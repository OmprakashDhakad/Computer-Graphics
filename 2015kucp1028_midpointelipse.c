/*
  NAME  : OMPRAKASH 
  ID    : 2015kucp1028
  
  Compile the code  : gcc midpointelipse.c -lgraph
  run the code      : ./a.out

*/

#include<stdio.h>
#include<graphics.h>
double x[100000],y[100000];
int main()
{
  int i,l=0;
  double a,b;
  double m,n;
  printf("Enter the value of a :" );
  scanf("%lf",&a);
  printf("\nEnter the value of b :" );
  scanf("%lf",&b);
  printf("a = %lf , b = %lf\n",a,b); 
  double xk ,yk;
  double pk,pk1;
  double xk1 ,yk1;
  
  xk=0; yk=b;
  
  pk  = (a*a)/4 + (b*b) - (a*a*b) ; 
    
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
      
     m = (b*b)*x[l-1];         // variables to check condition 
     n = y[l-1]*(a*a);
     
    
  
  
  // loop  for octant 1
  while(m <= n)
  {
      
     pk1 = pk + (b*b) + (2*b*b*(xk+1)) + (a*a*( yk1*yk1 - yk*yk )) - (a*a*(yk1-yk));     // get next pk as pk1 and use for next point for octant 1
     
    
     
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
     
      m = (b*b)*x[l-1];
      n = y[l-1]*(a*a);
     
     
   }
   // loop  for octant 2
   while(yk>=0)
   {
      
     pk1 = pk + a*a - (2*a*a*(yk-1)) + (b*b*( xk1*xk1 - xk*xk )) + b*b*(xk1-xk);         // get next pk as pk1 and use for next point for octant 1     
     

     if(pk1 >= 0)
     {
        xk1  = xk1 ;
        yk1  = yk1 - 1;
        
     }
     else if(pk1 < 0)
     {
        xk1  = xk1 + 1;
        yk1  = yk1 - 1;
        
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
   
   for(i=0;i<k;i++)      // mirror of  first quadrant  to make fourth octant 
   {
      x[l] = x[i];
      y[l] = -y[i];
      l++;
     
   }
   
   k = l;
   for(i=0;i<k;i++)         // mirror of  first and fourth quadrant   to make second and third quadrant  
   {
      x[l] = -x[i];
      y[l] = y[i];
      l++;
      
   }
    
   int  r = 120;
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


