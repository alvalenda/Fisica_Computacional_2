#include<stdio.h>
#include<math.h>

#define R 1000
#define C 1e-6
#define V0 5
#define dt 1e-3

double V( double t)
{
	double w=1000;
	
	return V0*cos(w*t);
}

double I(double Q, double t){

	return (V(t)/R)-(Q/(R*C));
}

main()
{
	double t,VC,VR,Q[2],k[4];
	
	Q[0]=0;


	for(t=0;t<10;t+=dt)
	{
		k[0]=I(Q[0],t);
		k[1]=I(Q[0]+dt*0.5*k[0],t+dt*0.5);
		k[2]=I(Q[0]+dt*0.5*k[1],t+dt*0.5);
		k[3]=I(Q[0]+dt*k[2],t+dt);

		Q[1]=Q[0]+dt*(k[0]+2*k[1]+2*k[2]+k[3])/6;

		VC=Q[1]/C;		
		VR=R*(k[0]+2*k[1]+2*k[2]+k[3])/6;

		printf("%f %f %f %f\n",t,V(t),VC,VR);
		Q[0]=Q[1];
	
	}
}

