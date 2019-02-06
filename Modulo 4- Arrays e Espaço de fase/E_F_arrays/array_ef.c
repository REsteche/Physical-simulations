#include<stdlib.h>
#include<math.h>
#include<stdio.h>

int main(){

    //Definindo variáveis de movimento
    int n,i,p, r, g=10,j,q,k=10,c;
    double l=10,t, dt=0.001, gama=0.9, w;

	//Arrays
	double x[10], vx[10], w0[10], teta[10];

	//matriz de condições iniciais
    r=0;
	for(q=0;q<k;q++){
        for(c=0;c<k;c++){
            vx[r]= 1 + (2*q);
            x[r]=1 + (2*c);
            r= r+1;
            }
	}
    r=0;
	for(q=0;q<k;q++){
        for(c=0;c<r;c++){
            w0[r]= 1 + (2*q);
            teta[r]=1 + (2*c);
            r= r+1;
            }
	}


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
   //printf("Digite velocidade inicial:\n");
   //scanf("%lf",&w0);
   printf("Digite o angulo inicial:\n");
   scanf("%lf",&teta);

   //interações
   for(i=0;i<n;i++){


   for(r=0;r<10;r++){
      fprintf(Rx_pendulo,"%lf   %lf", w0[r], teta[r]);
      w0[r] = w0[r] -((g/l)*sin(teta[r]))*dt;
      teta[r] = teta[r] + w0[r]*dt;
      t= t+dt;
	  }
	  fprintf(Rx_pendulo,"\n");
   }

   //fechando o arquivo
   fclose(Rx_pendulo);


   }if(p==2){

   //arquivo
   FILE *Rx_oscilador;
   Rx_oscilador = fopen("posição (oscilador).txt","w+");

   //Variáveis do oscilador
   //printf("Digite velocidade inicial:\n");
   //scanf("%lf",&vx);
   printf("Digite a frequência angular inicial:\n");
   scanf("%lf",&w);



   //interações

   for(i=0;i<n;i++){


       for(r=0;r<10;r++){
           fprintf(Rx_oscilador,"%lf   %lf", vx[r], x[r]);
           vx[r] = vx[r] - (w*w*x[r])*dt; //-(vx*gama)*dt + (cos(1*t))*dt;  //força resistiva com gama e força motriz externa em cosseno
           x[r]=  x[r] + vx[r]*dt;
           t= t+dt;
		   }
		   fprintf(Rx_oscilador,"\n");
   }

   //fechando o arquivo
   fclose(Rx_oscilador);

   }


   printf("seu arquivo foi criado com sucesso");

   return 0;
   }


