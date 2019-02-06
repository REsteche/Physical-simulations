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
int i, j, t, n = 30, M[n][n], E[n][n], ia, ja;
double r, T = 100, B = -200, J = -10, boltz, Ei, Ef, DE;
srand((unsigned)time(NULL));
//definindo uma matriz de probabilidade randomica
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        r = rand()/((double)RAND_MAX);
        if(r < 0.5){
            M[i][j] = 1;
        }
        else{
            M[i][j] = -1;
        }
    }
}
//definindo as condições de contorno
for(i=0;i<n;i++){
    M[i][n-1] = M[i][0];
}
for(j=0;j<n;j++){
    M[n-1][j] = M[0][j];
}

//abertura de janelas glfw
if (!glfwInit())
        return -1;
window = glfwCreateWindow(1000,1000,"Modelo de ising", NULL,NULL);

if (!window)
    {
        glfwTerminate();
        return -1;
    }
glfwMakeContextCurrent(window);
glfwSetKeyCallback(window,key_callback);
glfwSwapInterval(1);
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

//avisar que houve erro
glfwSetErrorCallback(error_callback);

//iterações do projeto:
while (!glfwWindowShouldClose(window)){
	     glClear(GL_COLOR_BUFFER_BIT);
	     //inclua as iterações aqui:
         Ei = 0.0;
         Ef = 0.0;
         for(i=1;i<n-1;i++){
             for(j=1;j<n-1;j++){
                  E[i][j] = -J*M[i][j]*(M[i][j+1] + M[i][j-1] + M[i+1][j] + M[i-1][j]) - B*M[i][j];
                  Ei += E[i][j];
             }
         }

         ia = rand()%n;
         ja = rand()%n;
         M[ia][ja] = -M[ia][ja];

         for(i=1;i<n-1;i++){
             for(j=1;j<n-1;j++){
                  E[i][j] = -J*M[i][j]*(M[i][j+1] + M[i][j-1] + M[i+1][j] + M[i-1][j]) - B*M[i][j];
                  Ef += E[i][j];
             }
         }

         DE = Ef - Ei;
         if(DE>0){
             boltz = exp(-(DE/T));
             r = rand()/((double)RAND_MAX);
             if(boltz<r){
                M[ia][ja] = - M[ia][ja];
             }
         }

	     glPointSize(25);
         glBegin(GL_POINTS);
         for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    glColor3d(0,(1 + M[i][j]/2.0),0);
                    glVertex2d((2*(double)i/n - 1), (2*(double)j/n - 1));
                }
         }
         glEnd();
         glfwSwapBuffers(window);
         glfwPollEvents();
}
glfwDestroyWindow(window);
glfwTerminate();
return 0;
}
