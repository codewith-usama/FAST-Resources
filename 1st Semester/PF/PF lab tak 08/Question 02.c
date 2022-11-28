#include <stdio.h>
 
long power (int, int);
 
main()
{
    int exp, base;
    long result;
 
    printf("Enter a base: ");
    scanf("%d", &base);
    printf("Enter it's power: ");
    scanf("%d", &exp);
    result = power(base, exp);
    printf("The value of %d power %d is = %d ", base, exp, result);
    return 0;
}
 
long power (int base, int exp)
{
    if (exp)
    {
        return (base * power(base, exp - 1));
    }
    return 1;
}


