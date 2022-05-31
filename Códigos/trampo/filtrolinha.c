#include<stdio.h>
#include<math.h>

#define R 1000
#define C 1e-6
#define V0 5
#define dt 1e-3

double V( double t, double w){

	return V0*cos(w*t);
}

double I(double Q, double t,double w){

	return (V(t,w)/R)-(Q/(R*C));
}

main()
{
	double t,VC,VR,Q[2],w,k[4],V_MAX,V_MIN,VR_MAX,VR_MIN,VC_MAX,VC_MIN,VC_t,V_t,VR_t;
	
	Q[0]=0;

	
	for(w=1;w<100;w++){

		V_MAX = 0;
		V_MIN = 0;
	
		VR_MAX = 0;
		VR_MIN = 0;
	
		VC_MAX = 0;
		VC_MIN = 0;

		for(t=0;t<4*3.14/w;t+=dt)
		{
			k[0]=I(Q[0],t,w);
			k[1]=I(Q[0]+dt*0.5*k[0],t+dt*0.5,w);
			k[2]=I(Q[0]+dt*0.5*k[1],t+dt*0.5,w);
			k[3]=I(Q[0]+dt*k[2],t+dt,w);
	
			Q[1]=Q[0]+dt*(k[0]+2*k[1]+2*k[2]+k[3])/6;
	
			VC=Q[1]/C;		
			VR=R*(k[0]+2*k[1]+2*k[2]+k[3])/6;
	
				V_t = V(t, w);
				VR_t = VR;
				VC_t = VC;
			
				if(V_t > V_MAX) 
					V_MAX = V_t;
				if(V_t < V_MIN) 
					V_MIN = V_t;
			
				if(VR_t > VR_MAX)
					 VR_MAX = VR_t;
				if(VR_t < VR_MIN) 
					VR_MIN = VR_t;
			
				if(VC_t > VC_MAX) 
					VC_MAX = VC_t;
				if(VC_t < VC_MIN)
					 VC_MIN = VC_t;
		}
	printf("%f\t%f\t%f\t%f\t%f\t%f\n",w,V_MAX,V_MIN,VC_MAX,VC_MIN,VR_MAX,VR_MIN);
			Q[0]=Q[1];
		
		}
}

