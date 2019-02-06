#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<time.h>

int main(){



  int i,j,N=1000,M=10000;
  double p=1/6,t=1,r,x=0, y=0, xm, ym, xd, yd, R2, k;
  FILE*random;
  FILE*R;
  random = fopen("caminhante.txt","w+");
  R = fopen("R^2.txt","w+");

  printf("GERADOR DE ARQUIVO CAMINHANTE ALEATÓRIO\n\n");
  //printf("escolha uma probabilidade de passo:\n");
  //scanf("%lf", &p);
  //printf("escolha um tamanho para os passos:\n");
  //scanf("%lf", &t);
  srand(time(NULL));

  for(j=0;j<M;j++){
      x=0;
      y=0;
      xm=0;
      ym=0;
      xd=0;
      yd=0;
      for(i=0;i<N;i++){
          r = rand()%6;

          if (r==0){
            x=x+t;
          }
          if (r==1){
            x=x +t*cos(M_PI/2);
            y=y +t*sin(M_PI/2);
          }
          if (r==2){
           x=x -t*cos(M_PI/2);
           y=y -t*sin(M_PI/2);
          }
          if (r==3){
           x=x -t*cos(M_PI/2);
           y=y +t*sin(M_PI/2);
          }
          if (r==4){
            x=x-t;
          }
          if (r==5){
           x=x +t*cos(M_PI/2);
           y=y -t*sin(M_PI/2);
          }
        }

    fprintf(random,"%lf %lf %d\n", x, y, j );


 xm= (xm+x);
 ym= (ym+y);
 xd= (xd + x*x);
 yd= (yd + y*y);
 //R2 = xd - (xm*xm) + yd -(ym*ym);
 //fprintf(R,"%lf %d\n", R2, j);

  }

xm= xm/M;
ym= ym/M;
xd= xd/M;
yd= yd/M;
R2 = xd - (xm*xm) + yd -(ym*ym);

 printf("\n%lf\n",xm);
 printf("%lf\n",xd);
 printf("\n%lf\n",ym);
 printf("%lf\n",yd);
 printf("\n%lf\n",R2);
 fclose(R);
 fclose(random);
 printf("seus arquivos foram criados com sucesso! :)\n");
return (0);
}
