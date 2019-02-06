#include <stdio.h>
int main () {

//Definição de variáveis
FILE *V_euler;
FILE *Y_euler;
FILE *EM_euler;
int n, i;
double vn, yn, a=0, t=0, dt=0.01;

//Coleta de dados
printf("Digite a velocidade inicial:\n ");
scanf("%lf",&vn);

printf("Digite a altura inicial: \n");
scanf("%lf",&yn);

printf("Digite o número de iterações:\n ");
scanf("%d",&n);

//energia mecânica
double m, EM;
      printf("Informe um valor para a massa do problema em questão:\n");
      scanf("%lf", &m);


V_euler = fopen("Velocidade (euler).txt","w+");
Y_euler = fopen("Posição (euler).txt","w+");
EM_euler = fopen("energia mecanica (euler).txt","w+");

for(i=0;i<n;i++){
fprintf(V_euler,"%lf\n", vn);
fprintf(Y_euler,"%lf\n", yn);
fprintf(EM_euler,"%lf\n", EM);
a = (1-vn);
vn= vn + a*dt;
yn= yn - vn*dt;
EM= (0.5*m*(vn*vn))+m*9.8*yn;
t= t+dt;
}
fclose(V_euler);
fclose(Y_euler);
fclose(EM_euler);
printf("O arquivo euler foi criado com sucesso.");

return(0);
}
