#include<iostream>
#include<graphics.h>
#include<conio.h>
class snake{
	public:
		int x;
		int y;
		int x1;
		int y1;
		int over;
		int count;
		int score;
		int ax[1000];
		int ay[1000];
		void input(char h){
				switch(h){
					case 'a':
				x--;
				break;
			case 'd':
				x++;
				break;
			case 'w':
				y--;
				break;
			case 's':
				y++;
				break;
			default:
				over=1;
				
			}
		}	
		void check(){
			if(x<x1+6&&x>x1-6&&y<y1+6&&y>y1-6){
				x1=rand()%460+30;
	            y1=rand()%460+20;
	            score+=10;
			}
			if(x==480)
			x=21;
			if(x==20)
			x=480;
			if(y==480)
			y=21;
			if(y==20)
			y=480;
			
		}
		void draw(char h){
			count=0;
			for(int i=0;i<1000;i++)
            {
                if(ax[i]!='\0')
                      count++;
            }
			for(int i=0;i<count-1;i++)
			{
				ax[count-i-1]=ax[count-i-2];
				ay[count-i-1]=ay[count-i-2];
			}
			ax[0]=x;
			ay[0]=y;
			
			for(int i=20;i<=score;i+=10)
			{
					if(x<ax[i]+6&&x>ax[i]-6&&y<ay[i]+6&&y>ay[i]-6)
					over=1;
			}
			for(int i=0;i<=score;i+=10)
			{
				circle(ax[i],ay[i],5);
			}
		
			
		}
};

int main()
{
	initwindow(500,500);
	
	snake s;
	char h,h1;
	h='w';
	h1='a';
	circle(s.x,s.y,5);
	s.x1=rand()%460+20;
	s.y1=rand()%460+20;
	s.x=250;
	s.y=250;
	s.over=0;
	s.score=0;
	do{
		line(15,15,15,485);
	line(15,15,485,15);
	line(15,485,485,485);
	line(485,15,485,485);
		circle(s.x1,s.y1,6);
		if(kbhit()){
			h1=h;
			h=getch(); 
			if(h=='a'&&h1=='d')
			h=h1;
			if(h=='d'&&h1=='a')
			h=h1;
			if(h=='w'&&h1=='s')
			h=h1;
			if(h=='s'&&h1=='w')
			h=h1;
			}
		s.input(h);
		s.check();
		s.draw(h);
		delay(10);
		cleardevice();
	}while (s.over==0);
	getch();
}
