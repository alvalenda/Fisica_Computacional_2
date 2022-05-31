#include<stdio.h>
#include<math.h>
 
#define M 1e-30
#define A 1e-2// unidade de comprimento
#define h 6.582e-16	//Constante de Planck
#define K 0.03
#define pi 3.14159265
#define dx 2e-2	//H
 
 
double u(double x) // u -> unidade de medida (adimensional)
{
    return x/A;
}
     
double P(double x)
{
    return 256*x*x; // potencial harmonico
}
 
int main()
{
        double Psi[3], x, Ep,aux;

        Ep = 112;//111.978;    // energia total
        aux = 0;
             
      //  for(Ep=111.9;Ep<=112; Ep+=0.001)
     //  {
 
        Psi[0]=0;
        Psi[1]=0.1;
         
        for(x=-1.0; x<1.0; x+=dx)
        {
            Psi[2] = (2 + dx*dx*(P(x) - Ep))*Psi[1] - Psi[0];
            aux += Psi[1];
 
            Psi[0]=Psi[1];
            Psi[1]=Psi[2];
		
        }
 
        for(x=-1.0; x<1.0; x+=dx)
        {
            Psi[2] = (2 + dx*dx*(P(x) - Ep))*Psi[1] - Psi[0];
 
            printf("%.12f %.12f\n", x, /*/Psi[2]);*/(Psi[2]*Psi[2])/(aux*aux));
 
            Psi[0]=Psi[1];
            Psi[1]=Psi[2];
        }
 
        //printf("%.12f %.12f\n", Ep, Psi[2]);
       // }
}

