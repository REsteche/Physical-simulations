#include <stdio.h>
int main () {

//Defini��o de vari�veis
FILE *V_midpoint;
FILE *Y_midpoint;
FILE *EM_midpoint;
int n, i;
double vn, vn1, yn, ynl, a, t=0, dt=0.01;

//Coleta de dados
printf("Digite a velocidade inicial:\n ");
scanf("%lf",&vn);

printf("Digite a altura inicial: \n");
scanf("%lf",&yn);

printf("Digite o n�mero de itera��es:\n ");
scanf("%d",&n);

//energia mec�nica
double m, EM;
      printf("Informe um valor para a massa do problema em quest�o");
      scanf("%lf", &m);


V_midpoint = fopen("Velocidade (Midpoint).txt","w+");
Y_midpoint = fopen("Posi��o (Midpoint).txt","w+");
EM_midpoint = fopen("energia mecanica (Midpoint).txt","w+");

for(i=0;i<n;i++){
fprintf(V_midpoint,"%lf\n", vn);
fprintf(Y_midpoint,"%lf\n", yn);
fprintf(EM_midpoint,"%lf\n", EM);
a = (1-vn);
vn1= vn + a*dt;
ynl= yn - 0.5*(vn+vn1)*dt;
t= t+dt;
EM= (0.5*m*(vn*vn))+m*9.8*yn;
vn = vn1;
yn = ynl;
}
fclose(V_midpoint);
fclose(Y_midpoint);
fclose(EM_midpoint);
printf("O arquivo Midpoint foi criado com sucesso.\n");




return(0);
}
