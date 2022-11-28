#include<stdio.h>
#include<string.h>
struct article
{
	int id,issue,s_page,e_page,year;
	char author[20],journal[20],title[30];
};
main()
{	
FILE *fptr;
fptr = fopen("abcd.bin", "wb");
if ( fptr == NULL )
{
puts("cannot open file");
}
int i,n;
printf("Enter number of articles:");
scanf("%d",&n);
struct article e[1];	
for(i=0; i<n; i++)
{
	

printf("Id: %d",i+1);
printf("Enter title");
scanf("%s",e[i].title);
printf("Enter journal: ");
scanf("%s",e[i].journal);
printf("Issue");
scanf("%d",&e[i].issue);
printf("Year");
scanf("%d",&e[i].year);
printf("Start page:");
scanf("%d",&e[i].s_page);
printf("end page :");
scanf("%d",&e[i].e_page);
printf("enter author");
scanf("%s",e[i].author);
fwrite(&e[i],sizeof(struct article),1,fptr);
}
fclose(fptr);
fptr=fopen("abcd.bin","rb");
for(i=0; i<1; i++){

	fread(&e[i],sizeof(struct article),1,fptr);
printf("%d\n",i+1);
printf("%s\n",e[i].title);
printf("%s\n",e[i].journal);
printf("%d\n",e[i].issue);
printf("%d\n",e[i].year);
printf("%d\n",e[i].s_page);
printf("%d\n",e[i].e_page);
printf("%s\n",e[i].author);
}
fclose(fptr);
}
