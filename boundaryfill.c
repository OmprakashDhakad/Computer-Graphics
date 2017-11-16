/*

   NAME  -  OMPRAKASH
   ID    -  2015KUCP1028
   
   compile the code  : 
   Run the code      :
*/


#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>

void boundryfill_8(int x,int y, int fillcolor,int boundrycolor)
{
    int now;
    now = getpixel(x,y);
    
    if(now!=fillcolor && now!=boundrycolor)
    {
      putpixel(x,y,fillcolor);
      
       boundryfill_8(x+1,y,fillcolor,boundrycolor);
       boundryfill_8(x,y+1,fillcolor,boundrycolor);
       boundryfill_8(x-1,y,fillcolor,boundrycolor);
       boundryfill_8(x,y-1,fillcolor,boundrycolor);
       boundryfill_8(x-1,y-1,fillcolor,boundrycolor);
       boundryfill_8(x+1,y-1,fillcolor,boundrycolor);
       boundryfill_8(x+1,y+1,fillcolor,boundrycolor);
       boundryfill_8(x-1,y+1,fillcolor,boundrycolor);
     
    } 
   
    
    
}

void boundryfill_4(int x,int y, int fillcolor,int boundrycolor)
{
    int now;
    now = getpixel(x,y);
    
    if(now!=fillcolor && now!=boundrycolor)
    {
      putpixel(x,y,fillcolor);
      
       boundryfill_4(x+1,y,fillcolor,boundrycolor);
       boundryfill_4(x,y+1,fillcolor,boundrycolor);
       boundryfill_4(x-1,y,fillcolor,boundrycolor);
       boundryfill_4(x,y-1,fillcolor,boundrycolor);
      
    } 
   
   
}
int main()
{
   
   
   int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);
    //make ractangle  
    rectangle(200,200,300,300);
    //fill rectangle
    boundryfill_8(250,250,1,15);
    
    //make circle
    circle(100,100,50);
    //fill circle
    boundryfill_4(100,100,1,15);
    getch();
    delay(10000);
}
