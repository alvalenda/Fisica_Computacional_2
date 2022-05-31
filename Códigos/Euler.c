/*
Lab. de Física Computacional II

Livro : Cláudio Scherer - Métodos Computacionais de Física

#################################################################

Calcular numéricamente

	dx/dt=0,3x; com x0=1 ; x(t)=?;
*/

/*
	Pelo método de Euler:

	x1=x0+f(x)dt;

*/

#include<stdio.h>

double f(double x){
	return 0,3*x;
}
main()
{
	double x=1,dt=1e-3,i;

	for(i=0;i<10;i+=dt)
	{
		x+=f(x)*dt;
		printf("%f %f\n",i,x);
	}
}

	
/*
	Pelo método de Euler Centrado:

	x=x0+2*f(x)*dt;

*/
double f(double x){
	return 0,3*x;
}
main()
{
	double x[3],dt=1e-3,i;
	
	x[0]=1;
	x[1]=x[0]+f(x[0])*dt;
	for(i=0;i<10;i+=dt)
	{
		x[2]+=2*f(x[1])*dt;
		printf("%f %f\n",i,x[2]);
	}
}

