#include<graphics.h>
#include<conio.h>
#include<dos.h>

void init();

main()
{
	init();
	

    
    
    setbkcolor(WHITE);
    
    int coordX = 0;
    int coordY = 0;
    int radius = 20;
    
    int color = 0;
	for(int i = 0 ;  i<=getmaxx() ; i+=20 )
   	{
   		setcolor(++color);
   		circle(coordX,coordX,i);
   	}
     
    getch();
    closegraph();
   
   
}

void init(){
	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
}
