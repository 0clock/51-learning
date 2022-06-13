cmake_minimum_required(VERSION 3.22)
project(_)

set(CMAKE_CXX_STANDARD 14)

include_directories(Library/inc)
include_directories(USER)

add_executable(_
        Library/inc/4_4_key.h
        Library/inc/ADC.h
        Library/inc/as608.h
        Library/inc/AT24C02.h
        Library/inc/buzz.h
        Library/inc/delay.h
        Library/inc/Digital_tube.h
        Library/inc/ds1302.h
        Library/inc/DS18B20.h
        Library/inc/HX711.H
        Library/inc/int_it.h
        Library/inc/IO_expand.h
        Library/inc/key.h
        Library/inc/LCD1602.h
        Library/inc/parallel_12864.h
        Library/inc/PCF8591.h
        Library/inc/PWM.h
        Library/inc/stepper_motor.h
        Library/inc/time.h
        Library/inc/usart.h
        Library/src/4_4_key.c
        Library/src/ADC.c
        Library/src/as608.c
        Library/src/AT24C02.c
        Library/src/buzz.c
        Library/src/delay.c
        Library/src/Digital_tube.c
        Library/src/csbcj.c
        Library/src/ds1302.c
        Library/src/DS18B20.c
        Library/src/HX711.c
        Library/src/int_it.c
        Library/src/IO_expand.c
        Library/src/key.c
        Library/src/LCD1602.c
        Library/src/parallel_12864.c
        Library/src/PCF8591.c
        Library/src/PWM.c
        Library/src/stepper_motor.c
        Library/src/time.c
        Library/src/usart.c
        USER/main.c
        USER/main.h
        USER/STC12C5A60S2.H Library/src/mpu6050.c Library/inc/mpu6050.h Library/inc/DHT11.h Library/src/DHT11.c)
