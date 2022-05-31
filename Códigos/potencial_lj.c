#include <math.h>
#include <stdio.h>
#define sigma 1.
#define beta 1.
#define m 1.
#define dt 1e-2
double dist(double x1, double x2, double y1, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
double F(double R){
    return beta*(12.*pow(sigma/R,13)-6.*pow(sigma/R,7));
}
int main(){
    int i, j , k;
    double t, tmax=50.;
    double RA[2], RB[2], VA[2], VB[2], AA[2],AB[2],R;
    RA[0]=0.7;
    RA[1]=0.;
    RB[0]=-RA[0];
    RB[1]=0.;
    VA[0]=VB[0]=0;
    VA[1]=0.5425;
    VB[1]=-VA[1];
    
    for(t=0.;t<tmax;t+=dt){
        R=dist(RA[0],RB[0],RA[1],RB[1]);
        for(i=0;i<2;i++){
            AA[i]=F(R)*(RA[i]-RB[i])/R;
            AB[i]=F(R)*(RB[i]-RA[i])/R;
            VA[i]+=AA[i]*dt;
            VB[i]+=AB[i]*dt;
            RA[i]+=VA[i]*dt;
            RB[i]+=VB[i]*dt;
        }
        printf("%lf\t%lf\t%lf\t%lf\n", RA[0], RA[1], RB[0], RB[1]);
    }
    return 0;
}
