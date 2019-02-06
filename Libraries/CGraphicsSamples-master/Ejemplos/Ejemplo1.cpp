#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdio.h>


main()
{


	int gd = DETECT, gm; //Variables inicializadas anteriormente, esto no se debe de modificar, ya que alteraría los argumentos
 	initgraph(&gd, &gm, "C:\\TC\\BGI"); //	Se abre la consola auxiliar, en la cual podremos dibujar
	


 	//Pintar pantalla
    setbkcolor(GREEN); //Establece el color
	cleardevice();		//Limpia pantalla para realizar efectos


 	//Imprime en consola clásica
	int tamano;
	int left = 60;
	int top = 80;

 	printf("Dame el tamaño del cuadrado ");
 	scanf("%d", &tamano);

 	//Acompañados
 	settextstyle(2, HORIZ_DIR, 6); //Define el estilo del texto
	outtextxy(40, 100, "Hola, esta es una prueba"); //Dice el texto y sus coordenadas


	//Dibujar una barra
		//bar(left, top, right, bottom);
	setfillstyle(SOLID_FILL, BLUE);
	bar(left, top, left + tamano, top + tamano);
	/*
		Cuadrado: Misma diferencia

	*/


    getch();
    closegraph();
   
   
}
