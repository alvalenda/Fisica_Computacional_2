/* Subamortecido V(0)2m/gama = D e X(0) = C */


#include<stdio.h>
#include<math.h>
#define m 1.0
#define k 2.0
#define dt 1e-1
#define gama 0.5

double dx_dt(double v){
	return v;
}
double dv_dt(double x, double v){
	return (-1)*(k/m)*x-(gama/m)*v;
}

main()
{
	double t,kv[4],kx[4],v[2],x[2],h;

	h=dt*0.5;
	x[0]=0.05;
	v[0]=0;

	for(t=0;t<5;t+=dt)
	{

		kx[0]=dx_dt(v[0]);

		kv[0]=dv_dt(x[0],v[0]);

		kx[1]=dx_dt(v[0]+kv[0]*dt/2);

		kv[1]=dv_dt(x[0]+kx[0]*h,dx_dt(v[0]));

		kx[2]=dx_dt(v[0]+kv[1]*dt/2);

		kv[2]=dv_dt(x[0]+kx[1]*h,dx_dt(v[0]));

		kv[3]=dv_dt(x[0]+kx[2],dx_dt(v[0]));

		kx[3]=dx_dt(v[0]+kv[2]*dt);   


	v[1]=v[0]+dt/6.*(kv[0]+2.*kv[1]+2.*kv[2]+kv[3]);
   	x[1]=x[0]+dt/6.*(kx[0]+2.*kx[1]+2.*kx[2]+kx[3]);
		
		printf("%f\t%f\t%f\n",t,x[1],v[1]);

		x[0]=x[1];
		v[0]=v[1];
	}
}
