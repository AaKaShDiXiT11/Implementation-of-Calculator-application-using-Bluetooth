#include"header.h"

void steps(int* p,int ele){
 int i;
	for(i=0;i<ele ;i++){
	 if(i%2==0){
		  uart0_itoa(p[i]);
	  }else{
		  uart0_tx(p[i]);
	  }
	 }
   uart0_tx_str("\r\n");
}




void iConv(char *a,int *d,int * ele){
  int i,j=0,sum=0;
  for(i=0;a[i];i++){
   if(a[i]>='0' && a[i] <='9')
   sum=sum*10+(a[i]-48);
   else{
   if( a[i]==')' || a[i]=='(' ){
	    d[j++]=a[i];
    }else{
	if(d[j-1]!=')')   
	   d[j++]=sum;
	   d[j++]=a[i];
	   }
	   sum=0;
	   }
	   }
	   d[j++]=sum;
	   *ele=j;
}

 int calculation(int *a,int ele){
 int i,j,res=0,n1,n2;

 int d[20],c=0,k=0;
 /////////////
   for(i=0;i<ele;i++){
	 if( a[i] == '('){
	    for(j=i+1;i<ele;j++){
		   ///////////////////////////
				 if( a[j] == '(')
				   c++; //for nested check
				 if(a[j]==')' && c==0)//nested check 
				  break;   //match with 1st out off loop
				 else if(a[j]==')')
				   c--;//still nested brackets present
		   ///////////////////////////
		       d[k++]=a[j];	//copy to another array
		}
		 res=calculation(d,k);
				a[i]=res;
				 ele-=k;
				 for(j=i+1;j<ele-k;j++)
				      a[j]=a[j+k+1];
				 
					  }
 }
 for(i=1;i<ele;i+=2){
     if(a[i]=='*' || a[i]=='/'){
	 n1=a[i-1];
	 n2=a[i+1];
	 
	 if(a[i] == '*')
	 res=n1 * n2;
	 else if (a[i]=='/')
	    res=n1/n2;
	 a[i-1]=res;
	 for(j=i;j<ele-2;j++)
	      a[j]=a[j+2];
	 ele-=2;
	 i-=2;
	 /////////////
	  steps(a,ele);
	 }
	 }
	 
	 /////////////////////////
	 for(i=1;i<ele;i+=2){
	 if(a[i] == '+' || a[i] == '-'){
	     n1=a[i-1];
	     n2=a[i+1];
		 if(a[i] == '+')
		 res=n1 + n2;
		 else if (a[i]=='-')
		    res=n1-n2;
		 a[i-1]=res;
		 for(j=i;j<ele-2;j++)
		      a[j]=a[j+2];
		 ele-=2;
		 i-=2;
		 /////////////////
		 steps(a,ele);
		 }
		}
		
	  return res;
	  }

