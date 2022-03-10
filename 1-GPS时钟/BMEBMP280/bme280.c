#include "bme280.h"
#include "iic.h"

#define BMP280_SlaveAddress   0xec  //定義bmp280在IIC的位址
#define   uchar unsigned char
#define   uint unsigned int	
                       
unsigned short dig_T1;
signed short dig_T2;
signed short dig_T3;
unsigned short dig_P1;
signed short dig_P2;
signed short dig_P3;
signed short dig_P4;
signed short dig_P5;
signed short dig_P6;
signed short dig_P7;
signed short dig_P8;
signed short dig_P9;
unsigned char dig_H1;
signed short dig_H2;
unsigned char dig_H3;
signed short dig_H4;
signed short dig_H5;
signed short dig_H6; 

long  temperature;
long  pressure;
long  height;
long  humidity;

uchar Single_Read(uchar ST_Address)
{ 
        uchar REG_data;
        //uchar bit;
        
        iic_start();         
        iic_send_byte(BMP280_SlaveAddress); //發送設備位址         
        iic_ack();
        iic_send_byte(ST_Address);  // 發送儲存位址          
        iic_ack(); 
        iic_start();                         
        iic_send_byte(BMP280_SlaveAddress+1);  //發送設備位址與讀信號       
        iic_ack(); 	  
        REG_data = iic_rev();     
        iic_ack(); //最後一筆需要回NOACK   
        return REG_data; 
}

void Single_Write(uchar SlaveAddress,uchar REG_Address,uchar REG_data)
{
    iic_start();                       
    iic_send_byte(SlaveAddress);  //發送設備位址與寫入信號 
        iic_ack(); 
        iic_send_byte(REG_Address); //內部暫存器位址   
        iic_ack(); 
        iic_send_byte(REG_data); // 內部暫存器寫入資料     
        iic_ack(); 
        iic_stop();                   
}


short Multiple_read(uchar ST_Address) //讀出BMP280內部資料,連續兩筆
{   
        uchar msb, lsb;
        short _data;
        
        lsb = Single_Read(ST_Address);
        msb = Single_Read(ST_Address+1);
        
        _data = msb << 8;
        _data |= lsb;        
     
        return _data;
}

long Multiple_read_H(uchar ST_Address) //讀出BMP280內部資料,連續兩筆
{   
        uchar msb, lsb;
        //short _data = 0;
        long _data = 0;

        msb = Single_Read(ST_Address);
        lsb = Single_Read(ST_Address+1);      
        
		_data=(long)(((uint32_t)msb<<8)|((uint32_t)lsb));
		//_data=((msb<<8)|lsb);
        return _data;
}

long Multiple_three_read(uchar ST_Address)
{   
        uchar msb, lsb,xlsb;
        long _data = 0;
        
        msb = Single_Read(ST_Address);
        lsb = Single_Read(ST_Address+1);
        xlsb = Single_Read(ST_Address+2);

        _data=(long)(((uint32_t)msb<<12)|((uint32_t)lsb<<4)|((uint32_t)xlsb>>4));
        return _data;
}



void Init_BMP280(void)
{
        unsigned short temp = 0;
        temp = Single_Read(0xd0);  //讀取id、判斷iic是否正常,模組是否正常，讀取出來的位址是0x58就是正確的

        dig_T1 = Multiple_read(0x88);
        dig_T2 = Multiple_read(0x8A);
        dig_T3 = Multiple_read(0x8C);
        dig_P1 = Multiple_read(0x8E);
        dig_P2 = Multiple_read(0x90);
        dig_P3 = Multiple_read(0x92);
        dig_P4 = Multiple_read(0x94);
        dig_P5 = Multiple_read(0x96);
        dig_P6 = Multiple_read(0x98);
        dig_P7 = Multiple_read(0x9A);
        dig_P8 = Multiple_read(0x9C);
        dig_P9 = Multiple_read(0x9E);
		dig_H1 = Single_Read(0xA1);
		dig_H2 = Multiple_read(0xE1);
		dig_H3 = Single_Read(0xE3);
	    dig_H4 = (Single_Read(0xE4)<< 4) | (Single_Read(0xE5) & 0x0F);
		dig_H5 = (Single_Read(0xE6)<< 4) | (Single_Read(0xE5) >> 4);
        dig_H6 = Single_Read(0xE7);
		
        Single_Write(BMP280_SlaveAddress,0xf2,0x04);
		Single_Write(BMP280_SlaveAddress,0xf4,0xb3);
        Single_Write(BMP280_SlaveAddress,0xf5,5<<2);
        Delay200ms();       
}


