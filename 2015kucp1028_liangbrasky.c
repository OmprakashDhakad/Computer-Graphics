/*
       Name  : OMPRAKASH
       ID    : 2015kucp1028
       
       compile the code : gcc 2015kucp1028_liangbrasky.c -lgraph
       Run the code     : ./a.out
       
*/

#include<stdio.h>
#include<math.h>
#include<graphics.h>

int points[2][2];                         // points array for final clipping points
double t1[4]= {0,0,0,0},t2[4]={1,1,1,1}; // time arrays for both points to store 4 values 

double max(double a,double b)         // max function for time t1 
{
   return a>b?a:b;
}
double min(double a,double b)       // min function for time t2
{
   return a<b?a:b;
}
int main()
{
   double dx,dy,x1,y1,x2,y2,p[4],q[4];
   double xmin=100,ymin=100,xmax=400,ymax=400;
   int i=0;
   printf("Please Enter value greater then 100 \n");
   printf("Enter the window coordinate xmin,ymin,xmax,ymax: ");   // inputs of xmin,ymin,xmax,ymax
   scanf("%lf%lf%lf%lf", &xmin,&ymin,&xmax,&ymax);
   printf("Enter the line coordinate x1,y1,x2,y2: ");             // inputs of x1,y1,x2,y2
   scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
   
   int gd = DETECT,gm;
   
   dx = x2-x1;         // delta values for x and y
   dy = y2-y1;
   
   p[0] = -dx;         // p1 p2 p3 p4 and q1 q2 q3 q4 array values 
   p[1] = dx; 
   p[2] = -dy;
   p[3] = dy;
   
   q[0] = x1-xmin;
   q[1] = xmax-x1;
   q[2] = y1-ymin;
   q[3] = ymax-y1;
   
   
   for(i=0;i<4;i++)
   {
      if(p[i] == 0)
      {
         if(q[i] < 0)
         { 
           printf("line is parallel the window \n"); 
         }
      }
      else if(p[i]!=0)
      {
         /*if(q[i] < 0)
         {
           printf("line is outside the window \n");
         }
         else if(q[i] > 0)
         { 
           printf("line is inside the window or intersect \n");
         }
         else
         { 
           printf("line on window boundary  \n");
         }*/
         
         if(p[i] <0)
         { 
            double  temp1 = (q[i]/p[i]);
            t1[i] = max(0,temp1);
         }
         else if(p[i] > 0)
         {
           double  temp2 = (q[i]/p[i]);
           t2[i] = min(1,temp2);
         }
        
      }
      
   }
   double maxt1 = 0;
   double mint2 = 1;
   for(i =0 ;i < 4;i++)         //find max value from t1 array and min from array t2 
   {
     if(maxt1 <= t1[i])
     {
       maxt1 = t1[i];
     }
      
     if(mint2 >= t2[i])
     {
       mint2 = t2[i];
     }
   }
           // generate points from max of t1 and min of t2 
           points[0][0] = x1 + maxt1 * dx;
           points[0][1] = y1 + maxt1 * dy;
           points[1][0] = x1 + mint2 * dx;
           points[1][1] = y1 + mint2 * dy;
   
   initgraph(&gd, &gm,NULL); 
   //setcolor(GREEN);
   rectangle(xmin,ymin,xmax,ymax);   // generate window on graphics window 
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
