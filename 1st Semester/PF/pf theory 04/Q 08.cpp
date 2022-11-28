#include<stdio.h>
void printPatternRowRecur(int n) 
{  
    if (n < 1) 
        return; 
        
    printf("Mohammad\n"); 
    printPatternRowRecur(n-1); 
} 
  
void printPatternRecur(int n) 
{ 
    if (n < 1) 
        return; 
      
    printPatternRowRecur(n);     
      
    printf("Usama\n"); 
      
    printPatternRecur(n-1); 
      
} 
  
int main() 
{ 
    int n = 5; 
    printPatternRecur(n); 
    return 0; 
} 
