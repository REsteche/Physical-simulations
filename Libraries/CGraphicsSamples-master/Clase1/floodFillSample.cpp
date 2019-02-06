#include<graphics.h>
#include<conio.h>
#include<dos.h>

void init();

main()
{
	init();
	
    
   	setcolor(RED);
   	circle(100,100,50);
   	setfillstyle(HATCH_FILL, BLUE);
   	floodfill(100,100,RED);
   	
   	
   	setcolor(RED);
   	circle(200,200,50);
   	setfillstyle(SOLID_FILL, BLUE);
   	floodfill(200,200,RED); //Delimitador
	getch();
	
    closegraph();
   
   
}

void init(){
	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
}
