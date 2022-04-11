#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <dos.h>


void knopka();
void drawer(int a,int b);
void printer(int tt,char st[]);
void result(int position);
void button(int x1, int y1 ,int x2,int y2, int col,char *text);
void lines();

int A=0,B=0;
///////////////////////////////////////////////////////////////////////////
int main(void)
{
    int GrDr, GrMod, rez ;
    GrDr=DETECT ;
    initgraph(&GrDr,&GrMod," ") ;
    rez=graphresult() ;
    if(rez!= grOk)
    {
        printf("\n Error graph modeи") ;
        return(1) ;
    }
line(0,400,639,400);
line(319,400,319,0);
rectangle(19,19,219,239);
line(119,19,119,239);
line(19,59,219,59);
outtextxy(63,29, "X");
outtextxy(163,29, "Y");
rectangle(19,249,189,289);
outtextxy(40,259, "A=");
rectangle(19,299,189,339);
outtextxy(40,309, "B=");

line(72,62,72,239);
line(172,62,172,239);

lines ();

outtextxy(400,15,"F(x) = a*sin(x)+b*cos(x)");
outtextxy(400,40,"F(x) = a*tg(x)+b");

button(50, 420, 170, 450,4, "NEW PARAM");
button(240, 420, 340, 450, 2,"GRAPHIC");
button(420,420, 520, 450,2, "EXIT");


knopka();
    closegraph() ;
    return(0) ;
}

/////////////////////////////////////////////////////////////////////////////

void button(int x1, int y1 ,int x2,int y2, int col,char *text)
{
    setfillstyle(1,15);
    bar(x1, y1, x2, y2);
    setbkcolor(15);
    setcolor(col);
    outtextxy (x1+10,y1+5,text);
}

////////////////////////////////////////////////////////////////

void result(int position)
{
    switch (position)
        {
            case 1:
                button(50, 420, 170, 450,4, "NEW PARAM");
                button(240, 420, 340, 450, 2,"GRAPHIC");
                button(420,420, 520, 450,2, "EXIT");
                break;
            case 2:
                button(50, 420, 170, 450,2, "NEW PARAM");
                button(240, 420, 340, 450, 4,"GRAPHIC");
                button(420,420, 520, 450,2, "EXIT");
                break;
            case 3:
                button(50, 420, 170, 450,2, "NEW PARAM");
                button(240, 420, 340, 450, 2,"GRAPHIC");
                button(420,420, 520, 450,4, "EXIT");
                break;
                position=1;
        }
}

////////////////////////////////////////////////////////////////

void printer(int tt,char st[])
{
    st[0]='\0';
    char ch;
    int i=0;
    setcolor(GREEN);
    setbkcolor(0);
            do
            {
                ch=getch();
                if(ch>='0'&&ch<='9')
                {
                   st[i]+=ch;
                   st[i+1]='\0';
                   i++;
                }
                switch(ch)
                {
                    case('.'):
                        st[i]+=ch;
                        st[i+1]='\0';
                        i++;
                        break;
                    case('-'):
                        st[i]+=ch;
                        st[i+1]='\0';
                        i++;
                        break;
                    case(8):
                        setfillstyle(1,0);
                        bar(70,tt,70+strlen(st)*8,tt+20);
                        st[strlen(st)-1]='\0';
   i--;
                        break;
                }
                outtextxy(70,tt,st);
            }
            while(ch!=13);

    if(st=='\0') outtextxy(70,260,"0");
}

////////////////////////////////////////////////////////

void drawer(int a,int b)
{
   int c=0,y1,y2;
float x1=-5,x=359,dx=10.0/24000.0;
setbkcolor(0);
for(int i=0,j=0,c=0;i<11;i++)
{

   y1=round(a*sin(-5+c)+b*cos(-5+c));
   y2=round(a*(sin(-5+c)/cos(-5+c))+b);
 char str[3],str1[10],str2[10];
    setcolor(YELLOW);
    sprintf(str,"%d",(-5+c));
    sprintf(str1,"%d",y1);
    sprintf(str2,"%d",y2);

  outtextxy(22,(j+62),str);//x
  outtextxy(75,(j+62),str);

  outtextxy(122,(j+62),str1);//y
  outtextxy(175,(j+62),str2);
  j+=16;
  c++;

}

while(x1<5)
{
   int h,h1;
   h=210-round(a*sin(x)+b*cos(x));
   h1=210-round(a*(sin(x)/cos(x))+b);

   if(h<320 && h1<320 && h>80 && h1>80)
    {
    putpixel(round(x),h,2);
    putpixel(round(x),h1,4);
    }
    x1+=dx;
    x+=0.01;
}
}

