#include<stdlib.h>
#include<math.h>
#include<stdio.h>


int main(){

   //variaveis do problema
int n,i,r;
double x, dx, t, dt=0.000001;

   //arquivo para armazenar pontos de solução
FILE *solucao;
solucao = fopen("solucao.txt","w+");

   //interação com usuário
printf("ola! esse codigo ira resolver a EDO dx/dt=-x, com a condicao inicial baseada no seu cpf\n");
printf("para isso, nos informe o valor dos 4 primeiros digitos do seu cpf:\n");
scanf("%d",&r);
printf("quantas interacoes voce deseja realizar?\n");
scanf("%d",&n);

   x=r/1000;

   //interações
   for(i=0;i<n;i++){

   fprintf(solucao,"%lf  %lf\n", t,x);

   dx = x + (-x)*dt;
   x = dx;
   t = t+dt;
   }
fclose(solucao);
printf("seu arquivo foi criado com sucesso!\nos pontos de solucao estao dentro da pasta do projeto\nao lado esquerdo esta o tempo, e do direito o valor de x correspondente xD");
return 0;
}
