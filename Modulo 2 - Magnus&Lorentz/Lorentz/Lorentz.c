#include<stdlib.h>
#include<math.h>
#include<stdio.h>


int main(){

//Definindo variáveis de movimento
int n,i;
double rx,ry,rz, vx,vy,vz, Bx,By,Bz, Ex,Ey,Ez, dt=0.001;

//criando e abrindo arquivos
FILE *Rx_lorentz;
FILE *Ry_lorentz;
FILE *Rz_lorentz;

Rx_lorentz = fopen("eixo x (lorentz).txt","w+");
Ry_lorentz = fopen("eixo y (lorentz).txt","w+");
Rz_lorentz = fopen("eixo z (lorentz).txt","w+");

//obtendo valores do usuário
printf("Digite as componentes da velocidade inicial (x,y,z):\n");
scanf("%lf %lf %lf",&vx,&vy,&vz);

printf("Digite as componentes do Campo Magnetico inicial (x,y,z):\n");
scanf("%lf %lf %lf",&Bx,&By,&Bz);

printf("Digite as componentes do Campo Eletrico inicial (x,y,z):\n");
scanf("%lf %lf %lf",&Ex,&Ey,&Ez);





printf("Digite o numero de interaçoes:\n ");
scanf("%d",&n);


//interações numéricas
for(i=0;i<n;i++){

	//preenchendo arquivos
    fprintf(Rx_lorentz,"%lf\n", rx);
    fprintf(Ry_lorentz,"%lf\n", ry);
    fprintf(Rz_lorentz,"%lf\n", rz);

	//calculando velocidades
    vx= vx + ((vy*Bz - vz*By)+Ex)*dt;
    vy= vy + ((vx*Bz - vz*Bx)+Ey)*dt;
    vz= vz + ((vx*By - vy*Bx)+Ez)*dt;

	//calculando posições
   rx=  sin(i)*dt;
   ry=  0;
   rz=  i;

}

//fechando o arquivo
fclose(Rx_lorentz);
fclose(Ry_lorentz);
fclose(Rz_lorentz);
printf("Os arquivos Lorentz foram criados com sucesso.\n");


return 0;
}
