/* verlet - resolver a EDO de segunda ordem

0=a*cos(wt)
d²0/dt = -g*sin0
w= (0[i] - 0[i-1])/ dt

x[i+1] = 2*x[i] - x[i-1] + f(x,x,t).dt²
*/
#include<stdio.h>
#include<math.h>

//#define g 9.8
#define T0 45.
#define dt 1e-2
#define PI 3.14159265359
//#define l 1.
#define w0 0.
#define m 1.

double l=1., g=9.8;

double f(double teta)
{
	return (-g*sin(teta)/l);
}

double w(double teta[])
{
	return ((teta[2]-teta[1])/dt);
}

main()
{
	double teta[3], t, Om, OM,E, U, K, T, F, marca[2];
	int contador=0;
	teta[0]=T0*PI/180.;
	teta[1]= w0*dt + teta[0];

	
	for(l=0.5; l<50; l+=0.5)
	{	
		for(t=0; t<1000; t+=dt)
		{
			teta[2] = 2*teta[1] - teta[0] + f(teta[1])*dt*dt;
			Om = w(teta);
			K=0.5*m*Om*l*Om*l;
			U=m*g*l*(1-cos(teta[2]));
			E=U+K;
			if(teta[2]<teta[1]&&teta[1]>teta[0]&&contador<2)
			{
					if(contador==0)
					{
						marca[0]=t;
						contador++;
					}
					else if(contador==1)
					{
						marca[1]=t;
						contador++;
					}
				
			}
	  	
			teta[0]=teta[1];
			teta[1]=teta[2]; 	
		}
			contador=0;	
			T=marca[1]-marca[0];
			F=1./T;
			printf("%f\t%f\t%f\t%f\n",l, g, T, F);
	}
}
