#include<graphics.h>
#include<conio.h>
#include<dos.h>

void init();

main()
{
	init();
	
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	
    outtextxy(25,240,"Presiona cualquier boton");
    getch();
	int constanteASumar = 10;
	for(int i = 10 ; i <= 420 ; i += constanteASumar){
		
		setcolor(RED);
 		circle(getmaxx()/2, getmaxy()/2, i);
 		setcolor(GREEN);
		circle(getmaxx()/2, getmaxy()/2, i+50);
 		delay(5);
 		cleardevice();
 		if(i >= getmaxx()-250 || i < 10){
 			constanteASumar = -constanteASumar;
		 }
	}
	
 	
 	
   getch();
   
    closegraph();
   
   
}

void init(){
	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
}
