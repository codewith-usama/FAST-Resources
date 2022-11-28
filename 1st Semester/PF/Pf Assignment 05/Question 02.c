#include<stdio.h>
#include<math.h>

int main()
{
    float r,xx[9],xy[9],yy[9],nr=0,dr_1=0,dr_2=0,dr_3=0,dr=0;
    float x[9]={1,3,5,7,9,11,12,14,16},y[9]={2,4,6,8,10,12,13,15,17};
    float sum_y=0,sum_yy=0,sum_xy=0,sum_x=0,sum_xx=0;
    int i,n=9;
    
    for(i=0;i<n;i++)
    {
     xx[i]=x[i]*x[i];
     yy[i]=y[i]*y[i];
    }
    
    for(i=0;i<n;i++)
    {
     sum_x+=x[i];
     sum_y+=y[i];
     sum_xx+= xx[i];
     sum_yy+=yy[i];
     sum_xy+= x[i]*y[i];     
    }
    
    nr=(n*sum_xy)-(sum_x*sum_y);
    
    float sum_x2=sum_x*sum_x;
    float sum_y2=sum_y*sum_y;
    
    dr_1=(n*sum_xx)-sum_x2;
    dr_2=(n*sum_yy)-sum_y2;
    dr_3=dr_1*dr_2;
    dr=sqrt(dr_3);
    r=(nr/dr);
    
    printf("Total Numbers:%d\nCorrelation Coefficient:%.2f",n,r);
    return 0;   
}
