#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<time.h>

int main (void){

//coloque as variáveis aqui:
int i, j, D = 2, N=100, Nin = 0, V = 1;
double gam, d, Vnum, som, r, Val;
srand((unsigned)time(NULL));

//definindo a função gamma
if (D%2){
    gam = sqrt(M_PI);
    d=0.5;
}else{
    gam = 1.0;
    d = 1.0;
}
while (d<(float)D/2.0){
    gam = gam*d;
    d = d + 1.0;
}

//calculando o valor analitico
Val = 2.0*pow(M_PI,(double)D/2.0)/((double)D);
Val = Val /gam;
printf("valor analitico (funcao gama): %lf\n\n", Val);



//calculando valor numericamente
for(i=0;i<N;i++){
    som = 0;
    for(j=0;j<D;j++){
        r = 2*rand()/((double)RAND_MAX) - 1.0;
        som = som + r*r;
    }
    if(som<1.0){
        Nin = Nin + 1;
    }
}
for (i=0;i<D;i++){
        V = 2*V;
    }


Vnum = ((double)Nin)/((double)N) * V;
printf("valor monte carlo: %lf\n\n", Vnum);

return 0;
}
