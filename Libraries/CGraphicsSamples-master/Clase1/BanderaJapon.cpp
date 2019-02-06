#include<graphics.h>
#include<conio.h>
#include<dos.h>

void init();
main()
{
	init();
	
	setbkcolor(BLACK);
	cleardevice();
	settextstyle(2,HORIZ_DIR,6);
	outtextxy(getmaxx()/2 - 60, getmaxy()/2 - 150, "Heiwa To Shinpo");
	
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(getmaxx()/2 - 150, getmaxy()/2 - 100, getmaxx()/2 + 150, getmaxy()/2 + 100);
	 
	setcolor(RED);
    circle(getmaxx() / 2, getmaxy() / 2,50);
    setfillstyle(SOLID_FILL,RED);
    //Change RED to WHITE.
    floodfill(getmaxx() / 2, getmaxy() / 2,RED);
    
    getch();
    
    cleardevice();
    
    
    closegraph();
   
   
}

void init(){
	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
}
