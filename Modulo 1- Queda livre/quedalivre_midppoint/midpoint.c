#include <stdio.h>
int main () {

//Definição de variáveis
FILE *V_midpoint;
FILE *Y_midpoint;
int n, i;
double vn, vn1, yn, ynl, a, t=0, dt=0.000001;

//Coleta de dados
printf("Digite a velocidade inicial:\n ");
scanf("%lf",&vn);

printf("Digite a altura inicial: \n");
scanf("%lf",&yn);

printf("Digite o número de iterações:\n ");
scanf("&d",&n);

V_midpoint = fopen("Velocidade (Midpoint).txt","w+");
Y_midpoint = fopen("Posição (Midpoint).txt","w+");

for(i=0;i<n;i++){
fprintf(V_midpoint,"%lf\n", vn);
fprintf(Y_midpoint,"%lf\n", yn);
a = (1-vn);
vn1= vn + a*dt;
ynl= yn + 1/2*(vn+vn1)*dt;
t= t+dt;
vn = vn1;
}
fclose(V_midpoint);
fclose(Y_midpoint);
printf("O arquivo Midpoint foi criado com sucesso.");

return(0);
}
