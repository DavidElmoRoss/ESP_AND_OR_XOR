/*
    Title:  Program to input 2 values then AND OR XOR them and INVERT the firs tvalue
    Author: Your Name, Student ID, Course Code, Lab Section
    Date:   Today's date
    Description:    This program will continually prompt you separately for 
                    2 integer inputs. It will then AND OR and XOR these values 
                    plus invert of first number and show the output on the screen. 
*/
// INCLUDE SECTION
#include "arduino.h"

// FUNCTION PROTOTYPE SECTION
void clear(void);                                 // function to clear PC screen
void position(int x, int y);                      // function to position cursor (x,y);

// GLOBAL VARIABLE SECTION
volatile long num1,num2;                          // input values
volatile long ans1, ans2,ans3;                    // variables for AND, OR, XOR
String buff;                                      // buff gets string from keyboard
volatile int init_row = 1;                        // set initial row position to 1

void setup()
{
   Serial.begin(9600);                            // set BAUD RATE at 9600
   clear();                                       // clear the display
   position(init_row,1);                          // position cursor at (1,1) on screent
   printf("\t\t\e[1;31mAND OR XOR INVERT code");  // output title with bold red letters
   fflush(stdout);                                // flush stdout to screen
   printf("\e[0m");                               // clear all colour attributes
}

void loop()
{
  for(;;)                                         // endless loop
  {
     // Get user Input   
     position(init_row+2,1);                      // get num1 at (3,1)
     printf("Input first number  ? ");            // Prompt for first input vaue
     fflush(stdout);                              // fflush stdout to screen
     while (!Serial.available()) ;                // while no characters from keyboard - stay here
     buff = Serial.readString();                  // buff variable gets string read from keyboard
     num1 =strtol(buff.c_str(),NULL,16);          // num1 gets buff value as a base 16 (HEX) value     
     Serial.print(num1,HEX);                      // send num1 value in HEX to screen
     printf("\e[0K");                             // clear to end of screen of input line
     position(init_row+3,1);                      // get num2 at (4,1)
     printf("Input second number ? ");            // prompt for 2nd input value
     fflush(stdout);                              // fflush stdout to screen
     while (!Serial.available()) ;                // while no characters from keyboard - stay here
     buff = Serial.readString();                  // buff variable gets string read from keyboard
     num2 =strtol(buff.c_str(),NULL,16);          // num2 gets buff value as a base 16 (HEX) value
     Serial.print(num2,HEX);                      // send num2 value in HEX to screen
     printf("\e[0K");                             // clear to end of screen of input line

     // Do calculations
     ans1=num1 & num2;                            // ans1 calculated as num1 & num2
     ans2=num1 | num2;                            // ans2 calculated as num1 | num2
     ans3=num1 ^ num2;                            // ans3 calculated as num1 ^ num2

     // output results
     position(init_row+5,1);                      // cursor to position (6,1)
     printf("%X & %X = %X",num1,num2,ans1);       // output num1 ^ num2
     printf("\e[0K");                             // clear to end of screen of output line
     position(init_row+6,1);                      // cursor to position (7,1)
     printf("%X | %X = %X",num1,num2,ans2);       // output num1 | num2
     printf("\e[0K");                             // clear to end of screen of output line
     position(init_row+7,1);                      // cursor to position (8,1)
     printf("%X ^ %X = %X",num1,num2,ans3);       // output num ^ num2
     printf("\e[0K");                             // clear to end of screen of output line
     position(init_row+8,1);                      // position cursor at (9,1)
     printf("~%X =%X        ",num1,~num1);        // output num1 and inverse of num1
     printf("\e[0K");                             // clear to end of screen of output line
     fflush(stdout);                              // flush stdout to PC screen
  }
}

// Function Definitions
void clear(void)
{
    printf("\e[2J");                              // <ESC> [ 2 J to screen to clear it
    fflush(stdout);                               // fflush this to PC screen
}
void position(int x, int y)
{
    printf("\e[%d;%dH",x,y);                      // <ESC> [ x ; y H  to position cursor at (x,y)
    fflush(stdout);                               // fflush this to PC screen
}
 
 
 
 
 
 
 
