#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
#include <GLFW/glfw3.h>
//variável global(para entrar como argument das funções): número total de particulas do sistema

int n=125;

//acusar eventuais impedimentos da janela ser aberta
static void error_callback(int error, const char* description)
{
      fprintf(stderr, "Error: %s\n", description);
}
//listar respostas do programa a comandos no teclado
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose (window, GLFW_TRUE);
}

double distancia (double a, double b, double c, double d, double e, double f){
double r;
r = (a - b)*(a - b) + (c - d)*(c - d) + (e - f)*(e - f);
return r;
}

void centro_massa (double x,double y,double z,double vx,double vy, double vz,double Xcm,double Ycm,double Zcm,double VXcm,double VYcm,double VZcm){

int i;

Xcm = 0;
Ycm = 0;
Zcm= 0;
VXcm = 0;
VYcm = 0;
VZcm = 0;

for(i=0;i<n;i++){
    Xcm += x;
    Ycm += y;
    Zcm += z;
    VXcm += vx;
    VYcm += vy;
    VZcm += vz;
}

Xcm = Xcm/n;
Ycm = Ycm/n;
Zcm = Zcm/n;
VXcm = VXcm/n;
VYcm = VYcm/n;
VZcm = VZcm/n;

}


int main (void){
//definir ponteiro janela
GLFWwindow* window;

int i, j, k, cont=0;
double dt= 0.01, fx[n], fy[n], fz[n], fx1[n], fy1[n], fz1[n], x[n], y[n], z[n], x1[n], y1[n], z1[n];
double R[n], R1[n], r6, r12, vx[n], vy[n], vz[n], u, a=1, Xcm[1], Ycm[1], Zcm[1], VXcm[1], VYcm[1], VZcm[1];
srand((unsigned)time(NULL));
x[0]= 0;
y[0]= 0;
z[0]= 0;

if (!glfwInit())
        return -1;
window = glfwCreateWindow(1000,1000,"Dinâmica Molecular", NULL,NULL);

if (!window)
    {
        glfwTerminate();
        return -1;
    }
glfwMakeContextCurrent(window);
glfwSetKeyCallback(window,key_callback);
glfwSwapInterval(1);
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
glRotated(20,0.4,0.2,0.1);

//avisar que houve erro
glfwSetErrorCallback(error_callback);

for(i=0;i<5;i++){
    for(j=0;j<5;j++){
        for(k=0;k<5;k++){
            cont = k + 5*j + 25*i;
            u = rand()/((double)RAND_MAX);
            x[cont] = a*k + (u - 0.5)*0.5;
            u = rand()/((double)RAND_MAX);
            y[cont] = a*j + (u - 0.5)*0.5;
            u = rand()/((double)RAND_MAX);
            z[cont] = a*i + (u - 0.5)*0.5;
        }
    }
}

centro_massa (x[n], y[n], z[n], vx[n], vy[n], vz[n], Xcm[1], Ycm[1], Zcm[1], VXcm[1], VYcm[1], VZcm[1]);

for(j=0;j<n;j++){
vx[j] -= VXcm[0];
vy[j] -= VYcm[0];
vz[j] -= VZcm[0];
x[j] -= Xcm[0];
y[j] -= Ycm[0];
z[j] -= Zcm[0];
}

while (!glfwWindowShouldClose(window)){
	     glClear(GL_COLOR_BUFFER_BIT);

for(i=0;i<10000;i++){
   for(j=0;j<n;j++){
       fx[j]=0;
       fy[j]=0;
       fz[j]=0;
    }
    for(j=0;j<n;j++){
        fx1[j]=0;
        fy1[j]=0;
        fz1[j]=0;
    }
    for(j=0;j<n;j++){
        vx[j]=0;
        vy[j]=0;
        vz[j]=0;
    }

    for(j=0;j<n;j++){
        R[j] = distancia(x[j],x[j+1],y[j],y[j+1],z[j],z[j+1]);
        r6 = R[j]*R[j]*R[j];
        r12 = r6*r6;
        fx[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R[j]*R[j])*(x[j]-x[j+1]);
        fy[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R[j]*R[j])*(y[j]-y[j+1]);
        fz[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R[j]*R[j])*(z[j]-z[j+1]);
    }

    for(j=0;j<n;j++){
        x1[j]= x[j] + vx[j]*dt + (fx[j]*dt*dt)/2;
        y1[j]= y[j] + vy[j]*dt + (fy[j]*dt*dt)/2;
        z1[j]= z[j] + vz[j]*dt + (fz[j]*dt*dt)/2;
    }
    for(j=0;j<n;j++){
        R1[j] = distancia(x1[j],x1[j+1],y1[j],y1[j+1],z1[j],z1[j+1]);
        r6 = R[j]*R[j]*R[j];
        r12 = r6*r6;
        fx1[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R1[j]*R1[j])*(x1[j]-x1[j+1]);
        fy1[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R1[j]*R1[j])*(y1[j]-y1[j+1]);
        fz1[j]= 24*(2*(1/(r12)) - (1/r6))*(1/R1[j]*R1[j])*(z1[j]-z1[j+1]);
    }
    for(j=0;j<n;j++){
        vx[j]= vx[j] + ((fx[j]+fx1[j])*dt)/2;
        vy[j]= vy[j] + ((fy[j]+fy1[j])*dt)/2;
        vz[j]= vz[j] + ((fz[j]+fz1[j])*dt)/2;
        x[j]= x[j] + vx[j]*dt + fx[j]*dt*dt/2;
        y[j]= y[j] + vy[j]*dt + fy[j]*dt*dt/2;
        z[j]= z[j] + vz[j]*dt + fz[j]*dt*dt/2;

        if(x[j]<2.5){
          x[j] = x[j] + 5;
        }
        if(x[j]>2.5){
          x[j] = x[j] - 5;
        }
        if(y[j]<2.5){
          y[j] = y[j] + 5;
        }
        if(y[j]>2.5){
          y[j] = y[j] - 5;
        }
        if(z[j]<2.5){
          z[j] = z[j] + 5;
        }
        if(z[j]>2.5){
          z[j] = z[j] - 5;
        }

        }

    }
         glPointSize(2);
         glBegin(GL_POINTS);
		 glColor3f(1,1,1);
         for(j=0; j<n; j++){
		 glVertex3f(x[j]/10,y[j]/10,z[j]/10);
		 }
		 glEnd();
		 glfwSwapBuffers(window);
		 glfwPollEvents();
}
glfwDestroyWindow(window);
glfwTerminate();
return 0;
}
