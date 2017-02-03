#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void bezier(int [],int [],int);
void quadrand1(int,int,int,int,int);
void quadrand2(int[],int[],int[],int[],int);
void quadrand3(int[],int[],int[],int[],int);
void quadrand4(int[],int[],int[],int[],int);
int randomg(int N1,int N2);

int a,b;

int main()
{
	int gd=DETECT,gm;
	int i;
	int clr[25],xl,yl,yu;

	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	a=getmaxx()/2;
	b=getmaxy()/2;
	xl=a-8;
	yl=b;
	yu=b-4;
	setfillstyle(CLOSE_DOT_FILL,1);
	floodfill(a,b,20);
	srand(time(NULL));       // SEED RAND
	putpixel(a,b,1+rand()%15);

	for(i=0;i<25;i++)
	 {
	   clr[i]=1+rand()%15;
	   quadrand1(xl,a,yl,yu,clr[i]);
	   yu=yu-10;
	   yl=yl-10;
	   xl=xl-6-i;
	 }

	getch();
	closegraph();
	return 0;
}

void bezier(int x[4],int y[4],int clr_q)
{
  double t;

  for(t=0.0;t<1.0;t+=0.0005)
  {
    double xt=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
    double yt=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
    putpixel(xt,yt,clr_q);
  }

  return;
}

void quadrand1(int xlb,int xub,int ylb,int yub,int clr)
{
  int x1[4],y1[4],x2[4],y2[4];
  int i;

   for(i=0;i<4;i++)
   {
     x1[i]=randomg(xlb,xub);
     y1[i]=randomg(yub,ylb);
   }
   bezier(x1,y1,clr);

   for(i=0;i<4;i++)
    {
      x2[i]=a-(b-y1[i]);
      y2[i]=b-(a-x1[i]);
    }
    bezier(x2,y2,clr);

   quadrand2(x1,y1,x2,y2,clr);

}

void quadrand2(int x12[],int y12[],int x22[],int y22[],int clr2)
{
  int i;

   for(i=0;i<4;i++)
   {
     x12[i]=a-x12[i]+a;
     x22[i]=a-x22[i]+a;
   }
   bezier(x12,y12,clr2);
   bezier(x22,y22,clr2);

   quadrand3(x12,y12,x22,y22,clr2);

}

void quadrand3(int x13[],int y13[],int x23[],int y23[],int clr3)
{
  int i;

   for(i=0;i<4;i++)
   {
     y13[i]=b-y13[i]+b;
     y23[i]=b-y23[i]+b;
   }
   bezier(x13,y13,clr3);
   bezier(x23,y23,clr3);

   quadrand4(x13,y13,x23,y23,clr3);

}

void quadrand4(int x14[],int y14[],int x24[],int y24[],int clr4)
{
  int i;

   for(i=0;i<4;i++)
   {
     x14[i]=a-(x14[i]-a);
     x24[i]=a-(x24[i]-a);
   }
   bezier(x14,y14,clr4);
   bezier(x24,y24,clr4);

}

int randomg(int N1,int N2)
{

    int len=N2-N1+1,r;
   r=N1+rand()%len;
   return r;
}


