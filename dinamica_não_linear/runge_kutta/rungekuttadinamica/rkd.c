#include<stdio.h>
#include<math.h>
#define dimensao 2

#define omega0 2.

int main(void){

  void derivada(int dim, double *x, double *dxdt, double t);
  void rk4(void deri(int , double [], double [], double ), \
	   double h[], int n, double t, double dt);

  int i;
  double dt=0.01;
  double x[dimensao],  dxdt[dimensao],  t;
  double ttotal = 50.;
  int maxsteps = ttotal/dt ;

  x[0]=0.;
  x[1]=0.25 ; // Condicao inicial

  for(i=0;i<maxsteps;i++){
    t = i*dt;
    printf("%lf\t%lf\t%lf\n",t,x[0],x[1]);
    rk4(derivada,x,dimensao,t,dt);
  }

}

void derivada(int dim, double *x, double *dxdt, double t){
  double corrente(double t);
  dxdt[0] = x[1];
  dxdt[1] = -omega0*x[0];
}


/* Runge Kutta integrator from Numerical Recipes plus improvements */
/* void *deri(int n,double h[],double D[],double t);  */

void rk4(void deri(int , double [], double [], double ), \
double h[], int n, double t, double dt)
{
  // #define naux 260

int i;
double k1[n],k2[n],k3[n],k4[n],h0[n];
double dt2, dt6;

dt2=dt/2.;
dt6=dt/6.;

for (i = 0 ; i<n; i++)
	h0[i] = h[i];

deri(n,h0,k1,t);
for (i =0 ; i<n ; i++)
	h0[i]=h[i]+dt2*k1[i];

deri(n,h0,k2,t+dt2);
for (i =0 ; i<n ; i++)
	h0[i]=h[i]+dt2*k2[i];

deri(n,h0,k3,t+dt2);
for (i =0 ; i<n ; i++)
	h0[i]=h[i]+dt*k3[i];

deri(n,h0,k4,t+dt);
for (i = 0 ; i<n ; i++)
	{h0[i]=h[i]+dt*k4[i];};

for (i =0; i<n ; i++)
	h[i]=h[i]+dt6*(2.*(k2[i]+k3[i])+k1[i]+k4[i]);

return;
}


