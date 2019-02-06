#include <stdio.h>
#include <math.h>
int main () {

//Defini��o de vari�veis
FILE *V_midpoint;
FILE *Y_midpoint;
FILE *Vf_midpoint;
int n, i;
double vn, vn1, yn, ynl, a, t=0, dt=0.01, vexata, vf;

//Coleta de dados
printf("Digite a velocidade inicial:\n ");
scanf("%lf",&vn);

printf("Digite a altura inicial: \n");
scanf("%lf",&yn);

printf("Digite o n�mero de itera��es:\n ");
scanf("%d",&n);


V_midpoint = fopen("Velocidade (Midpoint).txt","w+");
Y_midpoint = fopen("Posi��o (Midpoint).txt","w+");
Vf_midpoint = fopen("log do erro (Midpoint).txt","w+");

for(i=0;i<n;i++){
fprintf(V_midpoint,"%lf\n", vn);
fprintf(Y_midpoint,"%lf\n", yn);
fprintf(Vf_midpoint,"%lf\n", vf);
a = (1-vn);
vn1= vn + a*dt;
ynl= yn - 0.5*(vn+vn1)*dt;
t= t+dt;
vexata= -tanh(t);
vf= log(fabs(vn - vexata));
vn = vn1;
yn = ynl;
}
fclose(V_midpoint);
fclose(Y_midpoint);
fclose(Vf_midpoint);
printf("O arquivo Midpoint foi criado com sucesso.\n");




return(0);
}

