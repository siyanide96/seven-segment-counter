/*SEVEN SEGMENT COUNTER WITH PUSH BUTTON BY SIYANIDE*/
#include <mega32.h>
#include <delay.h>

int buttonPushCounter;
int previousState = 0;
int i;
char sevenSegArray[] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66,
                        0x6D, 0x7D, 0x07, 0xFF, 0x6F };
void main(){
    DDRB=0xFF;
    DDRD=0x00;  
    while(1){
    
    //Counter
    if(PIND == 0xFF)       //WHEN BUTTON PRESSED
    {
        if(previousState==1)  //Make Sure that button hold
        {                     //does single operation only.
           //DO NOTHING
        }
        else
        {
        previousState = 1;
            if(buttonPushCounter < 9)
            {
                buttonPushCounter++;
            }
            else
            {
            buttonPushCounter = 0;
            }
        }
    }
    else
    {
    previousState = 0;
    }
    
    //Display
    for(i=0;i<10;i++)
        {
            PORTB = sevenSegArray[buttonPushCounter];
        }
}
}
