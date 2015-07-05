#include <digitalWriteFast.h>

unsigned int code[128];
const int revPin              = 2;
const int pin[]               = {3,4,5,6,7,8,9,10,A0,A1,A2,A3,A4,A5};
unsigned long previous         = 0;
unsigned long current          = 0;
double timestep         = 0.;
double offset           = 0.;
unsigned long t                = 0;
unsigned int command          = 0;
char message[]                = "OOOOOOOOOOOOOOOO";


void setup()
{
  initializeletters();
  Serial.begin(115200);
  for(int i = 0; i<=15l; i++)
  {
    pinMode(pin[i], OUTPUT);
  }
  pinMode(revPin, INPUT);
  attachInterrupt(0, interrupt, RISING);
  current = micros();
}

void loop() 
{
  bitWrite(command, 0, bitRead(code[message[0]], (t)%16));
  bitWrite(command, 1, bitRead(code[message[1]], (t+1)%16));
  bitWrite(command, 2, bitRead(code[message[2]], (t+2)%16));
  bitWrite(command, 3, bitRead(code[message[3]], (t+3)%16));
  bitWrite(command, 4, bitRead(code[message[4]], (t+4)%16));
  bitWrite(command, 5, bitRead(code[message[5]], (t+5)%16));
  bitWrite(command, 6, bitRead(code[message[6]], (t+6)%16));
  bitWrite(command, 7, bitRead(code[message[7]], (t+7)%16));
  bitWrite(command, 8, bitRead(code[message[8]], (t+8)%16));
  bitWrite(command, 9, bitRead(code[message[9]], (t+9)%16));
  bitWrite(command, 10, bitRead(code[message[10]], (t+10)%16));
  bitWrite(command, 11, bitRead(code[message[11]], (t+11)%16));
  bitWrite(command, 12, bitRead(code[message[12]], (t+12)%16));
  bitWrite(command, 13, bitRead(code[message[13]], (t+13)%16));
  bitWrite(command, 14, bitRead(code[message[14]], (t+14)%16));
  bitWrite(command, 15, bitRead(code[message[15]], (t+15)%16));

  while(micros()<current+timestep*t+offset)
  {
  }
    
  digitalWriteFast(pin[0],bitRead(command,0));
  digitalWriteFast(pin[1],bitRead(command,1));
  digitalWriteFast(pin[2],bitRead(command,2));
  digitalWriteFast(pin[3],bitRead(command,3));
  digitalWriteFast(pin[4],bitRead(command,4));
  digitalWriteFast(pin[5],bitRead(command,5));
  digitalWriteFast(pin[6],bitRead(command,6));
  digitalWriteFast(pin[7],bitRead(command,7));
  digitalWriteFast(pin[8],bitRead(command,8));
  digitalWriteFast(pin[9],bitRead(command,9));
  digitalWriteFast(pin[10],bitRead(command,10));
  digitalWriteFast(pin[11],bitRead(command,11));
  digitalWriteFast(pin[12],bitRead(command,12));
  digitalWriteFast(pin[13],bitRead(command,13));
  digitalWriteFast(pin[14],bitRead(command,14));
  digitalWriteFast(pin[15],bitRead(command,15));

  digitalWriteFast(pin[0],0);
  digitalWriteFast(pin[1],0);
  digitalWriteFast(pin[2],0);
  digitalWriteFast(pin[3],0);
  digitalWriteFast(pin[4],0);
  digitalWriteFast(pin[5],0);
  digitalWriteFast(pin[6],0);
  digitalWriteFast(pin[7],0);
  digitalWriteFast(pin[8],0);
  digitalWriteFast(pin[9],0);
  digitalWriteFast(pin[10],0);
  digitalWriteFast(pin[11],0);
  digitalWriteFast(pin[12],0);
  digitalWriteFast(pin[13],0);
  digitalWriteFast(pin[14],0);
  digitalWriteFast(pin[15],0);
  t++;
}

void interrupt()
{
  previous = current;
  current = micros();
  timestep = (current-previous)/16.;
  offset   = timestep*.075;
  t=0;
}

void initializeletters()
{
  code[1]=0xFFFF;
  code['A']=0xE186;
  code['B']=0xE521;
  code['C']=0x8007;
  code['D']=0xE421;
  code['E']=0x8087;
  code['F']=0x8086;
  code['G']=0xA107;
  code['H']=0x6186;
  code['I']=0x8421;
  code['J']=0x6003;
  code['K']=0x0296;
  code['L']=0x0007;
  code['M']=0x6A06;
  code['N']=0x6816;
  code['O']=0xE247;
  code['P']=0xC186;
  code['Q']=0xE017;
  code['R']=0xC196;
  code['S']=0xA181;
  code['T']=0x8420;
  code['U']=0x6007;
  code['V']=0x0246;
  code['W']=0x6056;
  code['X']=0x0A50;
  code['Y']=0x41A4;
  code['Z']=0x8241;
  code['0']=0xE007;
  code['1']=0x6200;
  code['2']=0xC183;
  code['3']=0xE181;
  code['4']=0x6184;
  code['5']=0xA185;
  code['6']=0xA187;
  code['7']=0xE000;
  code['8']=0xE187;
  code['9']=0xE185;
  code[' ']=0x0000;
  code[':']=0x1008;
  code[';']=0x1040;
  code['/']=0x0240;
}


