#ifndef __CONFIG_H
#define __CONFIG_H

// Need the Arduino library for pin conversion
#include "Arduino.h"


// --------------  Settings  --------------
// General parameters
#define CLOSED_LOOP
#define CLOSED_LOOP_CONFIG
#define BUTTON_REPEAT_INTERVAL 1000 // Millis
#define BOARD_VOLTAGE 3.3 // The voltage of the main processor
//#define TEST_FLASH

// Serial configuration settings
#define STRING_START_MARKER '<'
#define STRING_END_MARKER '>'
#define SERIAL_BAUD 115200

// The CAN ID of this board
// X:2, X2:3...
// Y:7, Y2:8... 
// Z:11 Z2:12...
// E:17, E1:18...
#define DEFAULT_CAN_ID X

// Motor constants
#define STEP_ANGLE 1.8 // ! Check to see for .9 deg motors as well
#define MAX_CURRENT 3500 // Maximum current in mA
#define CURRENT_SENSE_RESISTOR 0.25 // Value of the board's current calculation resistor. An incorrect value here will cause current inaccuracies
#define MAX_MICROSTEP_DIVISOR 32 // The maximum microstepping divisor
#define STEP_UPDATE_FREQ 10 // in Hz, to step the motor back to the correct position
#define MAX_MOTOR_SPEED 50 // deg/s
#define STEP_FAULT_TIME 1 // The maximum allowable time (sec) for a step fault (meaning motor is out of position)
#define STEP_FAULT_ANGLE 45 // The maximum allowable deviation between the actual and set angles before StallFault is triggered


// --------------  Pins  --------------
/*
// * = F103C8-CB    | DIGITAL | ANALOG | USART      | TWI       | SPI        | SPECIAL   |
//                  |---------|--------|------------|-----------|------------|-----------|
#define PA0  A0  // | 0       | A0     |            |           |            |           |
#define PA1  A1  // | 1       | A1     |            |           |            |           |
#define PA2  A2  // | 2       | A2     | USART2_TX  |           |            |           |
#define PA3  A3  // | 2       | A2     | USART2_RX  |           |            |           |
#define PA4  A4  // | 4       | A4     |            |           | SPI1_SS    |           |
#define PA5  A5  // | 5       | A5     |            |           | SPI1_SCK   |           |
#define PA6  A6  // | 6       | A6     |            |           | SPI1_MISO  |           |
#define PA7  A7  // | 7       | A7     |            |           | SPI1_MOSI  |           |
#define PA8  8   // | 8       |        |            |           |            |           |
#define PA9  9   // | 9       |        | USART1_TX  |           |            |           |
#define PA10 10  // | 10      |        | USART1_RX  |           |            |           |
#define PA11 11  // | 11      |        |            |           |            | USB_DN    |
#define PA12 12  // | 12      |        |            |           |            | USB_DP    |
#define PA13 13  // | 13      |        |            |           |            | SWD_SWDIO |
#define PA14 14  // | 14      |        |            |           |            | SWD_SWCLK |
#define PA15 15  // | 15      |        |            |           | SPI1_SS    |           |
//                  |---------|--------|------------|-----------|------------|-----------|
#define PB0  A8  // | 16      | A8     |            |           |            |           |
#define PB1  A9  // | 17      | A9     |            |           |            |           |
#define PB2  18  // | 18      |        |            |           |            | BOOT1     |
#define PB3  19  // | 19      |        |            |           | SPI1_SCK   |           |
#define PB4  20  // | 20      |        |            |           | SPI1_MISO  |           |
#define PB5  21  // | 21      |        |            |           | SPI1_MOSI  |           |
#define PB6  22  // | 22      |        | USART1_TX  | TWI1_SCL  |            |           |
#define PB7  23  // | 23      |        | USART1_RX  | TWI1_SDA  |            |           |
#define PB8  24  // | 24      |        |            | TWI1_SCL  |            |           |
#define PB9  25  // | 25      |        |            | TWI1_SDA  |            |           |
#define PB10 26  // | 26      |        | USART3_TX* | TWI2_SCL* |            |           |
#define PB11 27  // | 27      |        | USART3_RX* | TWI2_SDA* |            |           |
#define PB12 28  // | 28      |        |            |           | SPI2_SS*   |           |
#define PB13 29  // | 29      |        |            |           | SPI2_SCK*  |           |
#define PB14 30  // | 30      |        |            |           | SPI2_MISO* |           |
#define PB15 31  // | 31      |        |            |           | SPI2_MOSI* |           |
//                  |---------|--------|------------|-----------|------------|-----------|
#define PC13 32  // | 32      |        |            |           |            |           |
#define PC14 33  // | 33      |        |            |           |            | OSC32_IN  |
#define PC15 34  // | 34      |        |            |           |            | OSC32_OUT |
//                  |---------|--------|------------|-----------|------------|-----------|
#define PD0  35  // | 35      |        |            |           |            | OSC_IN    |
#define PD1  36  // | 36      |        |            |           |            | OSC_OUT   |
//                  |---------|--------|------------|-----------|------------|-----------|
*/


