# Sobre os softwares com códigos para exibição em tempo real: 

utilizei uma biblioteca em C conhecida como OpenGL, mais especificamente o GLFW3, que pode ser obtido na pasta libraries, e tem sua instalação e uso 
muito bem explicados nesse vídeo listado à seguir: 

	* https://www.youtube.com/watch?v=0WrSGMuU964

vou deixar também no final desse texto um script/template com o código básico "geral" para você implementar exibição em tempo real dentro de qualquer simulação.

# About real-time simulations: 

link below to understand how to install and use GLFW3 and OpenGL 

	* https://www.youtube.com/watch?v=0WrSGMuU964

and below, one template (pretty much general) to use in your first simulations.
ps.: the comments are in portuguese, if you want for better understandig, use google translate to know what each part of the code do. 

`glfw3 template:` 

```C
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
int ;
double ;
srand((unsigned)time(NULL));

//abertura de janelas glfw
if (!glfwInit())
        return -1;
window = glfwCreateWindow(1000,1000,"TITULO", NULL,NULL);  //coloque o titulo da janela entre aspas 

if (!window)
    {
        glfwTerminate();
        return -1;
    }
glfwMakeContextCurrent(window);
glfwSetKeyCallback(window,key_callback);
glfwSwapInterval(1);
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//glRotated(20,0.4,0.2,0.1); //usar somente em casos tridimensionais, se não da merda

//avisar que houve erro
glfwSetErrorCallback(error_callback);

//colocar as condições iniciais aqui:


//iterações do projeto:
while (!glfwWindowShouldClose(window)){
	     glClear(GL_COLOR_BUFFER_BIT);
	     //inclua as iterações aqui:
	     
		 
		 
		 
		 
	     glPointSize(2);
             glBegin(GL_POINTS); //para outros casos, voce tambem pode usar GL_LINES
		 glColor3f(1,1,1);
         for(j=0; j<n; j++){ 
		 glVertex3f(/*colocar aqui os pontos que irão aparecer na tela*/); //glVertex3f - o 3 indica que a função receb 3 argumentos, também pode ser feita para 2 ou 1.
		 }
		 glEnd();
		 glfwSwapBuffers(window);
		 glfwPollEvents();
}
glfwDestroyWindow(window);
glfwTerminate();
return 0;
}
```

