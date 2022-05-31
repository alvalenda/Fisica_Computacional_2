#include <stdio.h>
#include <math.h>

#define Q0 0
#define V0 5
#define R 1e03
#define C 1E-06
/*
#define omega 10e3
#define max_ticks 4*3.14/omega

#define dt 1e-03/omega
#define h dt/2
*/
double V(double t, double omega)
{
	return V0*cos(omega*t);
}

double Vr(double I)
{
	return R*I;
}

double Vc(double Q)
{
	return Q/C;
}

double dQ_dt(double Q, double t, double omega)
{
	return V(t, omega)/R - Q/R/C;
}

void main()
{
	double Q = Q0;
	double ticks;
	double k[4];
	double I;
	
	double omega;
	double max_ticks;

	double dt;
	double h;
	
	double V_t;
	double V_MAX;
	double V_MIN;
	
	double Vr_t;
	double Vr_MAX;
	double Vr_MIN;
	
	double Vc_t;
	double Vc_MAX;
	double Vc_MIN;

	for(omega = 1; omega < 10e4; omega += 1)
	{
		max_ticks = 4*3.14/omega;

		dt = 1e-03/omega;
		h = dt/2;
		
		V_MAX = 0;
		V_MIN = 0;
	
		Vr_MAX = 0;
		Vr_MIN = 0;
	
		Vc_MAX = 0;
		Vc_MIN = 0;

		for(ticks = 0; ticks < max_ticks; ticks += dt)
		{
			k[0] = dQ_dt(Q, ticks, omega);
			k[1] = dQ_dt(Q + h*k[0], ticks + h, omega + h);
			k[2] = dQ_dt(Q + h*k[1], ticks + h, omega + h);
			k[3] = dQ_dt(Q + dt*k[2], ticks + dt, omega + dt);

			I = (k[0] + 2*k[1] + 2*k[2] + k[3])/6;
			Q += I*dt;

			if(ticks > max_ticks/4)
			{
				V_t = V(ticks, omega);
				Vr_t = Vr(I);
				Vc_t = Vc(Q);
			
				if(V_t > V_MAX) V_MAX = V_t;
				if(V_t < V_MIN) V_MIN = V_t;
			
				if(Vr_t > Vr_MAX) Vr_MAX = Vr_t;
				if(Vr_t < Vr_MIN) Vr_MIN = Vr_t;
			
				if(Vc_t > Vc_MAX) Vc_MAX = Vc_t;
				if(Vc_t < Vc_MIN) Vc_MIN = Vc_t;
			}
		}
		
		printf("%lf %lf %lf %lf %lf %lf %lf\n", omega, V_MAX, V_MIN, Vr_MAX, Vr_MIN, Vc_MAX, Vc_MIN);
	}
}
