#include<stdio.h>
#include<math.h>
#define sig 0.3
#define eps 0.2
#define dt 1e-2

double V(double r){
	return 4*eps*(pow(sig/r,12)-pow(sig/r,6));
}

double F(double r){
	double beta=(-1)*(4*eps)/sig;

	return beta*(12*pow(sig/r,13)-6*pow(sig/r,7));
}	

main()
{
	double x,r1[2],r2[2],i;

	r1[0]=1;
	r2[0]=-1;

	for(i=0;i<10000;i+=dt)
	{
		r1[1]=r1[0]+F(r1[0])*dt;
		r2[1]=r2[0]+F(r2[0])*dt;
	
		x=r1[1]-r2[1];
		printf("%f %f %f\n",i,r1[1],r2[1]);
		
		r1[0]=r1[1];
		r2[0]=r2[1];
	}
}

