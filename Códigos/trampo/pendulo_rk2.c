#include <stdio.h>
#include<math.h>
#define g 9.8
#define m 1.0
#define dt 1e-3
#define pi 3.14159265

double f(double x,double l){
    return -1.*g*l*sin(x);
}

double h(double w){
    return w;
}

int main() 
{
  double x[2],w[2],i,E,T,l;

  x[0]=1.0;
  w[0]=0.;	

  double Eo=m*l*l*w[0]*w[0]/2.+m*g*l*(1.-cos(x[0]));

  for(i=0;i<10;i+=dt) {
	for(l=0;l<10;l+=0.1){
    w[1]=w[0]+f(x[0]+0.5*dt*h(w[0]),l)*dt;
    x[1]=x[0]+h(w[0]+0.5*dt*f(x[0],l))*dt;
    E=m*l*l*w[1]*w[1]/2.+m*g*l*(1.-cos(x[1]));
    T=2*pi*sqrt(l/g);

    printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\n",i,T,l,x[1], w[1],(E-Eo)/Eo, Eo);

    x[0]=x[1];
    w[0]=w[1];
  }
}
}






