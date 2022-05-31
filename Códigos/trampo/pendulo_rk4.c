#include <stdio.h>
#include<math.h>
#define g 9.8
#define l 1.0
#define m 1.0
#define dt 1e-1

float f(float x) {
    return -1.*g*l*sin(x);
}
float h(float w) {
    return w;
}
int main() {

  float x[4],w[4],i,E,kw[4],kt[4];
  x[0]=1.0;
  w[0]=0.;
  float Eo=m*l*l*w[0]*w[0]/2.+m*g*l*(1.-cos(x[0]));

  for(i=0;i<100;i+=dt) {
    kw[0]=f(x[0]);
    kt[0]=h(w[0]);
	kw[1]=f(x[0]+kt[0]*dt/2);
	kt[1]=h(w[0]+kw[0]*dt/2);
	kw[2]=f(x[0]+kt[1]*dt/2);
	kt[2]=h(w[0]+kw[1]*dt/2);
	kw[3]=f(x[0]+kt[2]*dt);
	kt[3]=h(w[0]+kw[2]*dt);    

    w[1]=w[0]+dt/6.*(kw[0]+2.*kw[1]+2.*kw[2]+kw[3]);
    x[1]=x[0]+dt/6.*(kt[0]+2.*kt[1]+2.*kt[2]+kt[3]);

    E=m*l*l*w[1]*w[1]/2.+m*g*l*(1.-cos(x[1]));
    printf("%f\t%f\t%f\t%f\t%f\n",i,x[1], w[1],(E-Eo)/Eo, Eo);
    x[0]=x[1];
    w[0]=w[1];
  }
}






