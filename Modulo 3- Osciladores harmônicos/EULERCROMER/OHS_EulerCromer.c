#include<stdlib.h>
#include<math.h>
#include<stdio.h>

int main(){
    //Definindo variáveis de movimento
    int n,i,p, g=10,j;
    double x, vx, w0, l=10,teta,t, dt=0.001, gama=0.9;


   //obtendo valores do usuário

   //quantidade de interações
   n=50000;


   //Seleção de qual programa executar

   printf("Selecione qual problema voce deseja resolver:\n01.Pendulo simples(1)\n02.Oscilador(2)\n");
   scanf("%d",&p);

   if(p==1){

   //arquivo
   FILE *Rx_pendulo;
   Rx_pendulo = fopen("posição (pendulo).txt","w+");

   //Variáveis do pêndulo
   printf("Digite velocidade inicial:\n");
   scanf("%lf",&w0);
   printf("Digite o angulo inicial:\n");
   scanf("%lf",&teta);

   //interações
   for(i=0;i<n;i++){
   fprintf(Rx_pendulo,"%lf %lf\n",w0, teta);

   w0 = w0 -((g/l)*sin(teta))*dt;
   teta = teta + w0*dt;
   t= t+dt;
   }

   //fechando o arquivo
   fclose(Rx_pendulo);


   }if(p==2){

   //arquivo
   FILE *Rx_oscilador;
   Rx_oscilador = fopen("posição (oscilador).txt","w+");

   //Variáveis do oscilador
   printf("Digite velocidade inicial:\n");
   scanf("%lf",&vx);
   printf("Digite a frequência angular inicial:\n");
   scanf("%lf",&w0);
   printf("Digite posição inicial:\n");
   scanf("%lf",&x);



   //interações

   for(i=0;i<n;i++){
   fprintf(Rx_oscilador,"%lf %lf\n", vx, x);
   vx = vx - (w0*w0*x)*dt -(vx*gama)*dt + (cos(1*t))*dt;  //força resistiva com gama e força motriz externa em cosseno
   x=  x + vx*dt;
   t= t+dt;
   }
   //fechando o arquivo
   fclose(Rx_oscilador);

   }


   printf("seu arquivo foi criado com sucesso");

   return 0;
   }
