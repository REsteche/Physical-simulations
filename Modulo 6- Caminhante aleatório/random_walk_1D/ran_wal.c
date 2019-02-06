#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<time.h>

int main(){
  int i,j,N=1000,M=1000;
  double p,t,r,x=0,xm, xd;
  FILE*random;
  random = fopen("caminhante.txt","w+");

  printf("GERADOR DE ARQUIVO CAMINHANTE ALEATÓRIO\n\n");
  printf("escolha uma probabilidade de passo:\n");
  scanf("%lf", &p);
  printf("escolha um tamanho para os passos:\n");
  scanf("%lf", &t);
  srand(time(NULL));

  //lembrar: M caminhantes realizando N passos!

  for(j=0;j<M;j++){
      x=0;
      xm=0;
      xd=0;
      for (i=0;i<N;i++){
	       r = rand()/((double)RAND_MAX);
	       //fprintf(random,"%lf %d\n", x, j);
           if(p<r){
              x=x+t;
           }
           else{
              x=x-t;
          }
       }
       fprintf(random,"%d %lf\n", j, x);
       xm = (xm + x);
       xd = (xd + x*x);

  }

 xm = xm/M;
 xd = xd/M;

 printf("\n%lf\n",xm);
 printf("%lf\n",xd);
 fclose(random);
 printf("seu arquivo foi criado com sucesso! :)\n");
return (0);
}
