#include<time.h>
#include<graphics.h>


int main(){

	int i, j, p, q, gd, gm, G[700][700], t, s=16;
	srand(time(NULL));
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	setfillstyle(1,2);

//condições iniciais 
	for(i=s;i<=1350;i=i+s)
    {
		for(j=s;j<=700;j=j+s)
		   {
			if((i==s) || (j==s))
				G[(i-s)/s][(j-s)/s] = -1;
			else if((i==s*(1350/s)) || (j==s*(700/s)))
				G[(i+s)/s][(j+s)/s] = -1;
			if(rand()%10 == 1){
				bar(i-s/2,j-s/2,i+s/2,j+s/2);
				G[i/s][j/s] = 1;
		    }
			else
				G[i/s][j/s] = 0;
		}
	}

//colocando "semente" azul
	setfillstyle(1,1);
	i = s*(1350/s)/2;
	j = s*(700/s)/2;
	bar(i-s/2,j-s/2,i+s/2,j+s/2);
	G[i/s][j/s] = 1;
	delay(2000);

//interações
	while(1) {

		for(i=s;i<=1350;i=i+s){
			for(j =s;j<=700;j=j+s){
				if(getpixel(i,j)==2){

					t = rand()%4;
					p = i;
					q = j;

					if(t==0)
						q = q - s;
					else if(t==1)
						p = p + s;
					else if(t==2)
						q = q + s;
					else if(t==3)
						p = p - s;
					if(G[p/s][q/s] == 0){
						G[i/s][j/s] = 0;
						G[p/s][q/s] = 2;
					}
					else if(G[p/s][q/s] == 1)
						G[i/s][j/s] = 1;
				}
			}
		}
		for(i=s;i<=1350;i=i+s){
            for(j=s;j<=700;j=j+s){
				setfillstyle(1,G[i/s][j/s]);
				bar(i-s/2,j-s/2,i+s/2,j+s/2);
			}
		}
  	}
	
	getch();
	closegraph();
	return 0;
}
