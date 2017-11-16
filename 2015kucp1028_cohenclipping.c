/*
     Name  : OMPRAKASH
     ID    : 2015kucp1028
     
     compile the code : gcc 2015kucp1028_cohenclipping.c -lgraph
     run the code     : ./a.out
*/


#include<stdio.h>
#include<graphics.h>

int points[2][2];
int max(int a,int b)
{
  return ((a>b) ? a : b);
}
int min(int a,int b)
{
  return ((a<b) ? a : b);
}
int findcode(int x ,int y, int xmin, int ymin,int xmax,int ymax)
{
   int top=0,bottom=0,right=0,left=0; 
   if(y < ymin)
     {top = 8;}
   if(x < xmin)
     {left = 1;}
   if(x > xmax)
     {right = 2;}
   if(y > ymax)
     {bottom =4;} 
   
   return (top|bottom|right|left); 
   
}

int setpoints(int xa ,int ya ,int xb ,int yb)
{
	points[0][0] = xa;
	points[0][1] = ya;
	points[1][0] = xb;
	points[1][1] = yb;
}

int main()
{
   int x1,y1,x2,y2;
   int xmin=200,ymin=200,xmax=400,ymax=400;
   int i=0;
   printf("Please Enter value greater then 100\n");
   printf("Enter the window coordinate xmin,ymin,xmax,ymax: ");   // inputs of xmin,ymin,xmax,ymax
   scanf("%d%d%d%d", &xmin,&ymin,&xmax,&ymax);
   printf("Enter the line coordinate x1,y1,x2,y2: ");             // inputs of x1,y1,x2,y2
   scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	
   
      
	int code1=0,code2=0;
	code1 = findcode(x1,y1,xmin,ymin,xmax,ymax);
	code2 = findcode(x2,y2,xmin,ymin,xmax,ymax);
	
	
	
	if(x1==x2)                                          // for vertical line
	{
		if(x1>=xmin && x1<=xmax) 
		{
		    setpoints(x1,ymin,x1,ymax);
		}
	}
	else if(y1==y2)                                   //  for  horizontal line 
	{
		if(y1>=ymin && y1<=ymax)
		{
		  setpoints(xmin,y1,xmax,y1);
		}
	}
	else
	{
	    double  m  = ((double)y2-(double)y1)/((double)x2-(double)x1);  // slope of the line 
	    
	    if(code1==0 && code2==0)
	    {
	       setpoints(x1,y1,x2,y2);
	    }
	    else if(code1!=0 && code2!=0)                      
	    {
	           i=0;
	           int x,y;
			
			x = ((double)ymin-(double)y1)/m + x1;
			if((x<=x2 && x>=x1) && x>=xmin && x<=xmax) 
			{
			   points[i][0] = x;
                     points[i][1] = ymin;
                     i++;
			}
			
			x = ((double)ymax-(double)y1)/m + x1;
			if((x<=x2 && x>=x1) && x>=xmin && x<=xmax)
			{
			   points[i][0] = x;
                     points[i][1] = ymax;
                     i++;
			}
			
			y = ((double)xmin-(double)x1)*m + y1;
			if(i<2 && y>=ymin && y<=ymax && (y<=max(y1,y2) && y>=min(y1,y2)))
			{
			   points[i][0] = xmin;
                     points[i][1] = y;
                     i++;
			}
			
			y = ((double)xmax-(double)x1)*m + y1;
			if(i<2 && y>=ymin && y<= ymax && (y<=max(y1,y2) && y>=min(y1,y2)))
			{
			   points[i][0] = xmax;
                     points[i][1] = y;
                     i++;
			}
	    }
	    else if(code1==0)
	    { 
	            i=0;
	            int x,y;
			
			points[i][0] = x1;
                  points[i][1] = y1;
                  i++;
			
			x = ((double)ymin-(double)y1)/m + x1;
			if((x<=x2 && x>=x1) && x>=xmin && x<=xmax)
			{
			    points[i][0] = x;
                      points[i][1] = ymin;
                      i++;
			}
			
			x = ((double)ymax-(double)y1)/m + x1;
			if((x<=x2 && x>=x1) && x>=xmin && x<=xmax)
			{
			   points[i][0] = x;
                     points[i][1] = ymax;
                     i++;
			}
			
			y = ((double)xmax-(double)x1)*m + y1;
			if(i<2 && y>=ymin && y<=ymax && (y<=max(y1,y2) && y>=min(y1,y2)))
			{
			   points[i][0] = xmax;
                     points[i][1] = y;
                     i++;
			}
		
	    }
	    else if(code2==0)
	    {
	         i=0;
	         int x,y;
			
			points[i][0] = x2;
                  points[i][1] = y2;
                  i++;
			
			x = ((double)ymin-(double)y1)/m + x1;
			if((x<=x2 && x>=x1) && x>=xmin && x<=xmax )
			{
			   points[i][0] = x;
                     points[i][1] = ymin;
                     i++;
			}
			
			x = ((double)ymax-(double)y1)/m + x1;
			if((x<=x2 && x>=x1) && x>=xmin && x<=xmax )
			{
			   points[i][0] = x;
                     points[i][1] = ymax;
                     i++;
			}
			
			y = ((double)xmin-(double)x1)*m + y1;
			if(i<2 && y >= ymin && y<=ymax && (y<=max(y1,y2) && y>=min(y1,y2)))
			{
			   points[i][0] = xmin;
                     points[i][1] = y;
                     i++;
			}
	    }
	    
	}
	
	if((code1 & code2)==0)
	{ 
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	rectangle(xmin,ymin,xmax,ymax);
	line(x1,y1,x2,y2);
	
	   setcolor(RED);                     // set color red for points and fill them with blue color
	   circle(points[0][0] ,points[0][1],3);
	   floodfill(points[0][0] ,points[0][1],BLUE);
	   circle(points[1][0] ,points[1][1],3);
	   floodfill(points[1][0] ,points[1][1],BLUE);
	   line(points[0][0] ,points[0][1] ,points[1][0] ,points[1][1]);
		      
		      char *p1,*p2;
			p1 = (char *)malloc(20*sizeof(char));
			p2 = (char *)malloc(20*sizeof(char));
	
			sprintf(p1,"P1 : (%d,%d)",points[0][0],points[0][1]);          // print the values of final points on graphics window 
			sprintf(p2,"P2 : (%d,%d)",points[1][0],points[1][1]);
	
			outtextxy(points[0][0]-20,points[0][1]-20,p1);
			outtextxy(points[1][0]-20,points[1][1]-20,p2);
	   delay(10000);
	   getch();
	 
	   closegraph();
	}
	else
	{
	    printf("line rejected line is out side th window \n");
	}

}