////////////////////////////////////////////////////////

void lines()
{
     setcolor(0);
            setfillstyle(1,0);

            bar(320,57,639,399);

            bar(57,259,185,276);
            bar(57,309,185,326);

            bar(21,61,70,238);
            bar(74,61,119,238);
            bar(121,61,170,238);
            bar(174,61,219,238);

            setbkcolor(0);
setcolor(WHITE);
            outtextxy(200,285, "Parameters");
            outtextxy(472,212, "0");
            outtextxy(453, 72, "Y");
            outtextxy( 599, 215, "X");

setcolor(15);
line(469, 80, 469, 320);//Y
line(359, 210, 599, 210);//X

line(599,205,599,215);//XX
line(599,205,604,210);
line(599,215,604,210);

line(464,80,474,80);//YY
line(464,80,469,75);
line(474,80,469,75);

for(int i=359,j=320;i<=599,j>=80;i+=22,j-=22)
{
    line(i,205,i,215);
    line(464,j,474,j);
}

}

////////////////////////////////////////////////////////

void knopka()
{
    char key;
    int position=1;

    do
    {
//mouse
        int xz,yz;
        char st[10];
        getmouseclick(WM_LBUTTONDOWN,xz,yz);
        if((xz>50)&&(yz>420)&&(xz<170)&&(yz<450))
        {
  lines();

            position=1;
            key='n';
            result(position);

            printer(260,st);
            A=atoi(st);

            //sprintf(st,"%d",A);
            //outtextxy(500,50,st);

            printer(309,st);
            B=atoi(st);

            //sprintf(st,"%d",B);
            //outtextxy(500,100,st);

        }
        else if((xz>200)&&(yz>420)&&(xz<300)&&(yz<450))
        {
             setcolor(0);
            setfillstyle(1,0);
             bar(200,285,280,305);
                         setbkcolor(0);
setcolor(WHITE);
        outtextxy(600,80,"Graph" );
            position=2;
            key='g';
            result(position);
            drawer(A,B);
        }
        else if ((xz>400)&&(yz>420)&&(xz<550)&&(yz<450))
        {
            position=3;
            key='e';
            result(position);
        }

//keyboard
        if(kbhit())
        {
            key=getch();
 if(key=='n')
            {
                lines();

                char st[10];
                position=1;
                result(position);
                printer(260,st);
                A=atoi(st);
                printer(309,st);
                B=atoi(st);
            }

            if(key=='g')
            {
                 setcolor(0);
            setfillstyle(1,0);
             bar(200,285,280,305);
                         setbkcolor(0);
setcolor(WHITE);
        outtextxy(600,80,"Graph" );
                position=2;
                result(position);
                drawer(A,B);
            }

           if(key=='e')
            {
                position=3;
                result(position);
            }

            if(key==77)//right
            {
                position++;
                if(position==4)position=1;
                result(position);
            }

            if(key==75)//left
            {
                position--;
                if(position==0)position=3;
                result(position);
            }

            if(key==13)//enter
            {
                if(position==1)
                {
                    key='n';
  lines();

                    printer(260,st);
                    A=atoi(st);
                    printer(309,st);
                    B=atoi(st);
                }
                if(position==2)
                {
                   key='g';
                    setcolor(0);
            setfillstyle(1,0);
             bar(200,285,280,305);
                         setbkcolor(0);
setcolor(WHITE);
        outtextxy(600,80,"Graph" );
                   drawer(A,B);
                }
                if(position==3)
                    key='e';
            }

        }
    }
    while(key!='e');
}

