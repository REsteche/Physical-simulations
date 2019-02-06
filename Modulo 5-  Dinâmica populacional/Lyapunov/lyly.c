#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {

int n, i, t;
double r, x, L, S, l;
FILE*Lyapunov;
Lyapunov = fopen("Lyapunov.txt","w+");
x=0.9;
//r=0.865;
n = 2000;
srand(time(NULL));
for(r=0.001;r<10;r=r+0.01){
    for(t=0;t<100;t++){
        x = rand()/((double)RAND_MAX);
        S=0;
        for(i=0;i<n;i++){
            x = r*sin(M_PI*x);
            l = M_PI*r*cos(M_PI*x);;
            if(i>1000){
            S = S + log(fabs(l));
            }
        }
        L = S/(1000);
        fprintf (Lyapunov, "%lf  %lf\n",L ,r);
    }
}

fclose(Lyapunov);
printf("Seu arquivo foi criado com sucesso");
return 0;

}
