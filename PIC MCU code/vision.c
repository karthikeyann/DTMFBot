volatile       unsigned char PORTA  	@ 0x05;
volatile       unsigned char PORTB  	@ 0x06;
volatile       unsigned char TRISA  	@ 0x85;
volatile       unsigned char TRISB  	@ 0x86;
#define STRAIGHT 3 	//b'00000011'
#define RIGHT 1		//b'00000001'
#define LEFT 2		//b'00000010'
#define STOP 0		//b'00000000' RL
#define SOUND 4		//b'00000100'
void delay(int i);
int got=0;
void main()
{
int dir=0;
TRISB = 48;		// mode 00110000=48
TRISA = 0x0F;		// mode 00001111
PORTA = 0;
PORTB = 0;
/* PORTB pins ''21 'ERL
RB0 LEFT
RB1 RIGHT
RB2 555_enable
RB4 }input
RB5 }command from MT8870

PORTA pins LRF'
RA1 front
RA2 right
RA3 left

//Motor control
only front rotation is implemented
so turn is radial turn.

.1.// testing results
RB5 = 1 left motor 10
RB4 = 1 right motor 01
both forward 11
00 stop
*/
while(1)
{

if((PORTB&48) == 0)
PORTB= STOP;		//stop -> 4 keypad

else if((PORTB&48) == 48)
PORTB= STRAIGHT;		//straight ->3


/*****************
to reduce speed include this
delay(2);
PORTB=STOP;
*******************/

else if ((PORTB&48) == 16) //01
PORTB= RIGHT;		//right -> 1

else if((PORTB&48) == 32)  //10
PORTB= LEFT;		//left ->2

else 
PORTB = 7;		//straight

}
//end
}
void delay(int i){
for(int n=0;n<i;n++);
}