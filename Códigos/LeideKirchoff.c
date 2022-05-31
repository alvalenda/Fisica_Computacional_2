/* 		Lei de Kirchoff 

	V(t)=VC+VR+VL

	V(t)= Q/C + Ri + L di/dt

#####	di/dt=V(t)/L - Q/CL - Ri/L = f(i,q,t)   ############


*/ 

/* 
		P/ V(t)=0;
		q(0)=Q;

	1) RC> 4L/R - Supercrítico (Oscilador Harmônico Amortecido)

	2) RC = 4L/R - Criticamente Amortecido
	
	3) RC < 4L/R - Subamortecido

	4) R=0 - Oscilador Harmônico

	Plotar Vc,Vr, Vl  x t
*/


#include<stdio.h>
#include<math.h>

#define Q 1
#define R 2
#define C 1
#define V0 1
#define dt 1e-2
#define L 1


double dq_dt(double t,double V, double I){   //I

	return -(R/L)*I-(1/(L*C))*V;
}

double di_dt(double t, double V,double I)
{
	return I;
}

main()
{
	double I[2],t,V[2],VC,VR,VL,kdi_dt[4],kdq_dt[4];
	
	I[0]=0;
	V[0]=V0;

	for(t=0;t<10;t+=dt)
	{
		kdi_dt[0]=dq_dt(t,V[0],I[0]);
		kdq_dt[0]=di_dt(t,V[0],I[0]);

		kdi_dt[1]=dq_dt(t+dt/2,V[0]+(dt/2)*kdq_dt[0],I[0]+(dt/2)*kdi_dt[0]);
		kdq_dt[1]=di_dt(t+dt/2,V[0]+(dt/2)*kdq_dt[0],I[0]+(dt/2)*kdi_dt[0]);

		kdi_dt[2]=dq_dt(t+dt/2,V[0]+(dt/2)*kdq_dt[1],I[0]+(dt/2)*kdi_dt[1]);
		kdq_dt[2]=di_dt(t+dt/2,V[0]+(dt/2)*kdq_dt[1],I[0]+(dt/2)*kdi_dt[1]);

		kdi_dt[3]=dq_dt(t+dt,V[0]+dt*kdq_dt[2],I[0]+dt*kdi_dt[2]);
		kdq_dt[3]=di_dt(t+dt,V[0]+dt*kdq_dt[2],I[0]+dt*kdi_dt[2]);
			
		V[1]=V[0]+dt*(kdq_dt[0]+2*kdq_dt[1]+2*kdq_dt[2]+kdq_dt[3])/6;
		I[1]=I[0]+dt*(kdi_dt[0]+2*kdi_dt[1]+2*kdi_dt[2]+kdi_dt[3])/6;		

		VC=Q/C;		
		VR=R*I[1];
		VL=L*V[1];		

		printf("%f %f %f %f\n",t,V[1],VL,VC,VR,I[1]);

		V[0]=V[1];
		I[0]=I[1];	
	}
}

