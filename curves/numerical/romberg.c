#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sphere (double x) { 
   return sqrt(1 + 4*sin(x)*sin(x));
}

double parab(double t){
  return sqrt( 
      (1+4*t*t*sin(t)*sin(t)) * pow((sin(t) + t*cos(t)), 2)
     +(1+4*t*t*cos(t)*cos(t)) * pow((cos(t) - t*sin(t)), 2)
     + 8*t*t*sin(t)*cos(t)*(cos(t) - t*sin(t))* (sin(t) + t*cos(t))     );
}
double hyperb(double t){
  return sqrt( 
      (1+4*t*t*sin(t)*sin(t)) * pow((sin(t) + t*cos(t)), 2)
     +(1+4*t*t*cos(t)*cos(t)) * pow((cos(t) - t*sin(t)), 2)
     - 8*t*t*sin(t)*cos(t)*(cos(t) - t*sin(t))* (sin(t) + t*cos(t))    );
}

double a=0.1;
double b=1;
double o=10;

double defsph (double t) {
    return sqrt( pow(a*sin(o*t)+b,2) +
                 pow(a*o*cos(o*t),2) +
                 pow( 2*(a*sin(o*t)+b)*sin(t) ,2)                       );
}

void romberg(double f(double), double a, double b, int n, double **R)
{
  int i, j, k;
  double h, sum;

  h = b - a;
  R[0][0] = 0.5 * h * (f(a) + f(b));   
  printf(" R[0][0] = %f\n", R[0][0]);

  for (i = 1; i <= n; i++)
  { 
     h *= 0.5;
     sum = 0;
     for (k = 1; k <= pow(2,i)-1; k+=2)
     {
       sum += f(a + k * h);
     } 
     R[i][0] = 0.5 * R[i-1][0] + sum * h;  
     printf(" R[%d][0] = %f\n", i, R[i][0]);
     for (j = 1; j <= i; j++)
     {
       R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4,j)-1); 
       printf(" R[%d][%d] = %f\n", i,j, R[i][j]);
     }
   }
}

int main()
{
  int n = 10;
  int i;
  double **R;

  R = calloc((n+1), sizeof(double *));
  for (i = 0; i <= n; i++)
    R[i] = calloc((n+1), sizeof(double));

  printf("Sphere Winding curve\n");
  romberg(sphere,        0.0, 3.1415926, 8, R);
  printf("Deformed sphere\n");
  romberg(defsph,               0, 3.1415926, 8, R);
  printf("parab\n");
  romberg(parab,  -3.1415926, 3.1415926, 8, R);
  printf("hyperb\n");
  romberg(hyperb, -3.1415926, 3.1415926, 8, R);

  return 0;
}
