#include<stdio.h>
int main()
{
	int sc;
	system("Color 0A");
	printf("\t\t\t\tWELCOME TO FAST-NUCES's SOCIETIES");
	printf("1.FAST Managment Society:");
	printf("\n2.DECS");
	printf("\n3.The Literacy Club (TLC)");
	printf("\n4.The Webmaster");
	printf("\n5.Association for Computing Machienry(ACM)");
	printf("\n6.Google Developers Society");
	printf("\n7.Character Building Society");
	
	printf("\n\nFor Information Press Respective key:");
	scanf("%d", &sc); // "sc" is used to store Society Code
	
	system("cls");
	do
	{
		
		switch(sc)
		{
			case 1:
				printf("FMS");
				printf("\nDo you believe you have what it takes to make an excellent team? \nProve your talents now and apply for the team of FMS, where you \nwill learn and test your skills, all on an exploratory journey with us.");
				printf("\nYou can apply for the following positions:\n\n*Deputy\n*Member");
				break;
			case 2:
				printf("DECS");
				printf("\nFAST NU’s most entertaining society, DECS, is back this year again \nto save you from the horrors of an everyday boring routine. \nOnce again, we are bringing to you some of the most enthralling events. ");
				printf("\nIntroductory session will offer you:");
				printf("\n1. Musical Performances by the DECS Music House.\n2. A Theatre play by the DECS Drama House.\n3. A Brief Introduction of the Society.\n4. Description of the upcoming events and our vision.\n\nSo, Do not forget to be there!");
				break;
			case 3:
				printf("TLC");
				printf("\nGrab that pen, grab that paintbrush, hold the mic, and the lens, \neven closer. As yet again, The Literary Club (TLC) is officially back in\nthe game with several exhilarating events, opportunities, \ncompetitions and so much more! ");		
				break;
			case 4:
				printf("The Webmaster");
				printf("\nDear FASTians, The wait is finally over! Inductions for The WebMasters are now \nlive. If you know any skills then now is the time to show them off \nby joining the most prestigious society of FAST.\nNo skills? Don't worry, Learners are encouraged to join, so they \ncan participate in upcoming workshops and events.");
				break;
			case 5:
				printf("Association for Computing Machienry(ACM)");
				printf("\nACM is here, for yet another day, to welcome you into a highly \nprofessional team of individuals, a team where you will not only \nlearn but will also grow.\n\nSo head right over to the team inductions for ACM and become a \npart of an internationally recognized society.");	
				break;
			case 6:
				printf("DSC");
				printf("Front End Web Development must have introduced you to the basics of Javascript \nand it's unending library of modules. We are sure that you must be intrigued to \nknow what comes next. This week would be based upon Back End Web Development with NodeJs. \nNodeJs is a very interesting feature mainly used as a runtime environment to execute Javascript code. \nSo what are you waiting for? Register for this session and devise plans to \nmanage your website perfectly!");
				break;
			case 7:
				printf("CBS");
				printf("Every fall, at the Character Building Society, the bright and passionate minds, young \nand new alike, take the pledge of making the world a little bit better! \nA world with a few more trees, a great many smiles and lots of love to go around! \nSo in these unprecedented times, of uncertainty and crisis, they are ready to meet the \nmoment with kindness, empathy and ambition. We proudly introduce the \nCBS Excom for 2020-2021.");
				break;							
		}
	}
	while(sc!=8);
	

}