long bmp280Convert(void)
{
        long adc_T,adc_P,adc_H;
        long var1, var2,t_fine; 
         //rt_kprintf("----------------------------\n");
        adc_H= Multiple_read_H(0xFD);
        //adc_T = Multiple_three_read(0xFA); 
        adc_T = Multiple_three_read(0xFA);  //讀出溫度  
        //adc_P = Multiple_three_read(0xF7); 
        adc_P = Multiple_three_read(0xF7); 	 //讀出壓力

        if(adc_P == 0)
        {
                return 0;
        }
        //Temperature
        var1 = (((double)adc_T)/16384.0-((double)dig_T1)/1024.0)*((double)dig_T2) ;
        //rt_kprintf("var1 is %d\n",var1);
        var2 = ((((double)adc_T)/131072.0-((double)dig_T1)/8192.0)*(((double)adc_T)/131072.0-((double)dig_T1)/8192.0))*((double)dig_T3);
        //rt_kprintf("var2 is %d\n",var2);
        
        t_fine = (uint32_t)(var1+var2);
        //rt_kprintf("t_fine is %d\n",t_fine);
        
        temperature = t_fine*100/5120.0;  //5120.0	 5520.0是因為溫度值太高的調整
        
        //rt_kprintf("temperature is %d\n",T);
        
        var1 = ((double)t_fine/2.0)-64000.0;
        //rt_kprintf("var1 is %d\n",var1);
        
        var2 = var1*var1*((double)dig_P6)/32768.0;
        //rt_kprintf("var2 is %d\n",var2);
        
        var2 = var2+var1*((double)dig_P5)*2.0;
        //rt_kprintf("var2 is %d\n",var2);
        
        var2 = (var2/4.0)+(((double)dig_P4)*65536.0);
        //rt_kprintf("var2 is %d\n",var2);
        
        var1 = (((double)dig_P3)*var1*var1/524288.0+((double)dig_P2)*var1)/524288.0;
        //rt_kprintf("var1 is %d\n",var1);
        
        var1 = (1.0+var1/32768.0)*((double)dig_P1);
        //rt_kprintf("var1 is %d\n",var1);
        
        pressure = 1048576.0-(double)adc_P;
        //rt_kprintf("p is %d\n",p);

        pressure = (pressure-(var2/4096.0))*6250.0/var1;
        //rt_kprintf("p is %d\n",p);
		//height = (44330-4961*pow(pressure, 0.19))*100;
		//height = (44330 * (1-pow((pressure/ 101325.0),(1.0/5.255))))*100;  //101325標準海平面壓力，不是本地基本壓力
		height=(101325-pressure)*9;//轉化得到絕對高度
		//height=(101325-pressure) * 8.43  ;

		humidity  = (((double)t_fine)-76800.0);
		humidity  = (adc_H-(((double)dig_H4)*64.0+((double)dig_H5)/16384.0*humidity))*
			   (((double)dig_H2)/65536.0*(1.0+((double)dig_H6)/67108864.0*humidity*
			   (1.0+((double)dig_H3)/67108864.0*humidity)));
	    humidity  = humidity*(1.0-((double)dig_H1)*humidity/524288.0);
	    
	return 0;
 }	 
 
