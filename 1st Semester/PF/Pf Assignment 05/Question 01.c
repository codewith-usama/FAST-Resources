int main(void)
{

    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,0,1,2}};
    int *ptr = &arr;
    int i, j;

    for(i=0;i<3;i++)
	{
        for(j=0;j<4;j++)
            printf("%d ",*((ptr+i*4)+j)); 
            
            printf("\n");
    }
    
    if(arr[1]>arr[2]>arr[3]>arr[4])
    printf("\n%d", arr[1]);
    else if(arr[2]>arr[1]>arr[3]>arr[4])
    printf("\n%d", arr[2]);
    else if(arr[3]>arr[1]>arr[3]>arr[4])
    printf("\n%d", arr[3]);
    else
    printf("\n%d", arr[4]);
    return 0;
    
}
