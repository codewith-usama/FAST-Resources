#include<stdio.h>
struct dep{
	int de_id;
	char dep_name;
};
struct empolyee{
	int id;//emp_id
	char name[100];
	int sal;
	int age;
	struct dep d;
};
void del(FILE* fp1,struct empolyee e[]);
void partb(struct empolyee e[],int n);
void replace(FILE *fp,struct empolyee e[]);
void partd(FILE *fp1,struct empolyee e[]);
int main(){
	FILE *fp;
	fp=fopen("k200190.txt","w");
	int n;
	n=5;//given in question
	struct empolyee e[5];
	struct empolyee *p;
	p=e;
	int i;
	for(i=0;i<5;i++){
		printf("enter name: ");
		fflush(stdin);
		gets(p->name);
		printf("emp id: ");
		scanf("%d",&p->age);
		printf("emp salary: ");
		scanf("%d",&p->sal);//considering K is there by default so if i put 20 it means 20K
		printf("emp d: ");

		scanf(" %c",&p->d.dep_name);
		printf("emp dep id: ");
		scanf("%d",&p->d.de_id);
		//fwrite(&e,sizeof(struct empolyee),1,fp);
		fprintf(fp,"%s %d %d %c %d",p->name,p->age,p->sal,p->d.dep_name,p->d.de_id);
		printf("\n");
		
	}
	fclose(fp);
	fp=fopen("k200281.txt","r");
	for(i=0;i<5;i++){
		//fread("&e",sizeof(struct empolyee),1,fp);
		fscanf(fp,"%30s %d %d %c %d",&p->name,&p->age,&p->sal,&p->d.dep_name,&p->d.de_id);
		
	
		printf("%d",p->age);
		printf("%c",p->d.dep_name);
		printf("%d",p->d.de_id);
		puts(p->name);
		printf("%d",p->sal);
	}
	partb(e,5);
	replace(fp,e);

}
void partb(struct empolyee e[],int n){
	int i;
	int max=0;
	for(i=0;i<5;i++){
		if(e[i].d.dep_name=='X'){
			if(e[i].sal>max){
				max=e[i].sal;
			}
		}
	}
	for(i=0;i<5;i++){
	
		if(e[i].d.dep_name=='Y'){
			if(e[i].sal>max){
				printf("%s",e[i].name);
			
			}
			
		}
	}

}
void replace(FILE *fp,struct empolyee e[]){

	char d;
	FILE *fp1;
	fp1=fopen("update.bin","w");
	fp=fopen("k200281.bin","r");

	while(!feof(fp)){
		d=fgetc(fp);
		if(d>=65 && d<=90){
			if(d==32){
				d='-';
			}
			fputc(d,fp1);
		}
	}


	fclose(fp1);
	partd(fp1,e);
	
}
void partd(FILE *fp1,struct empolyee e[]){
	fp1=fopen("update.txt","r");
	int i=0;
	while(!feof(fp1)){
		fscanf(fp1,"%30s %d %d %c %d",&e[i].name,&e[i].age,&e[i].sal,&e[i].d.dep_name,&e[i].d.de_id);
		if(e[i].d.dep_name=='X'){
			if(e[i].age>30){
				puts(e[i].name);		//printf(" %s",e[i].name);
				printf("%d",e[i].age);
				printf("%c",e[i].d.dep_name);
				printf("%d",e[i].d.de_id);
			}
			
		}
		i++;
	}
	fclose(fp1);
	del(fp1,e);
} 
void del(FILE* fp1,struct empolyee e[]){
	fp1=fopen("update.txt","r");
	FILE *fp2;
	int i=0;
	fp2=fopen("afterdel.txt","w");
	int id;
	printf("enter id to delete: ");
	scanf("%d",&id);
	while(!feof(fp1)){
		fscanf(fp1,"%30s %d %d %c %d",&e[i].name,&e[i].age,&e[i].sal,&e[i].d.dep_name,&e[i].d.de_id);
		if(e[i].id!=id){
			fprintf(fp2,"%30s %d %d %c %d",e[i].name,e[i].age,e[i].sal,e[i].d.dep_name,e[i].d.de_id);
			i++;
		}
		else{
			i++;
		}
	}
	fclose(fp2);
}

