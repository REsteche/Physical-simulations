#include<stdlib.h>
#include<math.h>
#include<stdio.h>

int main(){
    //Definindo vari�veis de movimento
    int n,i,p, g=10;
    double x, vx,v, w0,w, l=10,teta,t, dt=0.01;


   //obtendo valores do usu�rio

   //quantidade de intera��es
   n=100000;


   //Sele��o de qual programa executar

   printf("Selecione qual problema voce deseja resolver:\n01.Pendulo simples(1)\n02.Oscilador(2)\n");
   scanf("%d",&p);

   if(p==1){

   //arquivo
   FILE *Rx_pendulo;
   Rx_pendulo = fopen("posi��o (pendulo).txt","w+");

   //Vari�veis do p�ndulo
   printf("Digite velocidade inicial:\n");
   scanf("%lf",&w0);
   printf("Digite o angulo inicial:\n");
   scanf("%lf",&teta);

   //intera��es
   for(i=0;i<n;i++){
   fprintf(Rx_pendulo,"%lf  %lf\n", t, teta );

   w = w0 -((g/l)*sin(teta))*dt;
   teta = teta + w0*dt;
   w0=w;
   t= t+dt;
   }

   //fechando o arquivo
   fclose(Rx_pendulo);


   }if(p==2){

   //arquivo
   FILE *Rx_oscilador;
   Rx_oscilador = fopen("posi��o (oscilador).txt","w+");

   //Vari�veis do oscilador
   printf("Digite velocidade inicial:\n");
   scanf("%lf",&vx);
   printf("Digite a frequ�ncia angular inicial:\n");
   scanf("%lf",&w0);
   printf("Digite posi��o inicial:\n");
   scanf("%lf",&x);


   //intera��es

   for(i=0;i<n;i++){
   fprintf(Rx_oscilador,"%lf  %lf\n", t,x);
   v = vx - (w0*w0*x)*dt;
   x=  x + vx*dt;
   vx = v;
   t= t+dt;
   }
   //fechando o arquivo
   fclose(Rx_oscilador);

   }


   printf("seu arquivo foi criado com sucesso");

   return 0;
   }
