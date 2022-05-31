#include <stdio.h>
#include <math.h>
#define dt 1e-2
#define N 1000
#define pi 3.1415926
#define freq 20.
#define dw 2*pi/N
#define a 1.

double fu(double t)
{
	return a*cos(2*pi*freq*t);
}
main()
{
	double f[N],t[N],gI[N],gR[N],w;
	int i,j,k;
	double wmin = -pi/dt;
	for (i=0;i<N;i++)
	{
		t[i] = i*dt;
		f[i] = fu(t[i]);
	}

	for(k=0;k<N;k++)
	{
		gI[k]=0;
		gR[k]=0;
		w=wmin+k*dw/dt;
		for(j=0;j<N;j++)
		{
			gI[k]-=sin(w*t[j])*f[j];
			gR[k]+=cos(w*t[j])*f[j];
		}
		printf("%.5f\t%.5f\t%.5f\n",w/(2*pi),dt*gR[k], dt*gI[k]);
	}
}

