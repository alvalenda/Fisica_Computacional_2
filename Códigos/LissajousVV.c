#include<stdio.h>
#include<math.h>

#define Kx 100
#define Ky 400
#define m 1
#define dt 1e-2

double g(double x, double v, double t)
{
	return v;
}

double fx(double x, double v, double t)
{
	return -Kx*x/m;
}

double fy(double y, double v, double t)
{
	return -Ky*y/m;
}

/*
double verlet(double x1, double x2)
{
	return 2*x2 - x1 + 2*dt*dt*f(x2);
}
*/

main()
{
	double v[4],x[4],t;

	x[0]=0.5;
	x[2]=0.5;
	v[0]=0.;
	v[2]=0.;

	for(t=0;t<1000;t++)
	{
		x[1] = x[0] + v[0]*dt + 0.5*fx(x[0], v[0], t)*dt*dt;
		v[1] = v[0] + 0.5*(fx(x[1], v[0], t) + fx(x[0], v[0], t))*dt;
		
		x[3] = x[2] + v[2]*dt + 0.5*fy(x[2], v[2], t)*dt*dt;
		v[3] = v[2] + 0.5*(fy(x[3], v[2], t) + fy(x[2], v[2], t))*dt;
		
		printf("%f\t%f\t\n",x[1],x[3]);
		
		x[0]=x[1];
		x[2]=x[3];
		v[0]=v[1];
		v[2]=v[3];
	}
}