// OLED Mappings
#define OLED_CS_PIN   PBout(12)	//
#define OLED_RST_PIN  PAout(8) 	//
#define OLED_RS_PIN   PBout(13)	//
#define OLED_SCLK_PIN PBout(15)	//(D0)
#define OLED_SDIN_PIN PBout(14)	//(D1)

// Button mappings
#define DOWN_BUTTON_PIN         PA_3
#define BACK_BUTTON_PIN         PB_0
#define SELECT_BUTTON_PIN       PB_1

// Dip switch mappings
// PIN     |    Normal             |  Reversed
// DIP_1   |    Microstep 1        |  Calibration mode
// DIP_2   |    Microstep 2        |  Closed/Open loop
// DIP_3   |    Closed/Open loop   |  Microstep 2
// DIP_4   |    Calibration mode   |  Microstep 1
#define DIP_1_PIN  PB_10
#define DIP_2_PIN  PB_11
#define DIP_3_PIN  PB_3
#define DIP_4_PIN  PA_15

// LED pin
#define LED_PIN PC_13

// Motor mappings
#define COIL_A_DIR_1_PIN        PB_6
#define COIL_A_DIR_2_PIN        PB_7
#define COIL_B_DIR_1_PIN        PB_8
#define COIL_B_DIR_2_PIN        PB_9
#define COIL_A_POWER_OUTPUT_PIN PB_4
#define COIL_B_POWER_OUTPUT_PIN PB_5

// Encoder SPI interface
#define ENCODER_CS_PIN   PAout(4) // SPI1_SS
#define ENCODER_SCK_PIN  PA_5 // SPI1_SCK
#define ENCODER_MISO_PIN PA_6 // SPI1_MISO
#define ENCODER_MOSI_PIN PA_7 // SPI1_MOSI

// Stepping interface
#define STEP_PIN      PA_1 // ! according to the previous files, but this is the same as the dir pin
#define ENABLE_PIN    PA_2
#define DIRECTION_PIN PA_1

// CAN bus pins
#define CAN_IN_PIN  PA_11
#define CAN_OUT_PIN PA_12

// StallFault connection (to mainboard)
// Pulls high on a stepper misalignment after the set period
// ! Find an actual pin to set
#define STALLFAULT_PIN NC


// --------------  Internal defines  --------------
// Under the hood motor setup
#define SINE_STEPS ((int16_t)(1024L))
#define SINE_MAX ((int32_t)(32768L))

// Low level GPIO configuration (for quicker manipulations than digitalWrites)
// A large amount of low level commands for handling the useage of fast GPIO manipulation
#define GPIOA_ODR_Addr    (GPIOA_BASE+12) //0x4001080C
#define GPIOB_ODR_Addr    (GPIOB_BASE+12) //0x40010C0C
#define GPIOC_ODR_Addr    (GPIOC_BASE+12) //0x4001100C
#define GPIOD_ODR_Addr    (GPIOD_BASE+12) //0x4001140C
#define GPIOE_ODR_Addr    (GPIOE_BASE+12) //0x4001180C
#define GPIOF_ODR_Addr    (GPIOF_BASE+12) //0x40011A0C
#define GPIOG_ODR_Addr    (GPIOG_BASE+12) //0x40011E0C

#define GPIOA_IDR_Addr    (GPIOA_BASE+8) //0x40010808
#define GPIOB_IDR_Addr    (GPIOB_BASE+8) //0x40010C08
#define GPIOC_IDR_Addr    (GPIOC_BASE+8) //0x40011008
#define GPIOD_IDR_Addr    (GPIOD_BASE+8) //0x40011408
#define GPIOE_IDR_Addr    (GPIOE_BASE+8) //0x40011808
#define GPIOF_IDR_Addr    (GPIOF_BASE+8) //0x40011A08
#define GPIOG_IDR_Addr    (GPIOG_BASE+8) //0x40011E08


#define BITBAND(addr, bitnum) ((addr & 0xF0000000)+0x2000000+((addr &0xFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)  *((volatile unsigned long  *)(addr))
#define BIT_ADDR(addr, bitnum)   MEM_ADDR(BITBAND(addr, bitnum))


#define PAout(n)   BIT_ADDR(GPIOA_ODR_Addr,n)
#define PAin(n)    BIT_ADDR(GPIOA_IDR_Addr,n)

#define PBout(n)   BIT_ADDR(GPIOB_ODR_Addr,n)
#define PBin(n)    BIT_ADDR(GPIOB_IDR_Addr,n)

#define PCout(n)   BIT_ADDR(GPIOC_ODR_Addr,n)
#define PCin(n)    BIT_ADDR(GPIOC_IDR_Addr,n)



#endif //__CONFIG_H