#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<stdio.h>


main()
{
	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
	
	
	//left, top, right, bottom
	
	int coordy = 100;
	
	circle(100, coordy, 50);
	int click = 0;
	while(true){
		 click = getch();
		
		switch(click){
			case 100:
				coordy += 20;
				cleardevice();
				
				circle(100, coordy, 50);
				break;
				
			case 97:
				coordy -= 20;
				cleardevice();
				
				circle(100, coordy, 50);
				break;
		}	
	}
	
    getch();
    closegraph();
   
   
}
