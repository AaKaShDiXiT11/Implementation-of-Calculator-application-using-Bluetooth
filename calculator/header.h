 //LIBRARY FUNCTIONS
#include<LPC21XX.H>
#include<string.h>

//datatype Shortcuts
typedef signed char s8;
typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef signed int s32;
typedef unsigned int u32;

//delay function
extern void delay_sec(u32);
extern void delay_ms(u32);

//4 bit driver
 extern void lcd_init(void);
 extern void lcd_cmd(u8);
 extern void lcd_data(u8);
 extern void lcd_cgram(void);
 extern void lcd_int(int);
 extern void lcd_cgram1(unsigned char *,unsigned char );


 //uart0 driver 
 extern void uart0_init(unsigned int);
 extern	void uart0_tx(unsigned char);
 extern	void uart0_tx_str(char * );
 extern	unsigned char uart0_rx(void);
 extern void uart0_rx_str(char *,int );
 extern void uart0_itoa(int);
 extern void uart0_float(float);

 //calci driver
  extern void iConv(char *,int*,int *);
  extern int calculation(int *,int );
  extern void steps(int*,int);
/*void atoif(char *a,int* d,int *s){
   int num,i;
 while(*a){
     if(*a>='0' && *a<='9'){
     num=atoi(a);//conversion to num
	 *d=num;
	 *s='@';
	  for(i=0;a[i]>='0' && a[i]<='9';i++);
		atoif(&a[i-1],d+1,s+1);
	 }	
 	 if((*a >= '!' )&&(*a <='/')){
		 *s= *a;
		 *d = '@';
	    
				atoif(&a[1],d+1,s+1);
	  }
	}
}
*/	   

