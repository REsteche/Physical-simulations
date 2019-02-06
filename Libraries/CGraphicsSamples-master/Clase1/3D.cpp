#include<graphics.h>
#include<conio.h>
#include<dos.h>

void init();

main()
{
	init();
	
	int midx = getmaxx() / 2;

   int midy = getmaxy() / 2;
    bar3d(midx-50, midy-50, midx+150, midy+150, 100, 1);
   	
	getch();
	
    closegraph();
   
   
}

void init(){
	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
}
