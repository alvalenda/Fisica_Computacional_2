#include<stdio.h>
#include<math.h>

#define g 9.8
#define dt 1e-3
#define pi 3.14159265
#define m 1
#define l 1

double f(double theta){
	return (g*l*sin(theta))*(-1);
}
double h(double w){
	return w;
}

main()
{
	double E,i,w[2],theta[2];
	
	theta[0]=1;
	w[0]=0;

	for(i=0;i<10;i+=dt)
	{
		w[1]=w[0]+dt*f(theta[0]+0.5*dt*h(w[0]));
		theta[1]=theta[0]+dt*h(w[0]+0.5*dt*f(theta[0]));
		E=((m*l*l)/2)*w[1]*w[1]+m*g*l*(1-cos(theta[1]));
		printf("%f %f %f %f\n",i,w[1],theta[1],E);
		theta[0]=theta[1];
		w[0]=w[1];
	}
}
