/*
d²y/dt² = -g/m      
d²x/dt² = 0 

dy/dt = vy
dvy/dt = -g/m

dx/dt = vx
*/
#include<stdio.h>
#include<math.h>

#define g 9.8
#define m 1.
#define dt 1e-4
#define PI 3.14159265359
#define HI 10.
#define VI 20.

double dvy(){
	return (-g/m);
}

double dy(double vy){
	return vy;
}

double dx(double vx){
	return vx;
}

main()
{
	double y[3],vy[3],x[3], vx[3], t=0, TETA=0, vi=VI, AX[2];
	AX[0]=0;

	for(TETA=1.0; TETA<90.0; TETA+=0.1)
	{	
		vy[0]=vi*sin((TETA*PI)/180.);
		vx[0]=vi*cos((TETA*PI)/180.);
		
		y[0]=HI;
		y[2]=y[0];//soh pra entrar no do
		y[1]=y[0]+dy(vy[0])*dt;
		vy[1]=vy[0]+2*dvy()*dt;
	
		x[0]=0;
		x[1]=x[0]+dx(vx[0])*dt;
		do{
			y[2]=y[0]+2*dy(vy[1])*dt;
			vy[2]=vy[1]+2*dvy()*dt;
			x[2]=x[0]+2*dx(vx[0])*dt;		
		
			//printf("%f\t%f\t%f\t%f\n",t,TETA,x[2]);
			//printf("%f\t%f\t%f\t%f\t%f\t\n",t, y[2], vy[2], x[2], vx[0]); 
			y[0]=y[1];
			y[1]=y[2];
			x[0]=x[1];
			x[1]=x[2];
			vy[0]=vy[1];
			vy[1]=vy[2];
			t+=dt;
			
			if(x[2]>AX[0])
			{
				AX[0]=x[2];
				AX[1]=TETA;
			}		

		}while(y[2]>0);
		printf("%f\t%f\t%f\n",t,TETA,x[2]);
	}
	//printf("Alcance máximo em %f graus, com %f metros percorridos.\n\n", AX[1], AX[0]);
}					
