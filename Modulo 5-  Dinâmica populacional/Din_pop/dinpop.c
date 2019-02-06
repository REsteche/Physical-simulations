#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {

int n, i, t;
double r, x;
FILE*Mapa_Logisitico;
Mapa_Logisitico = fopen("Mapa_Logisitico.txt","w+");
//printf("Determine o valor da semente x0 e da constante r:\n ");
//scanf("%lf\n  %lf", &x, &r);
x=0.9;
//r=0.865;
n = 5000;
srand(time(NULL));
for(r=0;r<1;r=r+0.001){
    for(t=0;t<300;t++){
        x = rand()/((double)RAND_MAX);

        for(i=0;i<5000;i++){
            x = 4*r*x*(1-x);
        }
        fprintf (Mapa_Logisitico, "%lf  %lf\n",r, x);
    }
}


printf("Seu arquivo foi criado com sucesso");
return 0;

}
