#include<stdio.h>
#include<math.h>

#define Kx 100
#define Ky 100
#define m 1
#define dt 1e-2

double g(double v)
{
	return v;
}

double fx(double x)
{
	return -Kx*x/m;
}

double fy(double y)
{
	return -Ky*y/m;
}

main()
{
	double vx[2],vy[2],x[2],y[2],t,kx[4],kvx[4],ky[4],kvy[4];

	x[0]=0.5;
	y[0]=0.;
	vx[0]=0.;
	vy[0]=0.9;

	for(t=0;t<1000;t++)
	{
		kvx[0]=fx(x[0]);
		kx[0]=g(vx[0]);

		kvx[1]=fx(x[0]+kx[0]*dt/2);
		kx[1]=g(vx[0]+kvx[0]*dt/2);

		kvx[2]=fx(x[0]+kx[1]*dt/2);
		kx[2]=g(vx[0]+kvx[1]*dt/2);

		kvx[3]=fx(x[0]+kx[2]*dt);
		kx[3]=g(vx[0]+kvx[2]*dt);    

		vx[1]=vx[0]+dt/6.*(kvx[0]+2.*kvx[1]+2.*kvx[2]+kvx[3]);
		x[1]=x[0]+dt/6.*(kx[0]+2.*kx[1]+2.*kx[2]+kx[3]);

/*----------------------------------------------------------------------------------*/
		
		kvy[0]=fy(y[0]);
		ky[0]=g(vy[0]);

		kvy[1]=fy(y[0]+ky[0]*dt/2);
		ky[1]=g(vy[0]+kvy[0]*dt/2);

		kvy[2]=fy(y[0]+ky[1]*dt/2);
		ky[2]=g(vy[0]+kvy[1]*dt/2);

		kvy[3]=fy(y[0]+ky[2]*dt);
		ky[3]=g(vy[0]+kvy[2]*dt);    

		vy[1]=vy[0]+dt/6.*(kvy[0]+2.*kvy[1]+2.*kvy[2]+kvy[3]);
		y[1]=y[0]+dt/6.*(ky[0]+2.*ky[1]+2.*ky[2]+ky[3]);

		printf("%f\t%f\t%f\t\n",t,x[1], y[1]);
    
		x[0]=x[1];
		vx[0]=vx[1];

		y[0]=y[1];
		vy[0]=vy[1];
	
	}
}
