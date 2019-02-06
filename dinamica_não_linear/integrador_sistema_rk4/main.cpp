#include <stdio.h>
#include <math.h>

//adicione aqui as constantes a serem usadas como globais em suas funções
int sigma = 10.;
double b = 8./3.;
double r = 28;

double funcao1 (double xn,double yn,double zn){

return(sigma*(yn - xn)); /* local para colocar a derivada da funcao que se quer integrar em x */

}
double funcao2 (double xn,double yn,double zn){

return(r*xn - yn - xn*zn); /* local para colocar a derivada da funcao que se quer integrar em y */

}
double funcao3 (double xn,double yn,double zn){

return(xn*yn - b*zn); /* local para colocar a derivada da funcao que se quer integrar em z */

}
void RK4 (double y0,double x0, double z0, float dt ){
    double t=-100,K1y,K2y,K3y,K4y,yn=0,K1x,K2x,K3x,K4x,xn=0,K1z,K2z,K3z,K4z,zn=0;
FILE *fp;
fp = fopen("resultado_numérico.txt","w");
yn = y0;
xn = x0;
zn = z0;
    do{

K1x = funcao1(xn,yn,zn)*dt;

K2x = funcao1(xn + (K1x*dt*0.5), yn + 0.5*dt, zn + 0.5*dt)*dt;

K3x = funcao1(xn + (K2x*dt*0.5), yn + 0.5*dt, zn + 0.5*dt)*dt;

K4x = funcao1(xn + (K3x*dt), yn + dt, zn + dt)*dt;

xn = xn + (0.166667)*(K1x + 2*K2x + 2*K3x + K4x);


K1y = funcao2(xn,yn,zn)*dt;

K2y = funcao2(xn + dt*0.5,yn + (K1y*0.5*dt),zn + 0.5*dt)*dt;

K3y = funcao2(xn + dt*0.5,yn + (K2y*0.5*dt),zn + 0.5*dt)*dt;

K4y = funcao2(xn + dt, yn + (K3y*dt), zn + dt)*dt;

yn = yn + (0.166667)*(K1y+ 2*K2y + 2*K3y + K4y);


K1z = funcao3(xn,yn,zn)*dt;

K2z = funcao3(xn + dt*0.5, yn + 0.5*dt, zn + (K1z*0.5*dt))*dt;

K3z = funcao3(xn + dt*0.5, yn + 0.5*dt, zn + (K2z*0.5*dt))*dt;

K4z = funcao3(xn + dt, yn + dt, zn + K3z*dt)*dt;

zn = zn + (0.166667)*(K1z + 2*K2z + 2*K3z + K4z);

t = t + dt;

fprintf(fp," %lf  %lf  %lf  %lf\n",xn,yn,zn,t);

    }while (t<250);
fclose(fp);
}
int main(){

            float dt = 0.01;
            double x0 = 0,y0 = 1, z0= 0;
            /*colocar os pontos iniciais, coloque pontos bem pertos dos pontos fixos para a mágica acontecer*/

            RK4 (x0,y0,z0,dt);
            printf("dale! teu arquivo foi criado com sucesso ;)\n\n");

return 0;
}

