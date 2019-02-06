#include<stdlib.h>
#include<math.h>
#include<stdio.h>

int main(){
    //Definindo vari�veis de movimento
    int n,i,p, g=10,j;
    double x, vx, w0, l=10,teta,t, dt=0.001, gama=0.9;


   //obtendo valores do usu�rio

   //quantidade de intera��es
   n=50000;


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
   fprintf(Rx_oscilador,"%lf %lf\n", vx, x);
   vx = vx - (w0*w0*x)*dt -(vx*gama)*dt + (cos(1*t))*dt;  //for�a resistiva com gama e for�a motriz externa em cosseno
   x=  x + vx*dt;
   t= t+dt;
   }
   //fechando o arquivo
   fclose(Rx_oscilador);

   }


   printf("seu arquivo foi criado com sucesso");

   return 0;
   }
