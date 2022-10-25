#include <REGX52.H>
#include <INTRINS.H>


#define DRAW(A,B) _74HC595_WriteByte(A);P0=B;delay_10us(100);
#define B(A,G) while(A){G};


sbit RCK=P3^5;		//RCLK
sbit SCK=P3^6;		//SRCLK
sbit SER=P3^4;		//SER
typedef unsigned char u8;
typedef unsigned int u16;

void time0_init(void) {
    TMOD |=   0X01;//选择为定时器 0 模式，工作方式 1
    TH0 = 0XFC; //给定时器赋初值，定时 1ms
    TL0 = 0X18;
    ET0 = 1;//打开定时器 0 中断允许
    EA = 1;//打开总中断
    TR0 = 1;//打开定时器
}
/********************************************************************
***********
* 函 数 名 : delay_10us
* 函数功能 : 延时函数，ten_us=1 时，大约延时 10us
* 输 入 : ten_us
* 输 出 : 无
*********************************************************************
**********/
void delay_10us(u16 ten_us)
{
    while(ten_us--);
}
/********************************************************************
***********
* 函 数 名 : hc595_write_data(u8 dat)
* 函数功能 : 向 74HC595 写入一个字节的数据
* 输 入 : dat：数据
* 输 出 : 无
*********************************************************************
**********/
void _74HC595_WriteByte(unsigned char Byte)
{
    unsigned char i;
    for(i=0;i<8;i++)
    {
        SER=Byte&(0x80>>i);
        SCK=1;
        SCK=0;
    }
    RCK=1;
    RCK=0;
}
u8 next =0;
void main() {
    time0_init();

        B(1, u8 i1 = 0;
          switch (next) {
            case 0:
                _74HC595_WriteByte(0x81);P0=0x00;
                delay_10us(1000);
                _74HC595_WriteByte(0xFF);P0=0xEF;
                delay_10us(1000);
                break;
            case 1:
                _74HC595_WriteByte(0xFF);P0=0x7F;
                delay_10us(1000);
                DRAW(0x01,0x00)
                break;
            case 2:
                DRAW(0x7e,0x7e)
                DRAW(0x81,0x81)
                break;
            case 3:
                for (; i1 < 4; ++i1) {
                    DRAW(_cror_(0x40,i1), _cror_(0x7f,i1))
                }
                for (i1=0 ;  i1<4 ; i1++) {
                      DRAW(_crol_(0x08,i1), _cror_(0xef,i1))
                  }
                break;
                case 4:
                    DRAW(0x91,0x00)
                    DRAW(0xff,0x7f)
                    break;
              case 5:
                  DRAW(0xff,0x7E)
                  DRAW(0x01,0x00)
                  break;
        }
                P0=0xff;
        )//while 1
       // delay_10us(1);



}
void time0() interrupt 1 //定时器 0 中断函数
{
static unsigned int i;//定义静态变量 i
static u8 now=0;
TH0=0XFC; //给定时器赋初值，定时 1ms
TL0=0X18;
i++;
if(i==700)
{
next ++;
next%=6;
i = 0;
}
}
