CFLAGS := PRINT(".\build\Target 1\${c}.lst") OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\null\INC\Atmel;.\0.96‘OLED-SPI;.\0.96‘OLED-SPI\BMP;.\USER;.\delay;.\按键;.\BMEBMP280;.\IIC;.\GPS;.\SPI;.\旋转编码器;.\1.54'TFT;.\..\..\..\..\..\Keil_v5\C51\INC) DEFINE(__UVISION_VERSION='526')
CXXFLAGS := PRINT(".\build\Target 1\${cpp}.lst") OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\null\INC\Atmel;.\0.96‘OLED-SPI;.\0.96‘OLED-SPI\BMP;.\USER;.\delay;.\按键;.\BMEBMP280;.\IIC;.\GPS;.\SPI;.\旋转编码器;.\1.54'TFT;.\..\..\..\..\..\Keil_v5\C51\INC) DEFINE(__UVISION_VERSION='526')
ASMFLAGS := PRINT(.\build\Target 1\${asm}.lst) SET(SMALL) INCDIR(.\null\INC\Atmel;.\0.96‘OLED-SPI;.\0.96‘OLED-SPI\BMP;.\USER;.\delay;.\按键;.\BMEBMP280;.\IIC;.\GPS;.\SPI;.\旋转编码器;.\1.54'TFT;.\..\..\..\..\..\Keil_v5\C51\INC)
LDFLAGS :=  PRINT(".\build\Target 1\1-工程案例.map") REMOVEUNUSED
LDLIBS := 
