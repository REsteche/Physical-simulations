#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
#include <GLFW/glfw3.h>

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

int main (void){
GLFWwindow* window;
//coloque as variáveis aqui:
int i, j, n=100, p=1000;
double xk[n], xk1[n],xk2[n], save[n], save1[n], dx[100];
srand((unsigned)time(NULL));

for (i = 0; i < n; i++)
{
    dx[i] = -1.0+2*i/(double)(n-1);
}
//abertura de janelas glfw
if (!glfwInit())
        return -1;
window = glfwCreateWindow(1000,1000,"corda vibrante", NULL,NULL);

if (!window)
    {
        glfwTerminate();
        return -1;
    }
glfwMakeContextCurrent(window);
glfwSetKeyCallback(window,key_callback);
glfwSwapInterval(1);
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//glRotated(20,0.4,0.2,0.1);

//avisar que houve erro
glfwSetErrorCallback(error_callback);

//colocar as condições iniciais aqui:
for (i=1;i<n-1;i++){
       xk1[i-1] = exp(-100*(dx[i]-dx[n/2])*(dx[i]-dx[n/2]));
       xk2[i] = exp(-100*(dx[i]-dx[n/2])*(dx[i]-dx[n/2]));
       xk[i] = exp(-100*(dx[i]-dx[n/2])*(dx[i]-dx[n/2]));
}
xk1[0] = xk1[n-1] = 0;
xk2[0] = xk2[n-1] = 0;
xk[0] = xk[n-1] = 0;
//iterações do projeto:
while (!glfwWindowShouldClose(window)){
	     glClear(GL_COLOR_BUFFER_BIT);
	     //inclua as iterações aqui:
            for(j=1;j<n-1;j++){
               xk[j] = xk1[j+1] + xk1[j-1] - xk2[j];
            }
            for(j=1;j<n-1;j++){
               xk2[j] = xk1[j];
               xk1[j] = xk[j];
            }
	     glPointSize(2);
         glBegin(GL_LINE_STRIP);
		 glColor3f(1,1,0);
         for(j=0; j<n; j++){
         //lembrar que vertex3f precisa de 3 argumentos, mesmo que o porblema seja linear, os eixos eles precisam ser expressos como constantes
		 glVertex2f(dx[j],xk[j]/10);
		 }
		 glEnd();
		 glfwSwapBuffers(window);
		 glfwPollEvents();
}
glfwDestroyWindow(window);
glfwTerminate();
return 0;
}
