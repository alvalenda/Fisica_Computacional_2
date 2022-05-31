#include <math.h>
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define sigma 1.
#define beta 1.
#define m 1.
#define dt 1e-2
#define N 50

double dist(double x1, double x2, double y1, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
double F(double R){
    return beta*(12.*pow(sigma/R,13)-6.*pow(sigma/R,7));
}
int main(){
    int i, j , k;
    double t, ;
    double R[N][2*N],V[N][2*N], F[N][2*N],Rttl;

	srand(time(NULL));	

	for(i=0;i<N;i++)
		for(j=i+1;j<2*N;j++)
		{
			R[i][j]=(double) rand()/(double) RAND_MAX*4;
			F[i][j]=0;
			V[i][j]=F[i][j]*dt;
		}	

		
        R=dist(R[][],R[][0],R[][1],R[][1]);
        for(i=0;i<2;i++){
            AA[i]=F(R)*(RA[i]-RB[i])/R;
            AB[i]=F(R)*(RB[i]-RA[i])/R;
            VA[i]+=AA[i]*dt;
            VB[i]+=AB[i]*dt;
            RA[i]+=VA[i]*dt;
            RB[i]+=VB[i]*dt;
        }

        printf("%lf\t%lf\n",t,T);
    }
    return 0;
}
