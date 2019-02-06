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
int i, j, n=400;
double V[n][n];
srand((unsigned)time(NULL));

//abertura de janelas glfw
if (!glfwInit())
        return -1;
window = glfwCreateWindow(1000,1000,"Método da relaxação", NULL,NULL);

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

//colocar as condições iniciais aqui:

//zerando potenciais
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        V[i][j] = 0;
    }
}
//desenho dos capacitores:
for(j=n/4;j<n/4+2;j++){
	for(i=n/4;i<3*n/4;i++){
		V[i][j] = -1;
	}
}

for(j=3*n/4;j<3*n/4+2;j++){
	for(i=n/4;i<3*n/4;i++){
		V[i][j] = 1;
	}
}
//iterações do projeto:
while (!glfwWindowShouldClose(window)){
	     glClear(GL_COLOR_BUFFER_BIT);
	     //inclua as iterações aqui:

	     for(i=1;i<n-1;i++){
            for(j=1;j<n-1;j++){
                if(!(((i>n/4)&&(i<3*n/4))&&(((j>n/4)&&(j<n/4+2))||((j>3*n/4)&&(j<3*n/4+2))))){
                            V[i][j] = (V[i][j-1] + V[i][j+1] + V[i-1][j] + V[i+1][j])/4;
                }

            }
         }



            glPointSize(3);
            glBegin(GL_POINTS);
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                glColor3d(((V[i][j] + 1)/2),(1 - (V[i][j] + 1)/2)/*(V[i][j] + 1)*2)*/,( 1 - (V[i][j] + 1)/2));
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
