#include <stdio.h>
int main()
{
	int m, d;
	printf("Enter your birth month ");
	scanf(" %d", &m);
	printf("Enter your Birth Date ");
	scanf(" %d", &d);
	if(m==1){
		for(d; d<=19; d++){
			printf("Your Sign is Capricon");
			break;
		}
		for(d; d>=20; d++){
			printf("Your Sign is Aquarius");
			break;
		}
	}
	if(m==2){
		for(d; d<=17; d++){
			printf("Your Sign is Aquarius");
			break;
		}
		for(d; d>=18; d++){
			printf("Your Sign is Pisces");
			break;
		}
	}
	if(m==3){
		for(d; d<=19; d++){
			printf("Your Sign is Pisces");
			break;
		}
		for(d; d>=20; d++){
			printf("Your Sign is Aries");
			break;
		}
	}
	if(m==4){
		for(d; d<=19; d++){
			printf("Your Sign is Aries");
			break;
		}
		for(d; d>=20; d++){
			printf("Your Sign is Taurus");
			break;
		}
	}
	if(m==5){
		for(d; d<=20; d++){
			printf("Your Sign is Taurus");
			break;
		}
		for(d; d>=21; d++){
			printf("Your Sign is Gemini");
			break;
		}
	}
	if(m==6){
		for(d; d<=20; d++){
			printf("Your Sign is Gemini");
			break;
		}
		for(d; d>=21; d++){
			printf("Your Sign is Cancer");
			break;
		}
	}
	if(m==7){
		for(d; d<=22; d++){
			printf("Your Sign is Cancer");
			break;
		}
		for(d; d>=23; d++){
			printf("Your Sign is Leo");
			break;
		}
	}
	if(m==8){
		for(d; d<=22; d++){
			printf("Your Sign is Leo");
			break;
		}
		for(d; d>=23; d++){
			printf("Your Sign is Virgo");
			break;
		}
	}
	if(m==9){
		for(d; d<=22; d++){
			printf("Your Sign is Virgo");
			break;
		}
		for(d; d>=23; d++){
			printf("Your Sign is Libra");
			break;
		}
	}
	if(m==10){
		for(d; d<=22; d++){
			printf("Your Sign is Libra");
			break;
		}
		for(d; d>=23; d++){
			printf("Your Sign is Scorpio");
			break;
		}
	}
	if(m==11){
		for(d; d<=21; d++){
			printf("Your Sign is Scorpio");
			break;
		}
		for(d; d>=22; d++){
			printf("Your Sign is Sagittarius");
			break;
		}
	}
	if(m==12){
		for(d; d<=21; d++){
			printf("Your Sign is Sagittarius");
			break;
		}
		for(d; d>=22; d++){
			printf("Your sign is Capricon");
			break;
		}
	}
}
