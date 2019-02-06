#include<stdlib.h>
#include<math.h>
#include<stdio.h>

//função que tira módulo vetorial
double modulo(double vx, double vy, double vz){
double m;
m = vx*vx + vy*vy + vz*vz;
m = sqrt(m);
return (m);
}


int main(){

//Definindo constantes de movimento da bola de beisebol
float Cd=0.0006, Cm=0.00004;
int g=10;

//Definindo variáveis de movimento
int n,i;
double rx,ry,rz, vx,vy,vz, wx,wy,wz ,dt=0.0001, v, t;

//criando e abrindo arquivos
FILE *Rx_magnus;
FILE *Ry_magnus;
FILE *Rz_magnus;
FILE *time_magnus;

Rx_magnus = fopen("eixo x (Magnus).txt","w+");
Ry_magnus = fopen("eixo y (Magnus).txt","w+");
Rz_magnus = fopen("eixo z (Magnus).txt","w+");
time_magnus = fopen("tempo (Magnus).txt","w+");

//obtendo valores do usuário
printf("Digite as componentes da velocidade inicial (x,y,z):\n");
scanf("%lf %lf %lf",&vx,&vy,&vz);

printf("Digite as componentes da velocidade angular (x,y,z):\n");
scanf("%lf %lf %lf",&wx,&wy,&wz);


printf("Digite o número de interações:\n ");
scanf("%d",&n);

t=0;
//interações numéricas
for(i=0;i<n;i++){

    //preenchendo arquivos
    fprintf(Rx_magnus,"%lf\n", rx);
    fprintf(Ry_magnus,"%lf\n", ry);
    fprintf(Rz_magnus,"%lf\n", rz);
    fprintf(time_magnus,"%lf\n", t);
    //tirando o módulo vetorial da velocidade
    v=modulo(vx,vy,vz);
    //calculando velocidades
    vx= vx + (Cm*(wy*vz - wz*vy)- (v*vx)*Cd)*dt;
    vy= vy + (Cm*(wx*vz - wz*vx)- (v*vy)*Cd)*dt;
    vz= vz + (-g + Cm*(wx*vy - wy*vx)- (v*vz)*Cd)*dt;
    //calculando posições
    rx=  rx + vx*dt;
    ry=  ry + vy*dt;
    rz=  rz + vz*dt;
    //tempo para  a parabola ideal
     t = t+dt;

}



//fechando o arquivo
fclose(Rx_magnus);
fclose(Ry_magnus);
fclose(Rz_magnus);
fclose(time_magnus);
printf("Os arquivos Magnus foram criados com sucesso.\n");





return 0;
}
