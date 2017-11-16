/*
       NAME   :  OMPRAKASH
       ID     :  2015kucp1028
       

*/


#include<stdio.h>
#include<graphics.h>
double x[100000],y[100000];
int main()
{
  int i,l=0;
  double r;
  printf("Enter the radius of circle : ");
  scanf("%lf",&r);
  
  double xk ,yk;
  double pk,pk1;
  double xk1 ,yk1;
  
  xk=0; yk=r;
  
  pk =1-r; 
    
 int gd=DETECT,gm;
 initgraph(&gd,&gm,NULL);      
  
  x[l] = xk;
  y[l] = yk;
  l++;
  
  
     if(pk >= 0)           // check the condition for point pk and get xk1 and yk1
     {
        xk1  = xk + 1;
        yk1  = yk - 1;
        
     }
     else if(pk < 0)
     {
        xk1  = xk + 1;
        yk1  = yk;
       
     }
     
     x[l] = xk1;
     y[l] = yk1;
     l++;
     
     
  while( xk1 <= yk1)
  {
      
     pk1 = (pk + 2*(xk+1)+(yk1*yk1-yk*yk)-(yk1-yk)+1);            // get next pk as pk1 and use for next point 
     

     if(pk1 >= 0)
     {
        xk1  = xk1 + 1;
        yk1  = yk1 - 1;
        
     }
     else if(pk1 < 0)
     {
        xk1  = xk1 + 1;
        yk1  = yk1;
        
     }
     
     xk = x[l-1];
     yk = y[l-1];
     
     
     x[l] = xk1;
     y[l] = yk1;
     l++;
     
     pk = pk1;
     
     
     
   }
   
   l--;
   
   
   int k = l;
   
   for(i=0;i<k;i++)      // mirror of  first octant  to make second octant 
   {
      x[l] = y[i];
      y[l] = x[i];
      l++;
   }
   
   k = l;
   for(i=0;i<k;i++)         // mirror of  first quadrant to make fourth quadrant  
   {
      x[l] = x[i];
      y[l] = -y[i];
      l++;
   }
    
   k = l;
   
   for(i=0;i<k;i++)       //// mirror of  first half  to make second half 
   {
      x[l] = -x[i];
      y[l] = y[i];
      l++;
   }
   // for good represantation of the circle 
   if(r < 100)
   {
	   for(i=0;i<l;i++)
	   {
		putpixel(x[i]+100,y[i]+100,WHITE);
	   }
   }
   else
   {
      for(i=0;i<l;i++)
	   {
		putpixel(x[i]+r,y[i]+r,WHITE);
	   }
   }
   getch();
}
