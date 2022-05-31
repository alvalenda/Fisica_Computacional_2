#include<stdio.h>
#include<math.h>

#define M 1e-30
#define A 10000 // unidade de comprimento
#define h 6.582e-16
#define K 0.03
#define pi 3.14159265


double u(double x) // u -> unidade de medida (adimensional)
{
	return x/A;
}
	
double p(double x)
{
	return 256*x*x; // potencial harmonico
}

int main()
{
		double psi, psi0, psi1, dx=1e-4, x;
		double dx2=dx*dx;
		double Ep = 111.978; 	// energia total
		double aux = 0;
        	
		//for(Ep=111.9;Ep<=112; Ep+=0.001)
		//{

		// condições iniciais
        	psi0=0;
        	psi=0.1;
		
		for(x=-1.0; x<1.0; x+=dx)
		{
			psi1 = (2 + dx2*(p(x) - Ep))*psi - psi0;
			aux += psi1;

			psi0=psi;
			psi=psi1;
		}

		for(x=-1.; x<1.; x+=dx)
		{
			psi1 = (2 + dx2*(p(x) - Ep))*psi - psi0;

			printf("%.12f %.12f\n", x, psi1*psi1/(aux*aux));

			psi0=psi;
			psi=psi1;
		}

		//printf("%.12f %.12f\n", Ep, psi1);
		//}
}




