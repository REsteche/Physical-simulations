#include <stdio.h>
int main () {

//Definição de variáveis
FILE *V_midpoint;
FILE *Y_midpoint;
int n, i;
double vn, vn1, yn, ynl, a, t=0, dt=0.01;

//Coleta de dados
printf("Digite a velocidade inicial:\n ");
scanf("%lf",&vn);

printf("Digite a altura inicial: \n");
scanf("%lf",&yn);

printf("Digite o número de iterações:\n ");
scanf("%d",&n);

V_midpoint = fopen("Velocidade (Midpoint).txt","w+");
Y_midpoint = fopen("Posição (Midpoint).txt","w+");

for(i=0;i<n;i++){
fprintf(V_midpoint,"%lf\n", vn);
fprintf(Y_midpoint,"%lf\n", yn);
a = (1-vn);
vn1= vn + a*dt;
ynl= yn - 0.5*(vn+vn1)*dt;
t= t+dt;
vn = vn1;
yn = ynl;
}
fclose(V_midpoint);
fclose(Y_midpoint);
printf("O arquivo Midpoint foi criado com sucesso.\n");

double m, EM;
      printf("Informe um valor para a massa do problema em questão");
      scanf("%lf", &m);

      EM= (0.5*m*(vn*vn))+m*9.8*yn;

      printf("a energia mecânica é igual a:%lf", EM);



return(0);
}
