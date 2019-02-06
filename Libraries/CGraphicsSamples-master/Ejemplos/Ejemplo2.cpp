#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>


main()
{


	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
	
 	int opcion;

 	while(true){
 		printf("Quieres dibujar un circulo o un cuadrado? \n1. Circulo \n2.Cuadrado\n\n");
	 	scanf("%d", &opcion);
 		cleardevice();

	 	getmaxx(); //Obtiene el total de pixeles en X
	    getmaxy(); //Obtiene el total de pixeles en Y


	    int mitadX = getmaxx() / 2;
		int mitadY = getmaxy() / 2;


	    if (opcion == 1)
	    {
	    	

		 	//Circle(Coordenada X, Coordenada Y, Radio)
		 	setcolor(BLUE); 				//Color de la linea del circulo
		 	circle(mitadX, mitadY, 200);		//Dibuja el circulo
		 	setfillstyle(SOLID_FILL,RED);	//Define como estará dibujado el circulo
		    floodfill(mitadX, mitadY, BLUE);		//Rellena el circulo y se le indica hasta donde detenerse

	    }else{
	    	//left, top, right, bottom
	    	bar(mitadX - 50, mitadY - 50, mitadX + 50, mitadY + 50);

	    }

	    getche();
	   
 	}

    getch();
    closegraph();
   
   
}
