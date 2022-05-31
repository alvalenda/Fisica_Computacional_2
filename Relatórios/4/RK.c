/*
dx/dt = f(t, x, y)
dy/dt = g(t, x, y)

k1x = f(t[i], x[i], y[i])
k1y = g(t[i], x[i], y[i])

k2x = f(t[i] + dt/2, x[i] + k1x*dt/2 , y[i] + k1y*dt/2)
k2y = g(t[i] + dt/2, x[i] + k1x*dt/2 , y[i] + k1y*dt/2)

k3x = f(t[i] + dt/2, x[1] + k2x*dt/2 , y[i] + k2y*dt/2)
k3y = g(t[i] + dt/2, x[1] + k2x*dt/2 , y[i] + k2y*dt/2)

k4x = f(t[i] + dt, x[1] + k3x*dt, y[i] + k3y*dt)
k4y = f(t[i] + dt, x[1] + k3x*dt, y[i] + k3y*dt)

x[i+1] = x[i] + dt/6 * (k1x + 2*k2x + 2*k3x + k4x)
y[i+1] = y[i] + dt/6 * (k1y + 2*k2y + 2*k3y + k4y)

______________________________________________________________________

v[t] = Vc + Vr
v[t] = Q/C + R*I

I = dq/dt      ->   (Q[i+1] - Q[i])/ dt

v0*sin(w*t) = Q/C + R*dq/dt

dq/dt = v0/R * sin(wt) - Q/R*C

Tensão no Capacitor -> Q/C
*/

#include<stdio.h>
#include<math.h>

#define v0 20.
#define dt 1e-7
#define PI 3.14159265359
#define R 100.
#define w 500000.
#define C 3e-5

double f(double Q,double t)
{
	return ((v0/R)*sin(w*t*PI/180.) - Q/(R*C));
}

double Rdqdt(double Q[])
{
	return (R*(Q[1]-Q[0])/dt);
}


main()
{
	double Q[2], K[4], t, T , TR, TF, TC;

	Q[0] = 0;
	T = 500*PI/w; 	
	
	for(t=0; t<T; t+=dt)
	{
		K[0] = f(Q[0], t);
		K[1] = f(Q[0] + K[0]*dt*0.5, t+dt*0.5);
		K[2] = f(Q[0] + K[1]*dt*0.5, t+dt*0.5);
		K[3] = f(Q[0] + K[2]*dt, t+dt);

		Q[1] = Q[0] + dt/6*(K[0] + K[1]*2 + K[2]*2 + K[3]);
		
		TF = v0*sin(w*t*PI/180.);
		TC = Q[1]/C;
		TR = Rdqdt(Q);

		printf("%f\t%f\t%f\t%f\t%f\n",t, Q[1], TF, TC, TR);
		Q[0]=Q[1];
	}  
}












