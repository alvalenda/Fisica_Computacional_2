/*
	Pelo método de Euler Centrado:

	x=x0+2*f(x)*dt;

*/
#include<stdio.h>
#include<math.h>

double f(double x){
	return 1.5*x;
}

double f1(double x){
	return exp(1.5*x);
}

main()
{
	double x[3],dt=1e-4,t, g;
	
	x[0]=1;
	x[1]=x[0]+f(x[0])*dt;
	for(t=0;t<(10+dt);t+=dt)
	{
		x[2]=x[0]+2*f(x[1])*dt;
		g=f1(t);
		printf("%f\t%f\t%f\t%f\n",t,x[2], g,fabs(g-x[2]));
		x[0]=x[1];
		x[1]=x[2];
	}
}
