CFLAGS := PRINT(".\build\Target 1\${c}.lst") OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\..\Keil_v5\C51\INC\Atmel;.\..\..\..\..\..\..\Keil_v5\C51\INC) DEFINE(__UVISION_VERSION='526')
CXXFLAGS := PRINT(".\build\Target 1\${cpp}.lst") OMF2 TABS(4) CODE NOCOND SYMBOLS OPTIMIZE(8,SPEED) SMALL ROM(LARGE) INCDIR(.\..\..\..\..\..\..\Keil_v5\C51\INC\Atmel;.\..\..\..\..\..\..\Keil_v5\C51\INC) DEFINE(__UVISION_VERSION='526')
ASMFLAGS := PRINT(.\build\Target 1\${asm}.lst) SET(SMALL) INCDIR(.\..\..\..\..\..\..\Keil_v5\C51\INC\Atmel;.\..\..\..\..\..\..\Keil_v5\C51\INC)
LDFLAGS :=  PRINT(".\build\Target 1\1-数码管计时器.map") REMOVEUNUSED
LDLIBS := 
