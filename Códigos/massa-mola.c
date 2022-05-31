/*

Sistemas massa-mola

	dx/dt= f(x,v,t)
		
		f(x,v,t)=v

	dv/dt=g(x,v,t)
		
		g(x,v,t)=-kx/m²


v_t+1=v_t+g(x,v,t).dt

x_t+1= x_t+f(x,v,t).dt

*/

#define dt 1e-3
#include<stdio.h>

double f(double x){
	double k=0.5,m=1;

	return (-k/m)*x;
}

main()
{
	double x[3],i,v=0;

	x[0]=5;
	x[1]=x[0]+v*dt*0.5*f(x[0])*dt*dt;
	
	for(i=0;i<100;i+=dt)
	{
		x[2]=2*x[1]-x[0]+2*f(x[1])*dt*dt;
		v=(x[2]-x[1])/dt;
		printf("%f %f\n",i,x[2]);
		x[0]=x[1];
		x[1]=x[2];
	}
}

/*
				Leap-Frog

d²x/dt²=f(x,t)

v=dx/dt

dv/dt=f(x,t)
*/

/*

				Velocity Verlet

x_j+1=x_j+v_j*dt+0,5f(x,t)dt²

v_j+1=v_j+0,5(f(x_j+1,t_j+1)+f(x,t))*dt

*/

/*
#################Resolver o sistema do	pêndulo###########################
	Resolver com os 3 métodos

	g=10
	l=1
	d²O/dt²=-glsenO
	T=? (período)
	T vs l
*/

