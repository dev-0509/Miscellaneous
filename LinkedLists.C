#include<stdio.h>
#include<conio.h>
#include<graphics.h>
struct link
{
  int info;
  struct link *next;
}node;
struct link *root1=NULL,*root2=NULL;
struct doubly_list
{
  int info;
  struct doubly_list *next,*prev;
}n;
struct doubly_list *root=NULL;
struct stack
{
  int s[10];
  int top;
}stk;
struct polynomial
{
  int coeff,expo;
  struct polynomial *next;
}n1;
struct polynomial *rt1=NULL,*rt2=NULL,*rt3=NULL;
int ctr=0,stck=0;
struct polynomial * create_poly(struct polynomial *r)
{
  struct polynomial *t,*temp;
  t=r;
  temp=(struct polynomial *)malloc(sizeof(n1));
  temp->next=NULL;
  return temp;
}
void beep()
{
  sound(2000);
  delay(100);
  nosound();
  return;
}
void arrow()
{
  int i;
  if(stck==1)
  {
      sound(500);
      delay(70);
      nosound();
      printf("\t\t\t\t  |");
      delay(50);
      printf("\t\t\t\t  v");
  }
  else
  {
    for(i=1;i<5;i++)
    {
      sound(500*i);
      delay(70);
      nosound();
      printf("%c",196);
      delay(50);
    }
    printf(">");
  }
}
void draw_bk()
{
  int color,i,x,y,xmax,ymax;
  xmax=getmaxx();
  ymax=getmaxy();
  for(i=0;i<6000;i++)
  {
    x=rand() % xmax;
    y=rand() % ymax;
    color=rand() % 12;
    putpixel(x,y,color);
  }
}
void screen(int n,int m)
{
  setgraphmode(2);
  setbkcolor(n);
  textcolor(m);
  clearviewport();
  draw_bk();
}
void error()
{
  char a;
  do
  {
    screen(0,14);
    sound(100);
    printf("\n\n\n\n\n\n\n\n\tHey ! The List does not Exists !");
    delay(2000);
    printf("\n\n\n\n\n\n\n\n\t\tPress 'e' to Exit ..");
    a=getch();
  }while(a!='e');
  nosound();
}
void startup()
{
  int i=1;
  char a;
  setgraphmode(2);
  setbkcolor(10);
  draw_bk();
  gotoxy(4,2);
  printf("%c",176);
  gotoxy(4,25);
  printf("%c",176);
  gotoxy(76,2);
  printf("%c",176);
  gotoxy(76,25);
  printf("%c",176);
  delay(400);
  setcolor(14);
  circle(300,240,230);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
  beep();
  setcolor(4);
  outtextxy(180,140,"LINK");delay(200);beep();outtextxy(269,140,"E");delay(200);beep();outtextxy(291,140,"D");
  delay(300);
  beep();
  outtextxy(350,140,"LI");delay(300);beep();outtextxy(386,140,"S");delay(200);beep();outtextxy(406,140,"T");
  delay(300);
  beep();
  setcolor(4);
  outtextxy(140,280,"I");delay(100);beep();outtextxy(151,280,"M");delay(100);beep();outtextxy(181,280,"P");delay(90);beep();outtextxy(203,280,"L");delay(80);beep();outtextxy(224,280,"E");delay(80);beep();outtextxy(246,280,"M");delay(30);beep();outtextxy(276,280,"E");delay(30);beep();outtextxy(298,280,"N");delay(20);beep();outtextxy(325,280,"T");delay(20);beep();outtextxy(346,280,"A");delay(20);beep();outtextxy(370,280,"T");delay(20);beep();outtextxy(392,280,"I");delay(20);beep();outtextxy(404,280,"O");delay(20);beep();outtextxy(426,280,"N");
  getch();
  return;
}
void linked_list_info_3()
{
  int i;
  setgraphmode(2);
  setbkcolor(14);
  setcolor(12);
  delay(800);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
  outtextxy(0,40," # Circular Linked List #");
  line(25,65,205,65);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  delay(1000);
  beep();
  outtextxy(235,55,"Circular Linked List is a variation of Linked list");
  delay(1000);
  beep();
  outtextxy(220,80,"in which first element points to last element and");
  delay(1000);
  beep();
  outtextxy(220,105,"last element points to first element. The last Node");
  delay(1000);
  beep();
  outtextxy(220,130,"contains the reference (address) to the first Node");
  delay(1000);
  beep();
  outtextxy(220,155,"and the first Node contains the reference to the");
  delay(1000);
  beep();
  outtextxy(220,180,"last Node.");
  delay(1500);
  beep();
  setcolor(4);
  rectangle(50,260,100,295);
  delay(500);
  beep();
  outtextxy(60,274,"Info");
  rectangle(101,260,135,295);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(800);
  beep();
  setcolor(1);
  outtextxy(113,262,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(500);
  beep();
  for(i=135;i<=160;i++)
    outtextxy(i,263,"--");
  outtextxy(177,263,">");
  delay(800);
  beep();
  rectangle(190,260,240,295);
  rectangle(241,260,275,295);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(800);
  beep();
  setcolor(2);
  outtextxy(253,262,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(500);
  beep();
  for(i=275;i<=300;i++)
    outtextxy(i,263,"--");
  outtextxy(317,263,">");
  delay(500);
  beep();
  rectangle(330,260,380,295);
  rectangle(381,260,415,295);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(800);
  beep();
  setcolor(3);
  outtextxy(393,262,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(500);
  beep();
  for(i=415;i<=440;i++)
    outtextxy(i,263,"--");
  outtextxy(457,263,">");
  delay(500);
  beep();
  rectangle(470,260,520,295);
  rectangle(521,260,555,295);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(800);
  beep();
  setcolor(4);
  outtextxy(533,262,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(900);
  beep();
  ellipse(300,300,154,28,290,50);
  delay(300);
  beep();
  outtextxy(40,264,">");
  line(39,272,39,284);
  setcolor(1);
  rectangle(480,452,800,700);
  outtextxy(490,463," Redirect Back :->");
  getch();
  return;
}
void linked_list_info_2()
{
  int i,j=1;
  setgraphmode(2);
  setbkcolor(15);
  setcolor(4);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(600);
  beep();
  line(60,40,580,40);
  delay(600);
  beep();
  line(0,0,60,40);
  delay(600);
  beep();
  line(580,40,640,0);
  setcolor(2);
  delay(800);
  beep();
  outtextxy(70,1,"CLASSIFICATION TO LINKED LISTS");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
  setcolor(1);
  delay(1000);
  beep();
  outtextxy(0,80," # Singly Linked List #");
  line(25,105,190,105);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  delay(1200);
  beep();
  outtextxy(220,90,"Singly linked lists contain nodes which have a data");
  delay(1200);
  beep();
  outtextxy(210,110,"as well as an address part i.e. next, which points");
  delay(1200);
  beep();
  outtextxy(210,130,"to the next node in sequence of nodes. The operations");
  delay(1200);
  beep();
  outtextxy(210,150,"we can perform on singly linked lists are insertion,");
  delay(1200);
  beep();
  outtextxy(210,170,"deletion and traversal.");
  delay(1000);
  beep();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  rectangle(50,210,100,240);
  outtextxy(60,222,"Info");
  rectangle(101,210,135,240);
  setcolor(6);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(800);
  beep();
  outtextxy(113,210,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(500);
  beep();
  for(i=135;i<=160;i++)
    outtextxy(i,212,"--");
  outtextxy(177,212,">");
  delay(500);
  beep();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  rectangle(190,210,240,240);
  rectangle(241,210,275,240);
  setcolor(5);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(800);
  beep();
  outtextxy(253,210,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(500);
  beep();
  for(i=275;i<=300;i++)
    outtextxy(i,212,"--");
  outtextxy(317,212,">");
  delay(500);
  beep();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  rectangle(330,210,380,240);
  rectangle(381,210,415,240);
  setcolor(3);
  delay(800);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(393,210,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(500);
  beep();
  for(i=415;i<=440;i++)
    outtextxy(i,212,"--");
  outtextxy(457,212,">");
  delay(500);
  beep();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  rectangle(470,210,520,240);
  rectangle(521,210,555,240);
  setcolor(4);
  delay(800);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(533,210,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(800);
  beep();
  outtextxy(560,211," . ");
  delay(500);
  beep();
  outtextxy(570,211," . ");
  delay(500);
  beep();
  outtextxy(580,211," . ");
  delay(500);
  beep();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  outtextxy(575,212,"so on");
  getch();
  setcolor(1);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
  outtextxy(0,260," # Doubly Linked List #");
  line(25,285,197,285);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  delay(600);
  beep();
  outtextxy(225,280,"In a doubly linked list, each node contains two");
  delay(1200);
  beep();
  outtextxy(200,300,"links, the first link points to the previous node");
  delay(1200);
  beep();
  outtextxy(175,320,"and the next link points to the next node in the sequence.");
  delay(1000);
  beep();
  setcolor(1);
  rectangle(10,380,125,410);
  rectangle(41,380,94,410);
  delay(600);
  beep();
  line(10,380,41,410);
  line(10,410,41,380);
  delay(800);
  beep();
  setcolor(4);
  circle(25,395,4);
  delay(600);
  beep();
  line(25,395,25,445);
  line(25,445,51,445);
  delay(800);
  beep();
  ellipse(145,450,0,360,95,25);
  delay(600);
  beep();
  outtextxy(82,436,"NULL Pointer to");
  delay(900);
  beep();
  outtextxy(60,448,"signify no node before");
  delay(900);
  beep();
  outtextxy(82,460,"the first node");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  setcolor(6);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(800);
  beep();
  outtextxy(105,380,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(500);
  beep();
  for(i=125;i<=150;i++)
    outtextxy(i,375,"--");
  outtextxy(167,375,">");
  rectangle(179,380,294,410);
  rectangle(210,380,263,410);
  setcolor(1);
  delay(800);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(190,380,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(500);
  beep();
  for(i=153;i>=128;i--)
    outtextxy(i,388,"--");
  outtextxy(126,388,"<");
  setcolor(5);
  delay(800);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(274,380,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(800);
  beep();
  for(i=294;i<=319;i++)
    outtextxy(i,375,"--");
  outtextxy(336,375,">");
  delay(500);
  beep();
  rectangle(348,380,463,410);
  rectangle(379,380,432,410);
  setcolor(6);
  delay(800);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(359,380,"*");
  delay(500);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  for(i=323;i>=297;i--)
    outtextxy(i,388,"--");
  outtextxy(295,388,"<");
  setcolor(3);
  delay(800);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(443,380,"*");
  delay(500);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  for(i=463;i<=488;i++)
    outtextxy(i,375,"--");
  outtextxy(505,375,">");
  rectangle(517,380,628,410);
  rectangle(548,380,598,410);
  setcolor(3);
  delay(800);
  beep();
  setcolor(5);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  outtextxy(528,380,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(500);
  beep();
  setcolor(5);
  for(i=492;i>=466;i--)
    outtextxy(i,388,"--");
  outtextxy(464,388,"<");
  setcolor(4);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(800);
  beep();
  outtextxy(608,380,"*");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  line(628,388,640,388);
  setcolor(3);
  line(628,401,640,401);
  delay(800);
  beep();
  setcolor(4);
  outtextxy(570,415," . ");
  delay(500);
  beep();
  outtextxy(580,415," . ");
  delay(500);
  beep();
  outtextxy(590,415," . ");
  delay(500);
  beep();
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  outtextxy(595,420,"so on");
  setcolor(1);
  rectangle(510,452,800,700);
  outtextxy(520,463," Continue :->");
  getch();
  linked_list_info_3();
  return;
}
void linked_list_info_1()
{
  int a=0,i,j=1,x,ctr=0;
  char c;
  setgraphmode(2);
  setbkcolor(15);
  setcolor(12);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  delay(200);
  outtextxy(200,10,"HEY");
  delay(200);
  beep();
  outtextxy(260,10,"!");
  delay(600);
  outtextxy(280,10,"I'M LINKED LIST");
  delay(700);
  beep();
  outtextxy(470,10,"!");
  setcolor(4);
  delay(1000);
  beep();
  rectangle(183,6,482,47);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  setcolor(4);
  outtextxy(10,70,"Linked List is a Linear Data Structure and");
  delay(1000);
  beep();
  outtextxy(10,91,"is very common data structure.");
  delay(1000);
  beep();
  outtextxy(10,121,"It consists of group of nodes in a sequence");
  delay(1000);
  beep();
  outtextxy(10,147,"which are divided in two parts. Each node");
  delay(1000);
  beep();
  outtextxy(10,174,"consists of its own data and the address of the");
  delay(1000);
  beep();
  outtextxy(10,201,"next node, thus forming a chain.");
  delay(1000);
  beep();
  outtextxy(10,226,"Linked Lists are used to create trees and graphs.");
  delay(400);
  beep();
  ellipse(320,360,0,360,315,115);
  delay(1000);
  beep();
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  outtextxy(230,258,"! MY HISTORY !");
  delay(100);
  beep();
  arc(300,0,-119,-59,300);
  setcolor(12);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  setcolor(4);
  delay(400);
  beep();
  outtextxy(50,320,"Linked lists were developed in 1955 by Allen Newell, Cliff Shaw and");
  delay(1000);
  beep();
  outtextxy(30,340,"Herbert A. Simon at RAND Corporation.");
  delay(1000);
  beep();
  outtextxy(20,365,"They used it as a primary data structure for their Information Processing");
  delay(1000);
  beep();
  outtextxy(30,385,"Language (IPL). IPL was used by the authors to develop several early");
  delay(1000);
  beep();
  outtextxy(50,405,"artificial intelligence programs, including the Logic Theory Machine,");
  delay(1000);
  beep();
  outtextxy(90,425,"the General Problem Solver, and a computer chess program.");
  delay(400);
  beep();
  setcolor(13);
  for(i=66;i<=228;i++)
    outtextxy(420,i,"|");
  delay(1000);
  setcolor(12);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  for(i=450;i<=495;i+=5)
  {
    sound(100*j);
    delay(50);
    nosound();
    delay(100);
    outtextxy(i,130,"=");
    j+=5;
  }
  outtextxy(505,130,">");
  while(1)
  {
  setcolor(5);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  outtextxy(540,140,"Press 'c'");
  c=getch();
  if(c=='c')
  {
    setgraphmode(2);
    setbkcolor(6);
    setcolor(14);
    arc(320,-260,-130,-50,330);
    line(170,0,170,33);
    line(470,0,470,33);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
    delay(500);
    beep();
    outtextxy(180,1,"? WHAT'S INSIDE ?");
    setcolor(15);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
    delay(500);
    beep();
    outtextxy(10,100,"Inside the system memory, Linked List is stored in the form of a combined");
    delay(1500);
    beep();
    outtextxy(10,125,"- Node -");
    delay(1500);
    beep();
    outtextxy(85,125,"each node containing its information within, and the");
    delay(1500);
    beep();
    outtextxy(10,150,"- Link -");
    delay(1500);
    beep();
    outtextxy(85,150,"to the other nodes in the same list. This link is nothing but the");
    delay(1500);
    beep();
    outtextxy(10,175,"address of the next node residing in the memory. This arrangement");
    delay(1500);
    beep();
    outtextxy(10,200,"forms a continuous chain of Nodes, and thereby, forming a Linked List.");
    setcolor(10);
    delay(2000);
    beep();
    rectangle(50,260,100,300);
    delay(1000);
    beep();
    setcolor(14);
    line(75,280,60,354);
    delay(500);
    beep();
    ellipse(95,385,0,360,70,35);
    gotoxy(7,24);
    delay(500);
    beep();
    printf("Information");
    gotoxy(7,25);
    delay(1000);
    beep();
    printf("of the Node");
    delay(1000);
    beep();
    setcolor(10);
    rectangle(101,260,135,300);
    gotoxy(15,18);
    printf("%c%c",174,189);
    getch();
    beep();
    gotoxy(15,18);
    printf("%c ",254);
    delay(1000);
    gotoxy(18,18);
    for(i=1;i<=6;i++)
    {
      sound(500*i);
      delay(100);
      nosound();
      printf("%c",196);
      delay(50);
    }
    printf(">");
    delay(800);
    beep();
    rectangle(200,260,250,300);
    delay(800);
    beep();
    rectangle(251,260,287,300);
    delay(700);
    beep();
    gotoxy(34,18);
    printf("%c%c",174,189);
    getch();
    beep();
    gotoxy(34,18);
    printf("%c ",254);
    setcolor(14);
    delay(1000);
    beep();
    line(269,280,284,368);
    delay(500);
    beep();
    ellipse(310,410,0,360,80,45);
    delay(500);
    beep();
    setcolor(15);
    outtextxy(255,390,"Address of the");
    delay(1000);
    beep();
    outtextxy(245,405,"next Node stored");
    delay(1000);
    beep();
    outtextxy(255,420,"in the logical");
    delay(1000);
    beep();
    outtextxy(290,435,"memory");
    delay(1500);
    gotoxy(37,18);
    for(i=1;i<=6;i++)
    {
      sound(500*i);
      delay(100);
      nosound();
      printf("%c",196);
      delay(50);
    }
    printf(">");
    delay(800);
    beep();
    setcolor(10);
    rectangle(350,260,400,300);
    delay(800);
    beep();
    rectangle(401,260,439,300);
    delay(500);
    beep();
    gotoxy(53,18);
    printf("%c",254);
    gotoxy(56,18);
    for(i=1;i<=6;i++)
    {
      sound(500*i);
      delay(100);
      nosound();
      printf("%c",196);
      delay(50);
    }
    printf(">");
    delay(1000);
    beep();
    rectangle(550,260,500,300);
    delay(800);
    beep();
    rectangle(585,260,551,300);
    gotoxy(71,18);
    printf("%c%c",174,189);
    getch();
    beep();
    gotoxy(71,18);
    printf("  ");
    line(551,260,585,300);
    line(551,300,585,260);
    setcolor(14);
    delay(500);
    beep();
    circle(568,280,5);
    delay(800);
    beep();
    line(568,280,550,358);
    delay(500);
    beep();
    ellipse(532,397,0,360,88,40);
    delay(500);
    beep();
    gotoxy(63,24);
    printf("Last Node");
    delay(1000);
    beep();
    gotoxy(59,25);
    printf("referenced to NULL");
    delay(1000);
    beep();
    setcolor(15);
    outtextxy(463,404,"to terminate the");
    delay(800);
    beep();
    outtextxy(518,420,"List");
    setcolor(1);
    rectangle(510,452,800,700);
    outtextxy(520,463," Continue :->");
    getch();
    linked_list_info_2();
    return;
  }
  }
  exit();
}
void choice()
{
  int ch,color,i,x,y,xmax,ymax;
  while(1)
  {
  setgraphmode(2);
  setbkcolor(9);
  gotoxy(4,2);
  printf("%c",176);
  gotoxy(4,25);
  printf("%c",176);
  gotoxy(76,2);
  printf("%c",176);
  gotoxy(76,25);
  printf("%c",176);
  setcolor(4);
  xmax=getmaxx();
  ymax=getmaxy();
  for(i=0;i<1000;i++)
  {
    x=rand() % xmax;
    y=rand() % ymax;
    color=rand() % 12;
    putpixel(x,y,color);
  }
  rectangle(10,10,629,460);
  rectangle(140,10,515,60);
  setcolor(15);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
  delay(500);
  beep();
  outtextxy(155,15,"PROJECT AT A GLANCE");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  delay(500);
  beep();
  outtextxy(20,120,"1. DOCUMENTATION ON LINKED LISTS");
  delay(600);
  beep();
  outtextxy(20,200,"2. IMPLEMENT LINKED LIST");
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  delay(2000);
  beep();
  outtextxy(80,300,"WHAT'S");
  delay(1000);
  beep();
  outtextxy(160,300,"ON");
  delay(200);
  beep();
  outtextxy(200,300,"YOUR");
  delay(200);
  beep();
  outtextxy(270,300,"MIND ? : ");
  gotoxy(47,20);
  scanf("%d",&ch);
  if(ch==1)
    linked_list_info_1();
  else
    return;
  }
}
void load()
{
  setgraphmode(2);
  setcolor(11);
  gotoxy(4,2);
  printf("%c",176);
  gotoxy(4,25);
  printf("%c",176);
  gotoxy(76,2);
  printf("%c",176);
  gotoxy(76,25);
  printf("%c",176);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
  outtextxy(210,200,"LOADING");
  beep();
  setcolor(1);
  outtextxy(315,200," . ");
  delay(300);
  beep();
  setcolor(3);
  outtextxy(325,200," . ");
  delay(300);
  beep();
  setcolor(11);
  outtextxy(335,200," . ");
  delay(300);
  beep();
  setcolor(11);
  outtextxy(345,200," . ");
  delay(300);
  beep();
  setcolor(15);
  outtextxy(355,200," . ");
  delay(200);
  return;
}
void create_two_poly()
{
  char y;
  struct polynomial *t,*temp;
  t=rt1;
  printf("\n\tCreate the first Polynomial :-> \n");
  do
  {
    t=rt1;
    temp=(struct polynomial *)malloc(sizeof(n1));
    temp->next=NULL;
    if(rt1==NULL)
    {
      printf("\n\tEnter the info of the first term : \n\t\t");
      printf("Exponent :- ");
      scanf("%d",&temp->expo);
      printf("\n\t\tCo-efficient :- ");
      scanf("%d",&temp->coeff);
      rt1=temp;
      printf("\n\tFirst Term added !");
      printf("\n\n\tPress 'y' to add more Terms or 'p' to create another Polynomial ...");
      y=getch();
    }
    else
    {
      printf("\n\tEnter the info of the term : \n\t\t");
      printf("Exponent :- ");
      scanf("%d",&temp->expo);
      printf("\n\t\tCo-efficient :- ");
      scanf("%d",&temp->coeff);
      while(t->next!=NULL)
	t=t->next;
      t->next=temp;
      printf("\n\tNew Term added !");
      printf("\n\n\tPress 'y' to add more Terms or 'p' to create another Polynomial ...");
      y=getch();
    }
  }while(y=='y');
  t=rt2;
  printf("\n\n\tCreate the second Polynomial :-> \n");
  do
  {
    t=rt2;
    temp=(struct polynomial *)malloc(sizeof(n1));
    temp->next=NULL;
    if(rt2==NULL)
    {
      printf("\n\tEnter the info of the first term : \n\t\t");
      printf("Exponent :- ");
      scanf("%d",&temp->expo);
      printf("\n\t\tCo-efficient :- ");
      scanf("%d",&temp->coeff);
      rt2=temp;
      printf("\n\tFirst Term added !");
      printf("\n\n\tPress 'y' to add more Terms or 'p' to create another Polynomial ...");
      y=getch();
    }
    else
    {
      printf("\n\tEnter the info of the term : \n\t\t");
      printf("Exponent :- ");
      scanf("%d",&temp->expo);
      printf("\n\t\tCo-efficient :- ");
      scanf("%d",&temp->coeff);
      while(t->next!=NULL)
	t=t->next;
      t->next=temp;
      printf("\n\tNew Term added !");
      printf("\n\n\tPress 'y' to add more Terms or 'r' to return ...");
      y=getch();
    }
  }while(y=='y');
  return;
}
/*void add_polynomial(struct polynomial *rt1,struct polynomial *rt2)
{
  int a=0;
  struct polynomial *t,*p,*temp;
  t=rt1;
  p=rt2;
  if(t->expo>p->expo)
  {
    while(t!=NULL||p!=NULL)
    {
      if(p->expo==t->expo)
      {
	a++;
	if(rt3==NULL)
	{
	  rt3=create_poly(rt3);
	  rt3->coeff=p->coeff+t->coeff;
	  rt3->expo=p->expo;
	}
	else
	{
	  temp=create_poly(rt3);
	  rt3->coeff=p->coeff+t->coeff;
	  rt3->expo=p->expo;
	}
	p=p->next;
      }
      else
      {
	if(t->expo<p->expo)
	{
	  if(t->expo==p->expo)
	  {
	    a++;
	   if(rt3==NULL)
	{
	  rt3=create_poly(rt3);
	  rt3->coeff=p->coeff+t->coeff;
	  rt3->expo=p->expo;
	}
	else
	{
	  temp=create_poly(rt3);
	  rt3->coeff=p->coeff+t->coeff;
	  rt3->expo=p->expo;
	}  */

void disp_polynomial(struct polynomial *rt)
{
  struct polynomial *t;
  t=rt;
  if(rt==NULL)
  {
    printf("\n\tPolynomial does not exists !");
    ctr++;
    return;
  }
  while(t!=NULL)
  {
    if(t->next==NULL)
    {
      printf("%d|%d",t->coeff,t->expo);
      return;
    }
    printf("%d|%d --> ",t->coeff,t->expo);
    t=t->next;
  }
  return;
}
void static_push()
{
  int item;
  if(stk.top==9)
  {
    printf("\n\tOverflow ! No more elements can be pushed !");
    return;
  }
  printf("\n\tEnter the element to be pushed into the Stack : ");
  scanf("%d",&item);
  stk.top++;
  stk.s[stk.top]=item;
  printf("\n\tElement %d pushed into the Stack !",item);
  return;
}
void dynamic_push()
{
  struct link *temp;
  temp=(struct link *)malloc(sizeof(node));
  printf("\n\tEnter the element to be pushed : ");
  scanf("%d",&temp->info);
  beep();
  temp->next=NULL;
  if(root1==NULL)
  {
    root1=temp;
    root1->next=NULL;
    beep();
    printf("\n\tElement %d pushed in the Stack !",temp->info);
    return;
  }
  temp->next=root1;
  root1=temp;
  beep();
  printf("\n\tElement %d pushed in the Stack !",temp->info);
  return;
}
void static_pop()
{
  int item;
  if(stk.top==-1)
  {
    printf("\n\tUnderflow ! No element can be popped !");
    return;
  }
  item=stk.s[stk.top];
  stk.top--;
  printf("\n\tStack Top : %d popped !",item);
  return;
}
void dynamic_pop()
{
  struct link *t;
  t=root1;
  if(root1==NULL)
  {
    printf("\n\tUnderflow ! No element can be popped !");
    return;
  }
  root1=root1->next;
  printf("\n\tStack Top : %d popped !",t->info);
  beep();
  free(t);
  return;
}
void dynamic_peep()
{
  if(root1==NULL)
  {
    printf("\n\tUnderflow ! Stack Top does not exists !");
    return;
  }
  beep();
  printf("\n\tStack Top : %d ",root1->info);
  return;
}
int static_peep()
{
  int item;
  if(stk.top==-1)
  {
    printf("\n\tUnderflow ! Stack Top does not exists !");
    return 0;
  }
  item=stk.s[stk.top];
  return item;
}
void traverse_stk()
{
  int i;
  if(stk.top==-1)
  {
    printf("\n\tUnderflow ! Stack cannot be traversed !");
    return;
  }
  printf("\n\tThe Stack is => \n\n");
  for(i=stk.top;i>=0;i--)
  {
    printf("\t\t\t\t %c%c%c%c\n",196,196,196,196);
    printf("\t\t\t\t%c %d %c\n",179,stk.s[i],179);
    printf("\t\t\t\t %c%c%c%c\n",196,196,196,196);
    if(i!=0)
      printf("\t\t\t\t  %c\n",215);
  }
}
void sort_create_linear()
{
  struct link *t,*temp;
  t=root1;
  if(root1==NULL)
  {
    root1=(struct link *)malloc(sizeof(node));
    printf("\n\tEnter the new node info : ");
    scanf("%d",&root1->info);
    root1->next=NULL;
    printf("\n\tFirst Node created !");
    return;
  }
  temp=(struct link *)malloc(sizeof(node));
  printf("\n\tEnter the new node info : ");
  scanf("%d",&temp->info);
  if(root1->next==NULL)   // Insertion of Sorted Node when only one root Node exists
  {
    /* Adding After the root node */
       if(root1->info<=temp->info)
       {
	 root1->next=temp;
	 temp->next=NULL;
	 printf("\n\tNode %d added after %d in the Sorted List !",temp->info,root1->info);
	 return;
       }
    /* Adding Before the root node */
       if(root1->info>temp->info)
       {
	 temp->next=root1;
	 root1->next=NULL;
	 root1=temp;
	 printf("\n\tNode %d added before %d in the sorted List !",temp->info,t->info);
	 return;
       }
  }
  if(root1->info>temp->info)    // Insertion before the root node, when multiple nodes exist
  {
    temp->next=root1;
    root1=temp;
    printf("\n\tNode %d added before %d in the sorted list !",temp->info,t->info);
    return;
  }
  while(t->next->info<temp->info)  // Insertion in sorted order anywhere else
  {
    if(t->next==NULL)
    {
      temp->next=NULL;
      t->next=temp;
      printf("\n\tNode %d added after %d in the sorted list !",temp->info,t->info);
      return;
    }
    t=t->next;
  }
  temp->next=t->next;
  t->next=temp;
  printf("\n\tNode %d added after %d in the sorted list !",temp->info,t->info);
}
void reverse_linear()
{
  int a=0,b=0,i;
  struct link *t,*p,*s;
  t=p=root1;
  if(root1==NULL)
  {
    ctr++;
    error();
    return;
  }
  while(t->next!=NULL)
  {
    t=t->next;
    a++;
  }
  if(a!=0)
    t=root1;
  else
  {
    printf("\n\tOnly one Node exists !");
    return;
  }
  for(i=1;i<=a;i++)
  {
    if(b==0)
    {
      while(t->next!=NULL)
      {
	p=t;
	t=t->next;
      }
      t->next=p;
      s=t;
      t=p;
      p=root1;
      if(t==root1)
      {
	t->next=NULL;
	root1=s;
	printf("\n\tThe Reversed Linked List is => \n\n");
	return;
      }
      b++;
    }
    else
    {
      while(p->next!=t)
	p=p->next;
      t->next=p;
      t=p;
      p=root1;
      if(t==root1)
      {
	t->next=NULL;
	root1=s;
	printf("\n\tThe Reversed Linked List is => \n\n");
	return;
      }
    }
  }
}
void alternate_sep_linear()
{
  int a=0,c=0;
  struct link *t,*p,*s;
  t=p=root1;
  if(root1==NULL)
  {
    printf("\n\tLinked List does not exists !");
    return;
  }
  if(root1->next==NULL)
  {
    printf("\n\tSingle Node %d cannot be seperated alternatively !",root1->info);
    return;
  }
  if(root1->next->next==NULL)
  {
    root2=root1->next;
    root1->next=NULL;
    root2->next=NULL;
    ctr++;
    return;
  }
  while(1)
  {
    if(a%2==0)
    {
      if(t->next->next==NULL||t->next==NULL) // OR is true in case of 3 nodes
      {
	t->next=NULL;
	break;
      }
      p=t->next;
      if(c==0)
      {
	s=p;
	c++;
      }
      t->next=t->next->next;
      t=t->next;
      a++;
    }
    else
    {
      if(p->next->next==NULL)
      {
	p->next=NULL;
	break;
      }
      p->next=p->next->next;
      p=p->next;
      a++;
    }
  }
  root2=s;
  ctr++;
  return;
}
struct link * merge_sort_linear(struct link *rt1,struct link *rt2)
{
  struct link *t,*p,*s,*q;
  t=rt1;
  s=p=rt2;
  if(rt1==NULL)
  {
    if(rt2==NULL)
    {
      printf("\n\tNo Lists exist !");
      return rt1;
    }
    else
    {
      printf("\n\tList 1 does not exists !");
      return rt1;
    }
  }
  if(rt2==NULL)
  {
    printf("\n\tList 2 does not exists !");
    return rt1;
  }
  while(s!=NULL)
  {
    if(p->info>t->info)
    {
      if(t->next==NULL)
      {
	t->next=p;
	s=p=p->next;
	t->next->next=NULL;
	t=rt1;
	continue;
      }
      q=t;
      t=t->next;
    }
    else
    {
      if(t==rt1)
      {
	s=p->next;
	p->next=rt1;
	t=rt1=p;
	p=s;
      }
      else
      {
	s=p->next;
	p->next=t;
	q->next=p;
	p=s;
	t=rt1;
      }
    }
  }
  printf("\n\tThe Merged Lists in sorted order are => \n\n");
  return rt1;
}
struct link * concate_linear(struct link *rt1,struct link *rt2)
{
  struct link *t;
  t=rt1;
  if(rt1==NULL)
  {
    if(rt2==NULL)
    {
      printf("\n\tNo Lists exist !");
      return rt1;
    }
    else
    {
      printf("\n\tList 1 does not exists !");
      return rt1;
    }
  }
  if(rt2==NULL)
  {
    printf("\n\tList 2 does not exists !");
    return rt1;
  }
  while(t->next!=NULL)
    t=t->next;
  t->next=rt2;
  return rt1;
}
void create_linear()
{
  struct link *temp,*t;
  t=root1;
  temp=(struct link *)malloc(sizeof(node));
  printf("\n\tEnter the information of the node : ");
  scanf("%d",&temp->info);
  temp->next=NULL;
  if(root1==NULL)
  {
    root1=temp;
    return;
  }
  while(t->next!=NULL)
    t=t->next;
  t->next=temp;
}
void create_two_linear()
{
  char y;
  struct link *t,*temp;
  t=root1;
  printf("\n\tCreate List 1 :-> \n");
  do
  {
    t=root1;
    temp=(struct link *)malloc(sizeof(node));
    printf("\n\tEnter the information of the node : ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(root1==NULL)
    {
      root1=temp;
      printf("\n\tFirst Node created !");
      printf("\n\n\tPress 'y' to to create more Nodes or 'n' to create another list ...");
      y=getch();
    }
    else
    {
      while(t->next!=NULL)
	t=t->next;
      t->next=temp;
      printf("\n\tNew Node %d added !",temp->info);
      printf("\n\n\tPress 'y' to to create more Nodes or 'n' to create another list ...");
      y=getch();
    }
  }while(y=='y');
  t=root2;
  printf("\n\n\tCreate List 2 :-> \n");
  do
  {
    t=root2;
    temp=(struct link *)malloc(sizeof(node));
    printf("\n\tEnter the information of the node : ");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(root2==NULL)
    {
      root2=temp;
      printf("\n\tFirst Node created !");
      printf("\n\n\tPress 'y' to to create more Nodes or any other key to Exit ...");
      y=getch();
    }
    else
    {
      while(t->next!=NULL)
	t=t->next;
      t->next=temp;
      printf("\n\tNew Node %d added !",temp->info);
      printf("\n\n\tPress 'y' to to create more Nodes or any other key to Exit ...");
      y=getch();
    }
  }while(y=='y');
  return;
}
void create_circular()
{
  struct link *temp,*t;
  t=root2;
  temp=(struct link *)malloc(sizeof(node));
  printf("\n\tEnter the information of the node : ");
  scanf("%d",&temp->info);
  if(root2==NULL)
  {
    root2=temp;
    root2->next=root2;
    printf("\n\tNode created and Circular List inititated !");
    return;
  }
  while(t->next!=root2)
    t=t->next;
  t->next=temp;
  temp->next=root2;
  printf("\n\tNode added in the Circular List");
}
void create_doubly()
{
  struct doubly_list *t;
  t=root;
  if(root==NULL)
  {
    root=(struct doubly_list *)malloc(sizeof(n));
    printf("\n\tEnter the info of the node : ");
    scanf("%d",&root->info);
    root->next=root->prev=NULL;
    printf("\n\tNode %d created and Doubly Linked List inititated !",root->info);
    return;
  }
  while(t->next!=NULL)
    t=t->next;
  t->next=(struct doubly_list *)malloc(sizeof(node));
  printf("\n\tEnter the new node info : ");
  scanf("%d",&t->next->info);
  t->next->next=NULL;
  printf("\n\tNew Node %d added in the Doubly List !",t->next->info);
}
void create_doubly_cir()
{
  struct doubly_list *t;
  t=root;
  if(root==NULL)
  {
    root=(struct doubly_list *)malloc(sizeof(n));
    printf("\n\tEnter the new node info : ");
    scanf("%d",&root->info);
    root->next=root->prev=root;
    printf("\n\tFirst Node created and Double Circular List initiated !");
    return;
  }
  while(t->next!=root)
    t=t->next;
  t->next=(struct doubly_list *)malloc(sizeof(n));
  printf("\n\tEnter the new node info : ");
  scanf("%d",&t->next->info);
  t->next->prev=t;
  t->next->next=root;
  root->prev=t->next;
  printf("\n\tNode %d added in the list !",t->next->info);
}
void add_after_linear()
{
  int pos;
  struct link *temp,*t;
  t=root1;
  if(root1==NULL)
  {
    printf("\n\tLinked List is not present !");

    return;
  }
  printf("\n\tEnter the node after which a new node is to be added : ");
  scanf("%d",&pos);
  while(t->info!=pos)
  {
    if(t->next==NULL)
    {
      beep();
      printf("\n\t\tNode not present in the list : ");
      ctr++;
      getch();
      return;
    }
    t=t->next;
  }
  temp=(struct link *)malloc(sizeof(node));
  printf("\n\tEnter the information of the new node : ");
  scanf("%d",&temp->info);
  temp->next=t->next;
  t->next=temp;
  printf("\n\t\tNode added in the list after %d",pos);
}
void add_after_circular()
{
  int pos;
  struct link *temp,*t;
  t=root2;
  if(root2==NULL)
  {
    printf("\n\tCircular List does not exists !");
    return;
  }
  printf("\n\tEnter the node after which a new node is to be added : ");
  scanf("%d",&pos);
  while(t->info!=pos)
  {
    if(t->next==NULL)
    {
      printf("\n\tNode is not present in the list !");
      return;
    }
    t=t->next;
  }
  temp=(struct link *)malloc(sizeof(node));
  printf("\n\tEnter the new node information : ");
  scanf("%d",&temp->info);
  temp->next=t->next;
  t->next=temp;
  printf("\n\tNode added after %d !",pos);
}
void add_after_doubly()
{
  int a=0,val;
  struct doubly_list *t,*temp;
  t=root;
  if(root==NULL)
  {
    printf("\n\tDoubly List does not exists !");
    return;
  }
  while(t->next!=NULL)
  {
    t=t->next;
    a++;
  }
  if(a==0)
  {
    temp=(struct doubly_list *)malloc(sizeof(n));
    printf("\n\tEnter the new node info : ");
    scanf("%d",&temp->info);
    t->next=temp;
    temp->next=NULL;
    printf("\n\tNode added after %d !",t->info);
    return;
  }
  else
    t=root;
  printf("\n\tEnter the node after which insertion is to be done : ");
  scanf("%d",&val);
  temp=(struct doubly_list *)malloc(sizeof(n));
  printf("\n\tEnter the new node info : ");
  scanf("%d",&temp->info);
  while(t->info!=val)
    t=t->next;
  temp->next=t->next;
  temp->prev=t;
  t->next->prev=temp;
  t->next=temp;
  printf("\n\tNew Node added after %d !",t->info);
}
void add_after_doubly_cir()
{
  int val,a=0;
  struct doubly_list *t,*temp;
  t=root;
  if(root==NULL)
  {
    printf("\n\tDoubly Circular List does not exists !");
    return;
  }
  while(t->next!=root)
  {
    t=t->next;
    a++;
  }
  if(a==0)
  {
    root->next=(struct doubly_list *)malloc(sizeof(n));
    printf("\n\tEnter the new node info : ");
    scanf("%d",&root->next->info);
    root->next->prev=root->next->next=root;
    root->prev=root->next;
    printf("\n\tNode %d added after %d !",root->next->info,root->info);
    return;
  }
  else
    t=root;
  printf("\n\tEnter the Node after which insertion is to be done : ");
  scanf("%d",&val);
  while(t->info!=val)
    t=t->next;
  temp=(struct doubly_list *)malloc(sizeof(n));
  printf("\n\tEnter the new node info : ");
  scanf("%d",&temp->info);
  temp->next=t->next;
  temp->prev=t;
  t->next->prev=temp;
  t->next=temp;
  printf("\n\tNode %d added after %d !",temp->info,t->info);
}
void add_before_linear()
{
  int pos,a=0;
  struct link *temp,*p,*t;
  t=root1;
  if(root1==NULL)
  {
    printf("\n\tLinked List does not exists ! ");
    return;
  }
  while(t->next!=NULL)
  {
    t=t->next;
    a++;
  }
  if(a==0)
  {
    temp=(struct link *)malloc(sizeof(node));
    printf("\n\t\t\tEnter the new node info : ");
    scanf("%d",&temp->info);
    temp->next=root1;
    root1=temp;
    printf("\n\t\t\tNew Node added before %d !",t->info);
    return;
  }
  else
    t=root1;
  printf("\n\tEnter the value before which the node is to be inserted : ");
  scanf("%d",&pos);
  while(t->info!=pos)
  {
    if(t->next==NULL)
    {
      beep();
      printf("\n\tNode not present in the list !");
      ctr++;
      getch();
      return;
    }
    p=t;
    t=t->next;
  }
  if(t==root1)
  {
    temp=(struct link *)malloc(sizeof(node));
    printf("\n\tEnter the information of the new node : ");
    scanf("%d",&temp->info);
    temp->next=root1;
    root1=temp;
  }
  else
  {
    temp=(struct link *)malloc(sizeof(node));
    printf("\n\tEnter the information of the new node : ");
    scanf("%d",&temp->info);
    temp->next=t;
    p->next=temp;
  }
  printf("\n\t\tNode added in the list after %d !",pos);
}
void add_before_circular()
{
  int pos,a=0;
  struct link *temp,*t,*p;
  t=root2;
  if(root2==NULL)
  {
    printf("\n\tCircular List does not exists !");
    return;
  }
  while(t->next!=root2)
  {
    t=t->next;
    a++;
  }
  if(a==0)
  {
    temp=(struct link *)malloc(sizeof(node));
    printf("\n\t\t\tEnter the new node info : ");
    scanf("%d",&temp->info);
    temp->next=root2;
    root2->next=temp;
    root2=temp;
    printf("\n\t\t\tNew Node added before %d !",t->info);
    return;
  }
  else
    t=root2;
  printf("\n\tEnter the node before which a new node is to be created : ");
  scanf("%d",&pos);
  while(t->info!=pos)
  {
    if(t->next==NULL)
    {
      printf("\n\tNode does not exists !");
      return;
    }
    p=t;
    t=t->next;
  }
  temp=(struct link *)malloc(sizeof(node));
  printf("\n\tEnter the new node information : ");
  scanf("%d",&temp->info);
  if(t==root2)
  {
    while(t->next!=root2)
      t=t->next;
    t->next=temp;
    temp->next=root2;
    root2=temp;
  }
  else
  {
    temp->next=t;
    p->next=temp;
  }
  printf("\n\tNode added in the list before %d !",pos);
}
void add_before_doubly()
{
  int a=0,val;
  struct doubly_list *t,*temp;
  t=root;
  if(root==NULL)
  {
    printf("\n\tDoubly List does not exists !");
    return;
  }
  while(t->next!=NULL)
  {
    t=t->next;
    a++;
  }
  if(a==0)
  {
    t->prev=(struct doubly_list *)malloc(sizeof(n));
    printf("\n\tEnter the new node info : ");
    scanf("%d",&t->prev->info);
    t->prev->next=root;
    t->prev->prev=NULL;
    root=t->prev;
    printf("\n\tNode added before %d !",t->info);
    return;
  }
  else
    t=root;
  printf("\n\tEnter the value before which insertion is to be done : ");
  scanf("%d",&val);
  temp=(struct doubly_list *)malloc(sizeof(n));
  printf("\n\tEnter the new node info : ");
  scanf("%d",&temp->info);
  while(t->next->info!=val)
    t=t->next;
  temp->next=t->next;
  temp->prev=t;
  t->next->prev=temp;
  t->next=temp;
  printf("\n\tNew Node added before %d !",val);
}
void add_before_doubly_cir()
{
  int val,a=0;
  struct doubly_list *t,*temp;
  t=root;
  if(root==NULL)
  {
    printf("\n\tDoubly Circular List does not exists !");
    return;
  }
  while(t->next!=root)
  {
    t=t->next;
    a++;
  }
  if(a==0)
  {
    root->prev=(struct doubly_list *)malloc(sizeof(n));
    printf("\n\tEnter the new node info : ");
    scanf("%d",&root->prev->info);
    root->prev->next=root->prev->prev=root;
    root->next=root->prev;
    root=root->prev;
    printf("\n\tNode %d added before %d !",root->info,root->next->info);
    return;
  }
  else
    t=root;
  printf("\n\tEnter the node before which insertion is to be done : ");
  scanf("%d",&val);
  temp=(struct doubly_list *)malloc(sizeof(n));
  printf("\n\tEnter the new node info : ");
  scanf("%d",&temp->info);
  if(root->info==val)
  {
    temp->next=root;
    temp->prev=root->prev;
    root->prev->next=temp;
    root->prev=temp;
    root=temp;
    printf("\n\tNode %d added before %d !",root->info,root->next->info);
    return;
  }
  while(t->next->info!=val)
    t=t->next;
  temp->next=t->next;
  temp->prev=t;
  t->next->prev=temp;
  t->next=temp;
  printf("\n\tNode %d added before %d !",temp->info,temp->next->info);
}
void del_linear()
{
  int val,a=0;
  struct link *t,*p;
  t=root1;
  if(root1==NULL)
  {
    error();
    return;
  }
  while(t->next!=NULL)      // Used to find out the number of nodes
  {
    t=t->next;
    a++;
  }
  if(a==0)                  // Direct Deletion if only one node exists
  {
    root1=NULL;
    free(root1);
    printf("\n\tExisting node %d deleted !",t->info);
    return;
  }
  else     // Reset 't' to 'root' as it has been updated if more than one node exists
    t=root1;
  printf("\n\tEnter the node to be deleted : ");
  scanf("%d",&val);
  while(t->info!=val)
  {
    if(t->next==NULL)
    {
      printf("\n\tNode is not present in the linear linked list!");
      ctr++;
      getch();
      return;
    }
    p=t;
    t=t->next;
  }
  if(t==root1)
  {
    root1=t->next;
    free(t);
  }
  else
  {
    p->next=t->next;
    free(t);
  }
  printf("Node %d has been deleted !",val);
}
void del_circular()
{
  int val,a=0;
  struct link *t,*p;
  t=root2;
  if(root2==NULL)
  {
    error();
    return;
  }
  while(t->next!=root2)      // Used to find out the number of nodes
  {
    t=t->next;
    a++;
  }                          // Direct Deletion if only one node exists
  if(a==0)
  {
    root2=NULL;
    free(root2);
    printf("\n\tExisting node %d deleted !",t->info);
    return;
  }
  else     // Reset 't' to 'root' as it has been updated if more than one node exists
    t=root2;
  printf("\n\tEnter the node to be deleted : ");
  scanf("%d",&val);
  while(t->info!=val)
  {
    if(t->next==root2)
    {
      printf("\n\tNode not present in the circular list !");
      return;
    }
    p=t;
    t=t->next;
  }
  if(t->next==root2)     //Deletion if only one node is present
  {
    root2=NULL;
    free(root2);
    printf("\n\tNode %d has been deleted !",val);
    return;
  }
  if(t==root2)          // Deletion if the node to be deleted is the root node
  {
    while(t->next!=root2)
      t=t->next;
    t->next=root2->next;
    root2=t->next;
  }
  else               // Deletion if the node to be deleted is other than root
  {
    p->next=t->next;
    free(t);
  }
  printf("\n\tNode %d has been deleted !",val);
}
void del_doubly()
{
  int val,a=0;
  struct doubly_list *t;
  t=root;
  if(root==NULL)
  {
    error();
    return;
  }
  while(t->next!=NULL)
  {
    t=t->next;
    a++;
  }
  if(a==0)
  {
    root=NULL;
    free(root);
    printf("\n\tExisting node %d deleted !",t->info);
    return;
  }
  else
    t=root;
  printf("\n\tEnter the node to be deleted : ");
  scanf("%d",&val);
  if(t->info==val)
  {
    t->next->prev=NULL;
    root=t->next;
    free(t);
    printf("\n\tNode %d deleted !",val);
    return;
  }
  while(t->next->info!=val)
    t=t->next;
  t->next=t->next->next;
  t->next->prev=t;
  printf("\n\tNode %d deleted !",val);
}
void del_doubly_cir()
{
  int a=0,val;
  struct doubly_list *t;
  t=root;
  if(root==NULL)
  {
    error();
    return;
  }
  while(t->next!=root)
  {
    t=t->next;
    a++;
  }
  if(a==0)
  {
    root=NULL;
    free(root);
    printf("\n\tExisting Node %d deleted !",t->info);
    return;
  }
  else
    t=root;
  printf("\n\tEnter the Node to be deleted : ");
  scanf("%d",&val);
  if(root->info==val)
  {
    root->next->prev=root->prev;
    root->prev->next=root->next;
    root=root->next;
    free(t);
    printf("\n\tNode %d deleted !",val);
    return;
  }
  while(t->next->info!=val)
    t=t->next;
  t->next=t->next->next;
  t->next->prev=t;
  printf("\n\tNode %d deleted !",val);
}
void nth_occurence()
{
  int val,occ,temp=0;
  struct link *t,*p;
  t=root1;
  p=root1;
  if(root1==NULL)
  {
    printf("\n\tList does not exists !");
    return;
  }
  printf("\n\tEnter the node whose occurence is to deleted : ");
  scanf("%d",&val);
  printf("\n\tEnter the occurence of %d to be deleted : ",val);
  scanf("%d",&occ);
  if(root1->info==val&&occ==1)
  {
    t=root1->next;
    free(root1);
    root1=t;
    p=root1;
  }
  while(t!=NULL)
  {
    if(t->info==val)
    {
      temp++;
      if(temp==occ)
      {
	p->next=t->next;
	free(t);
      }
    }
    p=t;
    t=t->next;
  }
  printf("\n\tNode %d occurence number %d deleted ! ",val,occ);
}
void del_allsimilar()
{
  int val;
  struct link *t,*p;
  p=t=root1;
  if(root1==NULL)
  {
    printf("\n\tList does not exists !");
    return;
  }
  printf("\n\tEnter the node to be deleted entirely from the list : ");
  scanf("%d",&val);
  while(t!=NULL)
  {
    if(t->info==val)
    {
      if(root1->info==val)
      {
	t=root1->next;
	free(root1);
	root1=t;
	p=root1;
	continue;
      }
      p->next=t->next;
      free(t);
      t=p;
      if(t->next==NULL)
	break;
      continue;
    }
    p=t;
    t=t->next;
  }
  printf("\n\tAll nodes with info %d deleted !",val);
}
void del_duplicate()
{
  int val,temp=0;
  struct link *t,*p;
  t=p=root1;
  if(root1==NULL)
  {
    printf("\n\tList does not exists !");
    return;
  }
  printf("\n\tEnter the node whose duplicates need to be deleted : ");
  scanf("%d",&val);
  while(t!=NULL)
  {
    if(t->info==val)
    {
      temp++;
      if(temp>1)
      {
	p->next=t->next;
	free(t);
	t=p;
	ctr=1;
	continue;
      }
    }
    p=t;
    t=t->next;
  }
  if(temp==1)
  {
    printf("\n\tNo duplicates of %d are present in the list !",val);
    return;
  }
  printf("\n\tAll duplicates of %d deleted !",val);
}
void nth_after_before()
{
  int a=0,pos,occ,ch,temp1=0;
  struct link *t,*p,*temp;
  t=p=root1;
  if(root1==NULL)
  {
    printf("\n\tList does not exists !");
    return;
  }
  printf("\n\tEnter the node at whose nth occurence, insertion is to be done : ");
  scanf("%d",&pos);
  printf("\n\tEnter the occurence where insertion is to be done : ");
  scanf("%d",&occ);
  while(t!=NULL)
  {
    if(t->info==pos)
    {
      temp1++;
      if(temp1==occ)
      {
	a++;
	printf("\n\tSpecify the type of insertion => 1. After \n\t\t\t\t\t 2. Before \n\t\t\t\t\t\t   Enter here : ");
	scanf("%d",&ch);
	switch(ch)
	{
	  case 1:temp=(struct link *)malloc(sizeof(node));
		 printf("\n\tEnter the new node information : ");
		 scanf("%d",&temp->info);
		 temp->next=t->next;
		 t->next=temp;
		 printf("\n\tNew Node added after occurence %d of %d !",occ,pos);
		 return;
	  case 2:temp=(struct link *)malloc(sizeof(node));
		 printf("\n\tEnter the new node information : ");
		 scanf("%d",&temp->info);
		 if(t==root1)
		 {
		   temp->next=root1;
		   root1=temp;
		   printf("\n\tNew Node added before occurence %d of %d !",occ,pos);
		   return;
		 }
		 else
		 {
		   temp->next=t;
		   p->next=temp;
		   printf("\n\tNew Node added before occurence %d of %d !",occ,pos);
		   return;
		 }
	}
      }
    }
    p=t;
    t=t->next;
  }
  if(a==0)
  {
    printf("\n\tOccurence %d not found for %d in the list !",occ,pos);
    return;
  }
}
void create_twopointers()
{
  struct link *t;
  t=root1;
  if(root1==NULL)
  {
    root1=(struct link *)malloc(sizeof(node));
    root1->next=NULL;
    printf("\n\t\t\tEnter the new node info : ");
    scanf("%d",&root1->info);
    printf("\n\t\t\tFirst Node Created in the list !");
    return;
  }
  while(t->next!=NULL)
    t=t->next;
  t->next=(struct link *)malloc(sizeof(node));
  t->next->next=NULL;
  printf("\n\t\t\tEnter the new node info : ");
  scanf("%d",&t->next->info);
  printf("\n\t\t\tNew Node added in the list !");
}
void add_bef_twopointers()
{
  int pos,a=0,i,b=0;
  struct link *t,*temp;
  t=root1;
  if(root1==NULL)
  {
    printf("\n\t\t\tList does not exists !");
    return;
  }
  while(t->next!=NULL)
  {
    t=t->next;
    b++;
  }
  if(b==0)
  {
    temp=(struct link *)malloc(sizeof(node));
    printf("\n\t\t\tEnter the new node info : ");
    scanf("%d",&temp->info);
    temp->next=root1;
    root1=temp;
    printf("\n\t\t\tNew Node added before %d !",t->info);
    return;
  }
  else
    t=root1;
  printf("\n\t\t\tEnter the node before which insertion is to be done : ");
  scanf("%d",&pos);
  while(t->info!=pos)
  {
    if(t->next==NULL)
    {
      beep();
      printf("\n\t\t\tNode not present in the list !");
      ctr++;
      getch();
      return;
    }
    t=t->next;
    a++;
  }
  temp=(struct link *)malloc(sizeof(node));
  printf("\n\t\t\tEnter the new node info : ");
  scanf("%d",&temp->info);
  if(t==root1)
  {
    temp->next=root1;
    root1=temp;
    printf("\n\t\t\tNew Node added before %d !",pos);
    return;
  }
  else
  {
    temp->next=t;
    t=root1;
    for(i=1;i<a;i++)
      t=t->next;
    t->next=temp;
    printf("\n\t\t\tNew Node added before %d !",pos);
  }
}
void del_twopointers()
{
  int val,a=0;
  struct link *t;
  t=root1;
  if(root1==NULL)
  {
    printf("\n\t\t\tList does not Exists !");
    return;
  }
  while(t->next!=NULL)     // To count the number of nodes in the list
  {
    t=t->next;
    a++;
  }                       // If no. of nodes =1 => directly delete it
  if(a==0)
  {
    root1=NULL;
    free(root1);
    printf("\n\t\t\tThe existing Node %d deleted !",t->info);
    return;
  }
  else   // If no. of nodes !=1 => reset 't' to root and ask the user which node to delete
    t=root1;
  printf("\n\t\t\tEnter the Node to be deleted : ");
  scanf("%d",&val);
  if(t->info==val)        // If node to be deleted is the root node
  {
    root1=t->next;
    printf("\n\t\t\tNode %d deleted !",val);
    return;
  }
  while(t->next->info!=val)
  {
    if(t->next==NULL)
    {
      beep();
      printf("\n\tNode not present in the List !");
      ctr++;
      getch();
      return;
    }
    t=t->next;
  }
  t->next=t->next->next;
  printf("\n\t\t\tNode %d has been deleted !",val);
}
void disp_linear(struct link *rt)
{
  struct link *t;
  t=rt;
  if(stck==1)
  {
    while(t!=NULL)
    {
      printf("\t\t\t\t %c%c%c%c\n",196,196,196,196);
      printf("\t\t\t\t%c %d %c\n",179,t->info,179);
      printf("\t\t\t\t %c%c%c%c\n",196,196,196,196);
      if(t->next!=NULL)
	arrow();
	//printf("\t\t\t\t  %c\n",215);
      t=t->next;
    }
    return;
  }
  if(rt==NULL)
  {
    error();
    return;
  }
  printf("\n\n\n\t\tThe Linear Linked List is => \n\n\n\n\t");
  while(t!=NULL)
  {
    printf(" %d ",t->info);
    if(t->next!=NULL)
      arrow();
    t=t->next;
  }
  beep();
}
void disp_circular()
{
  struct link *t;
  t=root2;
  if(root2==NULL)
  {
    error();
    return;
  }
  printf("\n\n\n\t\tThe Circular List is =>\n\n\n\n\t");
  do   // do-while is used here instead of while as in while, the traversal condition ' t!=root ' is false
  {
    printf(" %d\t",t->info);
    t=t->next;
    if(t!=root2)
      arrow();
  }while(t!=root2);
}
void disp_doubly()
{
  struct doubly_list *t;
  t=root;
  if(root==NULL)
  {
    error();
    return;
  }
  printf("\n\tThe Doubly Linked List is => \n\n");
  do
  {
    printf(" %d\t",t->info);
    t=t->next;
  }while(t!=root);
}
void disp_doubly_cir()
{
  struct doubly_list *t;
  t=root;
  if(root==NULL)
  {
    error();
    return;
  }
  printf("\n\tThe Doubly Circular Linked List is => \n\n");
  do
  {
    printf(" %d\t",t->info);
    t=t->next;
  }while(t!=root);
}
void add_freq(int n)
{
  int i,j;
  screen(n,0);
  textcolor(15);
  printf("\n\n\n\n\n\t! Creating the Node in the List ");
  for(i=1;i<20;i++)
  {
    sound(500*i);
    delay(20);
    nosound();
    delay(50);
    printf("-");
  }
  printf(">");
}
void del_freq(int n)
{
  int i,j;
  screen(n,0);
  textcolor(15);
  printf("\n\n\n\n\n\tWait .. Lemme Find and Delete this Node ");
  for(i=1;i<20;i++)
  {
    sound(500*i);
    delay(70);
    nosound();
    delay(50);
    printf(".");
  }
}
void main()
{
  int i,ch1,ch2,ch3,c,val,b=0,gd=DETECT,gm;
  char p,a,d,y,f;
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  stk.top=-1;
  clrscr();
  startup();
  choice();
  load();
  setgraphmode(2);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  setbkcolor(3);
  draw_bk();
  setcolor(4);
  delay(500);
  beep();
  outtextxy(5,10,"<- LINKED LIST IMPLEMENTATION WITH STACK OPERATIONS ->");
  delay(500);
  beep();
  printf("\n\n\n\n\n\n\t\t%c Specify the type of Linked List to operate %c",176,176);
  setcolor(10);
  ellipse(310,105,0,360,210,30);
  delay(800);
  beep();
  printf("\n\n\n\n\n\t1. Linear Linked List ");delay(800);beep();
  printf("\t\t2. Circular Linked List");delay(800);beep();
  printf("\n\n\n\n\n\t3. Doubly Linked List");delay(800);beep();
  printf("\t\t4. Circular Doubly Linked List");delay(800);beep();
  printf("\n\n\n\n\n\t5. Static Stack Opeartions");delay(800);beep();
  printf("\t6. Exit");delay(800);beep();
  printf("\n\n\n\n\t\t\t%c Enter your choice (1-6) %c : ",176,176);
  scanf("%d",&ch1);
  beep();
  setgraphmode(2);
  clearviewport();
  while(1)
  {
    switch(ch1)
    //switch(2)
    {
      case 1:screen(2,0);
	     printf("\n\n\t\t\t   <--- LINEAR LIST OPERATIONS --->\n");
	     printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240);
	     printf("\n\t\t\t%c                                       %c",221,221);
	     printf("\n\t\t\t%c  1. Create a List or Add a Node       %c\n\t\t\t%c  2. Create Two Linked Lists           %c\n\t\t\t%c  3. Add a Node after a Node           %c\n\t\t\t%c  4. Add a Node before a Node          %c\n\t\t\t%c  5. Delete a Node                     %c\n\t\t\t%c  6. Display the List                  %c\n\t\t\t%c  7. Manipulations Using Two Pointers  %c\n\t\t\t%c  8. Exit                              %c",221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221);
	     printf("\n\t\t\t%c                                       %c",221,221);
	     printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240);
	     printf("\n\nPress 'a' to access the Applications Menu of Linked Lists or 'c' to continue ...");
	     a=getch();
	     beep();
	     do
	     {
	       if(a=='a')
	       {
		 screen(4,15);
		 printf("\n\n\t\t\t   <----- Applications ----->\n");
		 printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240);
		 printf("\n\t\t%c                                               %c",221,221);
		 printf("\n\t\t%c  1. nth Occurence Deletion                    %c\n\t\t%c  2. Insertion at nth Occurence                %c\n\t\t%c  3. Delete all Similar Nodes                  %c\n\t\t%c  4. Delete all Duplicates                     %c\n\t\t%c  5. Create Sorted Linked List                 %c\n\t\t%c  6. Reverse a linked List                     %c\n\t\t%c  7. Seperate Alternate Nodes of a Linked List %c\n\t\t%c  8. Merge two Lists in Sorted Order           %c\n\t\t%c  9. Concatenate two Linked Lists              %c\n\t\t%c 10. Dynamic Stack Operations                  %c\n\t\t%c 11. Display the Linked List                   %c\n\t\t%c 12. Polynomial Manipulations                  %c\n\t\t%c 13. Previous Menu / Exit                      %c",221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221);
		 printf("\n\t\t%c                                               %c",221,221);
		 printf("\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240);
		 printf("\n\n* Enter your choice (1-13) : ");
		 scanf("%d",&ch2);
		 printf("\t\t\t    %c%c",174,189);
		 getch();
		 beep();
		 cleardevice();
		 switch(ch2)
		 {
		   case 1:screen(0,15);
			  nth_occurence();
			  del_freq(1);
			  setgraphmode(2);
			  break;
		   case 2:screen(1,0);
			  nth_after_before();
			  add_freq(12);
			  setgraphmode(2);
			  break;
		   case 3:screen(2,4);
			  del_allsimilar();
			  del_freq(2);
			  setgraphmode(2);
			  break;
		   case 4:screen(3,0);
			  del_duplicate();
			  del_freq(3);
			  setgraphmode(2);
			   break;
		   case 5:screen(4,15);
			  sort_create_linear();
			  add_freq(12);
			  disp_linear(root1);
			  getch();
			  setgraphmode(2);
			   break;
		   case 6:screen(5,2);
			  reverse_linear();
			  if(ctr==1)
			    break;
			   disp_linear(root1);
			   getch();
			   setgraphmode(2);
			   break;
		   case 7:screen(12,0);
			  alternate_sep_linear();
			   if(ctr!=0)
			   {
			     printf("\n\tList 1 :-> \n\n");
			     getch();
			     disp_linear(root1);
			     getch();
			     printf("\n\tList 2 :-> \n\n");
			     getch();
			     disp_linear(root2);
			   }
			   getch();
			   setgraphmode(2);
			   break;
		   case 8:screen(13,14);
			  root1=merge_sort_linear(root1,root2);
			   if(root1==NULL||root2==NULL)
			     break;
			   getch();
			   disp_linear(root1);
			   getch();
			   setgraphmode(2);
			   break;
		   case 9:screen(2,0);
			  root1=concate_linear(root1,root2);
			   if(root1==NULL||root2==NULL)
			     break;
			   printf("\n\tLinked List after Concatenation => \n\n");
			   disp_linear(root1);
			   getch();
			   setgraphmode(2);
			   break;
		   case 10:screen(4,1);
			   do
			   {
			     printf("\n\n\t\t    <--- DYNAMIC STACK OPERATIONS --->\n");
			     printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240);
			     printf("\n\t\t\t%c                         %c",221,221);
			     printf("\n\t\t\t%c  1. Push an Element     %c\n\t\t\t%c  2. Pop from Stack      %c\n\t\t\t%c  3. Peep                %c\n\t\t\t%c  4. Traverse the Stack  %c\n\t\t\t%c  5. Exit                %c",221,221,221,221,221,221,221,221,221,221,221,221,221,221,221);
			     printf("\n\t\t\t%c                         %c",221,221);
			     printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240);
			     printf("\n\n* Enter your Choice (1-5) : ");
			     scanf("%d",&ch2);
			     printf("\t\t\t    %c%c",174,189);
			     getch();
			     beep();
			     switch(ch2)
			     {
			       case 1:screen(0,15);
				      dynamic_push();
				      getch();
				      setgraphmode(2);
				      break;
			       case 2:screen(1,0);
				      dynamic_pop();
				      getch();
				      setgraphmode(2);
				      break;
			       case 3:dynamic_peep();
				      getch();
				      break;
			       case 4:screen(3,0);
				      screen(2,15);
				      if(root1==NULL)
				      {
					printf("\n\tUnderflow ! Stack is empty !");
					break;
				      }
				      stck=1;
				      printf("\n\tThe Stack is => \n\n");
				      disp_linear(root1);
				      getch();
				      setgraphmode(2);
				      break;
			       case 5:ch2=10;
				      break;
			       default:printf("\n\tInvalid Choice !");
			     }
			   }while(ch2!=10);
			   getch();
			   setgraphmode(2);
			   break;
		   case 11:screen(6,15);
			   disp_linear(root1);
			   getch();
			   setgraphmode(2);
			   break;
		   case 12:screen(3,0);
			   printf("\n\t* OPERATIONS * 1. Create two Polynomials \n\t\t\t 2. Add Two Polynomials \n\t\t\t 3. Multiply Two Nodes \n\t\t\t 4. Exit");
			   scanf("%d",&ch3);
			   switch(ch3)
			   {
			     case 1:create_two_poly();
				    if(ctr==1)
				    {
				      getch();
				      return;
				    }
				    printf("\n\tFirst Polynomial :-> \n\n");
				    getch();
				    disp_polynomial(rt1);
				    printf("\n\n\tSecond Polynomial :-> \n\n");
				    getch();
				    disp_polynomial(rt2);
				    getch();
				    break;
			     //case 2:add_polynomial(rt1,rt2);
			       //	    break;
			     case 4:return;
			     default:printf("\n\tInvalid Choice !");
				     break;
			   }
			   getch();
			   setgraphmode(2);
			   break;
		   case 13:a='c';
			   p='e';
			   break;
		   default:printf("\n\tInvalid Choice !");
			   break;
		 }
		 setgraphmode(2);
	       }
	     else
	     {
		 if(b==1)
		 {
		   screen(6,0);
		   printf("\n\n\t\t\t   <--- LINEAR LIST OPERATIONS --->\n");
		   printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240);
		   printf("\n\t\t\t%c                                       %c",221,221);
		   printf("\n\t\t\t%c  1. Create a List or Add a Node       %c\n\t\t\t%c  2. Create Two Linked Lists           %c\n\t\t\t%c  3. Add a Node after a Node           %c\n\t\t\t%c  4. Add a Node before a Node          %c\n\t\t\t%c  5. Delete a Node                     %c\n\t\t\t%c  6. Display the List                  %c\n\t\t\t%c  7. Manipulations Using Two Pointers  %c\n\t\t\t%c  8. Applications / Exit               %c",221,221,221,221,221,221,221,221,221,221,221,221,221,221,221,221);
		   printf("\n\t\t\t%c                                       %c",221,221);
		   printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240);
		 }
		 b=1;
		 printf("\n* Enter your Choice (1-8) : ");
		 scanf("%d",&ch2);
		 beep();
		 cleardevice();
		 switch(ch2)
		 {
		   case 1:screen(4,0);
			  create_linear(root1);
			  add_freq(0);
			  printf("\n\n\n\n\n\t\tNode Created !\n\n");
			  disp_linear(root1);
			  getch();
			  setgraphmode(2);
			  break;
		   case 2:screen(4,15);
			  create_two_linear();
			  printf("\n\n\tList 1 :-> \n\n");
			  getch();
			  disp_linear(root1);
			  printf("\n\n\tList 2 :-> \n\n");
			  getch();
			  disp_linear(root2);
			  getch();
			  setgraphmode(2);
			  break;
		   case 3:screen(12,2);
			  add_after_linear();
			  if(ctr==1)
			    break;
			  add_freq(1);
			  disp_linear(root1);
			  getch();
			  setgraphmode(2);
			  break;
		   case 4:screen(11,0);
			  add_before_linear();
			  if(ctr==1)
			    break;
			  add_freq(0);
			  disp_linear(root1);
			  getch();
			  setgraphmode(2);
			  break;
		   case 5:screen(4,0);
			  if(root1==NULL)
			    error();
			  else
			  {
			    del_linear();
			    if(ctr==1)
			      break;
			    del_freq(12);
			    printf("\n\tDisplay the list ? (y/n) : ");
			    f=getch();
			    if(f=='y')
			    {
			      screen(4,15);
			      disp_linear(root1);
			    }
			  }
			  getch();
			  setgraphmode(2);
			  break;
		   case 6:screen(4,0);
			  disp_linear(root1);
			  getch();
			  setgraphmode(2);
			  break;
		   case 7:screen(1,14);
			  printf("\nOpeartions Available =>\n\t\t\t1. Creation in List\n\t\t\t2. Add a Node before a particular Node \n\t\t\t3. Delete a Node\n\n\t\t\tEnter your choice (1-3) : ");
			   scanf("%d",&ch3);
			   printf("\t\t\t\t\t\t    %c%c",174,189);
			   getch();
			   switch(ch3)
			   {
			     case 1:screen(0,14);
				    create_twopointers();
				    add_freq(3);
				    beep();
				    setgraphmode(2);
				    break;
			     case 2:screen(0,14);
				    add_bef_twopointers();
				    if(ctr==1)
				      break;
				    add_freq(12);
				    beep();
				    setgraphmode(2);
				    break;
			     case 3:screen(0,14);
				    del_twopointers();
				    if(ctr==1)
				      break;
				    del_freq(4);
				    beep();
				    setgraphmode(2);
				    break;
			   }
			   printf("\n\n");
			   beep();
			  disp_linear(root1);
			  getch();
			  setgraphmode(2);
			   break;
		   case 8:printf("\n\tDo you want to access the Applications ? (y/n) : ");
			  d=getch();
			  beep();
			  if(d=='y')
			    a='a';
			  else
			  {
			    getch();
			    return;
			  }
			  break;
		   default:printf("\n\tInvalid Choice !");
			   break;
		 }
	       }
	     }while(a!='e'||a!='a');
	     setgraphmode(2);
	     break;
      }
  }
  getch();
}