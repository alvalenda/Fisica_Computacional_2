/* verlet - resolver a EDO de segunda ordem

0=a*cos(wt)
d²0/dt = -g*sin0
w= (0[i] - 0[i-1])/ dt

x[i+1] = 2*x[i] - x[i-1] + f(x,x,t).dt²
*/
#include<stdio.h>
#include<math.h>

#define g 9.8
#define T0 45.
#define dt 1e-4
#define PI 3.14159265359
#define l 1.
#define w0 0.
#define m 1.
double f(double teta)
{
	return -g*sin(teta)/l;
}

double w(double teta[])
{
	return ((teta[2]-teta[1])/dt);
}

main()
{
	double teta[3], t, Om, OM,E, U, K;
	teta[0]=T0*PI/180.;
	teta[1]= w0*dt + teta[0];

	for(t=0; t<100; t+=dt)
	{
		teta[2]=2*teta[1] - teta[0] + f(teta[1])*dt*dt;
		Om = w(teta);
		K=0.5*m*Om*l*Om*l;
		U=m*g*l*(1-cos(teta[2]));
		E=U+K;  
		teta[0]=teta[1];
		teta[1]=teta[2]; 	
		printf("%f\t%f\t%f\t%f\n",t, teta[2], Om, E);
	}
}
