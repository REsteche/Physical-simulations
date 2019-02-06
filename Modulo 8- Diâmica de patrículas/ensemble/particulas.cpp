#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<time.h>

int main (void){

int n=100, i, j, k, cont=0;
double dt= 0.01, fx[n], fy[n], fz[n], fx1[n], fy1[n], fz1[n], x[n], y[n], z[n], x1[n], y1[n], z1[n];
double R[n], R1[n], r6, r12, vx[n], vy[n], vz[n], u, v, a=1;
srand((unsigned)time(NULL));

x[0]= 0;
y[0]= 0;
z[0]= 0;

for(i=0;i<5;i++){
    for(j=0;j<5;j++){
        for(k=0;k<5;k++){
            cont = i + 5*j + 25*k;
            u = rand()/((double)RAND_MAX);
            v = rand()/((double)RAND_MAX);
            x[cont] = a*i + (u - v)*0.1;
            y[cont] = a*i + (u - v)*0.1;
            z[cont] = a*i + (u - v)*0.1;
        }
    }
}

for(j=0;j<n;j++){
    vx[j]=0;
    vy[j]=0;
    vz[j]=0;
}
for(j=0;j<n;j++){
    fx[j]=0;
    fy[j]=0;
    fz[j]=0;
}

for(i=0;i<100;i++){
    for(j=0;j<n;j++){
        R[j]=((x[i]-x[i+1])*(x[i]-x[i+1]) + (y[i]-y[i+1])*(y[i]-y[i+1]) + (z[i]-z[i+1])*(z[i]-z[i+1]));
        r6 = R[j]*R[j]*R[j];
        r12 = r6*r6;
        fx[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R[j])*(x[j]-x[j+1]);
        fy[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R[j])*(y[j]-y[j+1]);
        fz[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R[j])*(z[j]-z[j+1]);
    }
    for(j=0;j<n;j++){
        x1[j]= x[j] + vx[j]*dt + fx[j]*dt*dt/2;
        y1[j]= y[j] + vy[j]*dt + fy[j]*dt*dt/2;
        z1[j]= z[j] + vz[j]*dt + fz[j]*dt*dt/2;
    }
    for(j=0;j<n;j++){
        R1[j]=((x1[i]-x1[i+1])*(x1[i]-x1[i+1]) + (y1[i]-y1[i+1])*(y1[i]-y1[i+1]) + (z1[i]-z[i+1])*(z1[i]-z1[i+1]));
        r6 = R[j]*R[j]*R[j];
        r12 = r6*r6;
        fx1[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R1[j])*(x1[j]-x1[j+1]);
        fy1[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R1[j])*(y1[j]-y1[j+1]);
        fz1[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R1[j])*(z1[j]-z1[j+1]);
    }
    for(j=0;j<n;j++){
        x[j]= x[j] + vx[j]*dt + fx[j]*dt*dt/2;
        y[j]= y[j] + vy[j]*dt + fy[j]*dt*dt/2;
        z[j]= z[j] + vz[j]*dt + fz[j]*dt*dt/2;

        vx[j]= vx[j] + fx1[j]*dt/2;
        vy[j]= vy[j] + fy1[j]*dt/2;
        vz[j]= vz[j] + fz1[j]*dt/2;
    }
    for(j=0;j<n;j++){
        fx[j] = fx1[j];
        fy[j] = fy1[j];
        fz[j] = fz1[j];
    }
}

return 0;
}
