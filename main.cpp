#include "BigInt.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>




BigInt fastpow(BigInt num,BigInt dg,BigInt mod)
{
BigInt lg[20]={"0"}; //logs
BigInt nm[20]={"0"}; //result numbers to multiply

BigInt tw("2");
int j=0;

lg[0]=dg.lg();

BigInt l;
l=tw.pow(lg[0],(BigInt)"0"); //2^log

BigInt ot;
ot=dg%l; //rest from 2^log
j++;

while((BigInt)"3"<=ot)
{
l=ot.lg();
lg[j]=l;

l=tw.pow(l,(BigInt)"0");

ot=ot%l;
j++;
}

BigInt nn("1");

if(ot!=(BigInt)"0")
	nn=num.pow(ot,mod);

int tl=0;

bool br=1;

BigInt rs("1");

while(br)
{
num=(num*num)%mod;

	for(size_t f=0;f<j;f++)
	{
		lg[f]=lg[f]-"1";
		
		if(lg[f]=="0")
		{
			nm[tl]=num;
			tl++;
			
			if(f==0)
			{
			br=0;
			break;
			}

		}



	}

}


j=0;

while(nm[j]!="0") //multiply results between one another
{
rs=(rs*nm[j])%mod;
j++;

}

rs=(rs*nn)%mod; //mupltiply result on the rest 


return rs;

}





int main()
{
BigInt a("12");
BigInt b("5");
BigInt m("29");




//std::cout<<tr.gt_str()<<"\n";

return 0;
}
