/*
Lab. de Física Computacional II

	Pelo método de Euler:

	x1=x0+f(x)dt;

*/
#include<stdio.h>
#include<math.h>

double f(long double x){
	return x;
}

double f1(long double x)
{
	return exp(x);
}

main()
{
	double x=1,dt=1e-4,t, g;

	for(t=0;t<(10+dt);t+=dt)
	{
		x+=f(x)*dt;
		g=f1(t);
		printf("%e\t%e\t%e\t%e\n",t,x, g, fabs(g-x));
	}
}

	
/*
	Pelo método de Euler Centrado:

	x=x0+2*f(x)*dt;

*/
/*
double f(double x){
	return x;
}
main()
{
	double x[3],dt=1e-3,i;
	
	x[0]=1;
	x[1]=x[0]+f(x[0])*dt;
	for(i=0;i<10;i+=dt)
	{
		x[2]+=2*f(x[1])*dt;
		printf("%f %f\n",i,x[2]);
	}
}
*/

