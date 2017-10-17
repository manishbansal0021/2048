#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdlib.h>
#include<dos.h>
int a[4][4]={0};
int getkey();
void display();
void up();
void shiftup();
void shiftdown();
void shiftleft();
void shiftright();
void left();
void right();
void down();
void set();
int check()
{
 int i,j,count=0;
 for(i=0;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
   if(a[i][j]==2048)
   return 1;
   else if(a[i][j]!=0)
   count++;
  }
 }
 if(count==16)
 return 2;
 else
 return 0;
}
void main()
{
 int ch,c;
 clrscr();
 cout<<"Welcome to 2048\n\n";
 cout<<"Press ESC to exit!\n\n";
 sleep(2);
 set();
 while(1)
 {
  clrscr();
  system("cls");
  c=check();
  if(c==1)
  {
   cout<<"You won !!";
   sleep(2);
   exit(2);
  }
  else if(c==2)
  {
   cout<<"You lose !!";
   sleep(2);
   exit(3);
  }
  display();
  ch=getkey();
  if(ch==27)
  {
   cout<<"Exiting the game!";
   sleep(2);
   exit(1);
  }
  if(ch==72)
  {
   up();
  }
  if(ch==75)
  {
   left();
  }
  if(ch==80)
  {
   down();
  }
  if(ch==77)
  {
   right();
  }
  set();
 }
}
int getkey()
{
 int ch;
 ch=getch();
 if(ch==0)
 {
  ch=getch();
  return(ch);
 }
 return(ch);
}
void display()
{
 int i,j;
 for(i=0;i<4;i++)
 {
  cout<<"|";
  for(j=0;j<4;j++)
  {
   if(a[i][j]==0)
   cout<<"    |";
   else
   cout<<setw(4)<<a[i][j]<<"|";
  }
  cout<<endl;
 }
}
void up()
{
 int i,j;
 shiftup();
 for(i=0;i<3;i++)
 {
  for(j=0;j<4;j++)
  {
   if(a[i][j]==a[i+1][j])
   {
    a[i][j]=a[i][j]*2;
    a[i+1][j]=0;
   }
  }
 }
 shiftup();
}
void down()
{
 int i,j;
 shiftdown();
 for(i=3;i>0;i--)
 {
  for(j=0;j<4;j++)
  {
   if(a[i-1][j]==a[i][j])
   {
    a[i][j]=a[i][j]*2;
    a[i-1][j]=0;
   }
  }
 }
 shiftdown();
}
void left()
{
 int i,j;
 shiftleft();
 for(i=0;i<4;i++)
 {
  for(j=0;j<3;j++)
  {
   if(a[i][j]==a[i][j+1])
   {
    a[i][j]=a[i][j]*2;
    a[i][j+1]=0;
   }
  }
 }
 shiftleft();
}
void right()
{
 int i,j;
 shiftright();
 for(i=0;i<=3;i++)
 {
  for(j=3;j>0;j--)
  {
   if(a[i][j]==a[i][j-1])
   {
    a[i][j]=a[i][j]*2;
    a[i][j-1]=0;
   }
  }
 }
 shiftright();
}
void shiftup()
{
 int i,j,k;
 for(i=1;i<4;i++)
 {
  for(j=0;j<4;j++)
  {
   for(k=0;k<i;k++)
   {
    if(a[i-1-k][j]==0)
    {
     a[i-1-k][j]=a[i-k][j];
     a[i-k][j]=0;
    }
   }
  }
 }
}
void shiftdown()
{
 int i,j,k;
 for(i=2;i>=0;i--)
 {
  for(j=0;j<4;j++)
  {
   for(k=0;k<3;k++)
   {
    if(a[i+1+k][j]==0)
    {
     a[i+1+k][j]=a[i+k][j];
     a[i+k][j]=0;
    }
   }
  }
 }
}
void shiftleft()
{
 int i,j,k;
 for(i=0;i<4;i++)
 {
  for(j=1;j<4;j++)
  {
   for(k=0;k<j;k++)
   {
    if(a[i][j-1-k]==0)
    {
     a[i][j-1-k]=a[i][j-k];
     a[i][j-k]=0;
    }
   }
  }
 }
}
void shiftright()
{
 int i,j,k,count;
 for(i=0;i<4;i++)
 {
  for(j=2;j>=0;j--)
  {
   for(k=0;k<3;k++)
   {
    count=j+1+k;
    if(a[i][count]==0 && count<4)
    {
     a[i][j+1+k]=a[i][j+k];
     a[i][j+k]=0;
    }
   }
  }
 }
}
void set()
{
 int b[2]={2,4};
 int i,x,y;
 i=rand()%2;
 x=rand()%4;
 y=rand()%4;
 if(a[x][y]!=0)
 set();
 else
 a[x][y]=b[i];
}