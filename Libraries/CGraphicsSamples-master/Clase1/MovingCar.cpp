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
	int j= 0;
	
	for(int i = 0 ; i <= 420 ; i = i + 10, j++ ){
		
		
 		rectangle(50+i, getmaxy()-130, 250+i, getmaxy()-50);
 	 
 
 		rectangle(250+i, getmaxy()-100, 300+i, getmaxy()-50);
 	
 	
 		circle(70+i, getmaxy()-50,20);
 		circle(230+i, getmaxy()-50,20);
 		delay(100);
 		cleardevice();
	}
	
 	
 	
   getch();
   
    closegraph();
   
   
}

void init(){
	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
}
