#include"header.h"
#include<stdlib.h>


main(){
   char a[22];//strring
   int d[22]; //decimal value
   int ele,res;
uart0_init(9600);
	while(1){
		uart0_tx_str("Enter exp:-\r\n");
		uart0_rx_str( a,20);
		uart0_tx_str("\r\n");
	    iConv(a,d,&ele);
		res=calculation(d,ele);
	    uart0_tx_str("res = ");
		uart0_itoa(res);
		 uart0_tx_str("\r\n");
		}
}









