#include <stdio.h>
#include <math.h>
#define dt 1e-3
#define g 9.8
#define l 1.
#define m 1.
#define pi 3.14159

double f(double theta){
	return g*l*sin(theta)*(-1);
}

double h(double w){
	return w;
}

main()
{
	double v0=0,theta[2],t,w[2], Eo,E;

	w[0]=1;
	theta[0]=0;
	Eo=(m*l*l*w[0]*w[0]/2.)+(m*g*l)*(1-cos(theta[0]));

	for (t=0;t<10;t+=dt)
	{
		theta[1]=theta[0]+h(w[0])*dt+0.5*f(theta[0])*dt*dt;
		w[1]=w[0]+f(theta[0]+f(theta[1]))*0.5*dt;		
		E=(0.5*l*l*m*w[1]*w[1])+((m*g*l)*(1-cos(theta[1])));
		printf("%f\t%f\t%f\t%f\t%f\n",t,theta[1],w[1],E-Eo,(E-Eo)/Eo);
		theta[0]=theta[1];
		w[0]=w[1];
	}
}
