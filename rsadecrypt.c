#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long gcd(long long a, long long b);
struct ee ExtendedEuc(long long a,long long b);
long long MultInv(long long a, long long n);
long long ModularExp(long long a, long long b, long long n); //a^b(modn)
int * BinaryRep(long long a);

struct ee{
	//long long d;
	long long lastx;
	long long lasty;
};



int main(){
	int t;
	scanf("%d",&t);
	long long int p,q,c;
	long long n;
	long long phi_n;
	long long e;
	long long M;
	long long d;
	while(t>0){

		t--;
		scanf("%lld%lld%lld",&p,&q,&c);
		n=p*q;
		phi_n=(p-1)*(q-1);
		e=2;
		while(e<phi_n){
			if(gcd(e,phi_n)==1)break;
			else e++ ;
		}
		d=MultInv(e,phi_n);
		M=ModularExp(c,d,n);
		printf("%lld\n",M);


	}
}


long long ModularExp(long long a, long long b, long long n){
	long long c=0;
	long long d=1;
	int * B=BinaryRep(b);
	int l=log2(b)+1;
	for(int i=l-1;i>=0;i--){
		c=2*c;
		d=(d*d)%n;
		if(B[i]==1){
			c++;
			d=(d*a)%n;
		}
	}
	return d;
}
int * BinaryRep(long long a){
	int l=log2(a)+1;

	int *arr=malloc(sizeof(int)*l);
	for(int i=0;i<l;i++){
		arr[i]=a%2;
		a=a/2;

	}
	//printf("\n");
	//for(int i=0;i<l;i++){printf(" %d",arr[i]);}
	return arr;
}
long long MultInv(long long a, long long n){
	struct ee temp=ExtendedEuc(a,n);
	long long mult=temp.lastx;
	mult=(mult+n)%n;
	return mult;
}
long long gcd(long long a, long long b){
	long long temp;
	while(1){
		temp=a%b;
		if(temp==0)return b;
		a=b;
		b=temp;
	}
}
struct ee ExtendedEuc(long long a,long long b){

	struct ee temp;
	long long x=0;
	long long y=1;
	temp.lastx=1;
	temp.lasty=0;
	long long t;
	while(b){

		long long q=a/b;
		long long copya=a;
		a=b;
		b=copya%b;
		long long copyx=x;
		long long copyy=y;
		x=temp.lastx-(q*x);
		temp.lastx=copyx;
		y=temp.lasty-(q*y);
		temp.lasty=copyy;
	}
	return temp;
}
