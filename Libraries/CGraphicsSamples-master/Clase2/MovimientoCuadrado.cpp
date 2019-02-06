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
	
	int j = 5;
	
	for(int i = 0 ; i<= getmaxx() ; i++){
		
		if(i % 20 == 0){
			setfillstyle(SLASH_FILL, BLACK);
			j = 100;
		}else{
			setfillstyle(LTBKSLASH_FILL, RED);
			j = 200;
		}
		
		bar(30+i, 30, 100+i, 100);
		
		delay(j);
		cleardevice();
	}

    
    getch();
    closegraph();
   
   
}
