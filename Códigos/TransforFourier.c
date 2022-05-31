#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define dt 1e-2
#define N 500
#define pi 3.14159265359
#define a 1
#define freq 20

double gR(double w, double t,double Fj){
	return cos(w*t)*Fj;
}

double gI(double w,double t,double Fj){
	return -sin(w*t)*Fj;
}

double F(double t){
	return a*cos(2*pi*freq*t);
}

main()
{
	double t[N],gr[N],gi[N],w[2],Fj[N],dw;
	int k,i,j;

	dw=(2*pi)/N;
	w[0]=-pi/dt;

	for(i=0;i<N;i++)
	{
		t[i]=i*dt;		
		Fj[i]=F(t[i]);
	}		
		
	for(k=0;k<N;k++)
	{	
		gr[k]=0;
		gi[k]=0;
		w[1]=w[0]+k*(dw/dt);
		
		for(j=0;j<N;j++)
		{
			gi[k]+=gI(w[1],t[j],Fj[j]);
			gr[k]+=gR(w[1],t[j],Fj[j]);
		}
	printf("%f\t%f\t%f\n",w[1]/(2*pi),dt*gr[k],dt*gi[k]);
	}
}
