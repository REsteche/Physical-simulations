#include<graphics.h>
#include<conio.h>
#include<dos.h>

void init();
main()
{
	init();
	

    

    
    setbkcolor(WHITE);
    
    //Change RED to WHITE.
    cleardevice();
    setfillstyle(SOLID_FILL, BLACK);
    setcolor(RED);
    settextstyle(2,HORIZ_DIR,6);
   	outtextxy (getmaxx()/2 - 100, 100, "Ich liebe Deutschland!");
   	bar(getmaxx()/2 - 150, 150, getmaxx()/2 + 150, 200);
   	
   	setfillstyle(SOLID_FILL, RED);
   	
   	
   	bar(getmaxx()/2 - 150, 200, getmaxx()/2 +150, 250);
   	
   	setfillstyle(SOLID_FILL, YELLOW);
   	bar(getmaxx()/2 - 150, 250, getmaxx()/2 + 150, 300);
    
    
     
    getch();
    closegraph();
   
   
}

void init(){
	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
}
