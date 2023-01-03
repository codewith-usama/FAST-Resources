#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<omp.h>

#define MAX_WORDS   1000



int main()
{
    FILE *filev;
    FILE *fptr;
    char path[100];
    int i, len, index, isUnique;

    char words[MAX_WORDS][50];
    char word[50];
    char sentence[1000];

    int  count[MAX_WORDS]={0};


    printf("Enter file path: ");
    scanf("%s", path);
    filev = fopen(path, "r");

    if (filev == NULL)
    {
        printf("Unable to open file.\n");
    }




    index = 0;
    #pragma omp parallel num_threads(4)
    {
    while (fscanf(filev, "%s", word) != EOF)
    {
        len = strlen(word);
        if (ispunct(word[len - 1]))
            word[len - 1] = '\0';
        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }
        if (isUnique) 
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }
    }
    
    fclose(filev);
    
    fptr = fopen("output.txt", "w");
    
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
   
    for (i=0; i<index; i++)
    {
        fprintf(fptr, "%s => %d\n", words[i], count[i]);
    	
    }    
    
fclose(fptr);
    return 0;
}
