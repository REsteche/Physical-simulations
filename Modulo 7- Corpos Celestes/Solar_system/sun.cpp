#include<stdio.h>
#include<stdlib.h>
#include<math.h>

const int p = 3;
double m[p], vx[p], vy[p],vz[p], Px[p], Py[p], Pz[p], Frx[p], Fry[p], Frz[p], Lx[p],Ly[p],Lz[p],LX,LY,LZ, Em, E,U;
double dt = 0.01;

int main(void){

int i,j,k,n=15000;

double G=4*M_PI*M_PI;

//r(i)[p] � o n�mero de planeta, as massas est�o em arrays para atuar na for�a:
double t = 0.0, R, ff;

//constantes para o problema
//massas dos planetas
m[0]=1.0; //sol, m=1
m[1]=0.000002;
m[2]=0.000017;
m[3]=0.00002;
m[4]=0.000012;
//posi��o inicial
Px[0]=0;
Py[0]=0;
Pz[0]=0;

Px[1]=5.0;
Py[1]=0;
Pz[1]=0;

Px[2]=10.0;
Py[2]=5.0;
Pz[2]=0;

Px[3]=-12;
Py[3]=0;
Pz[3]=2;

Px[4]=5.0;
Py[4]=0;
Pz[4]=3.0;
//velocidades dos planetas
vx[0]=0;
vy[0]=0;
vz[0]=0;

vx[1]=0;
vy[1]= sqrt(4*M_PI*M_PI/Px[1]);
vz[1]=0;

vx[2]=0;
vy[2]=0;
vz[2]= sqrt(4*M_PI*M_PI/Px[2]);

vx[3]=0;
vy[3]=0;
vz[3]= sqrt(4*M_PI*M_PI/Pz[3]);

vx[4]=0;
vy[4]=0;
vz[4]= sqrt(4*M_PI*M_PI/Px[4]);

//arquivo com as posi��es
FILE*planetas;
planetas = fopen("posi��o planetas.txt","w+");
//rquivo com os momentos
FILE*momento;
momento = fopen("momento angular.txt","w+");
//arquivo com a energia
FILE*energia;
energia = fopen("energia.txt","w+");

//contador de intera��es:
for (k=0;k<n;k++){

    for(i=0;i<4;i++){
        U=0;
        Frx[i]=0;
        Fry[i]=0;
        Frz[i]=0;
        for(j=0;j<4;j++){

            if(i!=j){
               R= sqrt((Px[i]-Px[j])*(Px[i]-Px[j]) + (Py[i]-Py[j])*(Py[i]-Py[j]) + (Pz[i]-Pz[j])*(Pz[i]-Pz[j]));
               ff = -G*m[i]*m[j]/(R*R*R);
               Frx[i] += ff *(Px[i]-Px[j]);
               Fry[i] += ff *(Py[i]-Py[j]);
               Frz[i] += ff *(Pz[i]-Pz[j]);

               U = U + G*m[i]*m[j]/R;

            }
        }

    }



    for(i=0;i<4;i++){
        LX = 0;
        LY = 0;
        LZ = 0;
        E = 0;

        //integrador euler-cromer
        vx[i] += (Frx[i]/m[i])*dt;
        Px[i] += vx[i]*dt;

        vy[i] += (Fry[i]/m[i])*dt;
        Py[i] += vy[i]*dt;

        vz[i] += (Frz[i]/m[i])*dt;
        Pz[i] += vz[i]*dt;

        t= t+dt;

        //momento angular

        Lx[i]= m[i]*(Py[i]*vz[i]-Pz[i]*vy[i]);
        Ly[i]= m[i]*(Pz[i]*vx[i]-Px[i]*vz[i]);
        Lz[i]= m[i]*(Px[i]*vy[i]-Py[i]*vx[i]);

        LX = LX + Lx[i];
        LY = LY + Ly[i];
        LZ = LZ + Lz[i];

        //Energia mecanica

        E = E + m[i]*(vx[i]*vx[i] + vy[i]*vy[i] + vz[i]*vz[i])/2 ;

        Em= E-U ;

        //plotando os valores no arquivo
        fprintf(planetas,"%lf   %lf   %lf  ", Px[i],Py[i],Pz[i]);

        fprintf(momento,"%lf   %lf   %lf  ", LX,LY,LZ);

        fprintf(energia,"%lf   %lf\n  ", Em, t );


    }
    fprintf(planetas,"\n");
    fprintf(momento,"\n");
}

printf("\n seus arquivos forsm criados com sucesso!\n");
fclose(planetas);
fclose(momento);
fclose(energia);
return 0;
}


