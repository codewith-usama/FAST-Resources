//there are two parts in our program one is for outsider and student in which we provide gernal information about univeersity and second is only for students
#include<stdio.h>
#include<string.h>
//#include<stdlib.h>
struct userdetail    //this structure is used to take basic information of outsider and students
	{
		int cnic;
		char name[100];
		char phnum[100];	
	}u,u1;
struct studentdetail   //this structure is used to take basic information of student
    {
    	int rollno;
    	char name[100];
	}st,st1;
	void heading(void);  //this is global decleration of fuction heading and fuction is define in line(672-677)	
int main()
{
	void input(void);
    void inputstudent(void);
	system("COLOR 0A");   //used for text color
	void societies(void);
	void cafeteria(void);
	void library(void);
	int a,select,num,section,i,j,field,sc;
	//the below 2-dimensional character array are used to initialize daily periods of the perticular sections of freshman batch
	char csa[4][100]={"MONDAY:IRS,CAL,PHY,PF,PHY","TUESDAY:ECC,PHY,PF,PF(lab)","WEDNESDAY:PF,PHY,IRS,ECC(lab)","THURSDAY:ECC,CAL,IRS,ICT(lab)"},csb[5][100]={"MONDAY:PF,IRS,CAL,IRS","TUESDAY:ECC(lab),PF,CAL,PHY","WEDNESDAY:CAL,ECC,PHY,PF","THURSDAY:PF(lab),PHY,IRS,ECC","FRIDAY:ICT(lab)"},csc[4][100]={"MONDAY:CAL,PHY,IRS,PF(lab)","TUESDAY:ICT,PHY,CAL,ECC","WEDNESDAY:PF,IRS,ECC,PF,ECC(lab)","THURSDAY:IRS,PHY,PF,CAL"};
	char csd[4][100]={"MONDAY:PF(lab),PHY,IRS,PF,IRS","TUESDAY:ECC,PHY,PF,CAL,PHY","WEDNESDAY:ICT(lab),PF,CAL","THURSDAY:ECC,CAL,IRS,ECC(lab)"},cse[5][100]={"MONDAY:CAL,PHY,IRS","TUESDAY:PF,CAL,ECC(lab)","WEDNESDAY:PF,ECC,CAL,IRS,PF(lab)","THURSDAY:PF,IRS,ECC,PHY,PHY","FRIDAY:ICT(lab)"},csf[4][100]={"MONDAY:ICT,PHY,ECC(lab)","TUESDAY:PF,ECC,PHY,CAL,IRS,IRS","WEDNESDAY:PF(lab),PF,CAL","THURSDAY:CAL,PHY,PF,IRS,ECC"};
	char sea[4][100]={"MONDAY:PHY,CAL,PST,ECC(lab)","TUESDAY:ICT(lab),PF","WEDNESDAY:PF,ECC,PHY,CAL,PHY,PST","THURSDAY:PF(lab),PF,ECC,CAL,PST"},seb[4][100]={"MONDAY:PHY,CAL,PST,PHY","TUESDAY:ECC,PF,CAL,ECC(lab)","WEDNESDAY:PF(lab),PF,PST,PHY","THURSDAY:ECC,PF,ICT(lab),PST,CAL"},sec[4][100]={"MONDAY:ICT(lab),CAL,PHY,PST","TUESDAY:PST,ECC,PHY,PF,CAL","WEDNESDAY:PF(lab),PF,PHY","THURSDAY:PF,ECC,PST,ECC(lab)"};
	char bdfa[4][100]={"MONDAY:PHY,ICT(lab),CAL,PST","TUESDAY:PF(lab),PF,ECC(lab)","WEDNESDAY:PF,ECC,PHY,CAL","THURSDAY:PHY,PF,ECC,PF,CAL,PST"};
	char aia[4][100]={"MONDAY:PST,CAL,PHY,CAL,ICT(lab)","TUESDAY:ECC,PHY,PF,PST,PHY","WEDNESDAY:PST,PF,PF,PF(lab)","THURSDAY:CAL,ECC,ECC(lab)"};
	char eea[4][100]={"MONDAY:PHY,PHY,AC,ICT(lab)","TUESDAY:ED(lab),IRS,ENG,ENG","WEDNESDAY:IRS,IRS,PHY,ENG,ITC,ITC","THURSDAY:PHY(lab),AC,AC"},eeb[4][100]={"MONDAY:ITC(lab),ITC,PHY,PHY","TUESDAY:AC,ENGENG,ED(lab)","WEDNESDAY:PHY,ITC,ENG,IRS,IRS","THURSDAY:AC,AC,IRS,PHY(lab)"};
	printf("                                               WELCOME TO THE FAST UNIVERSITY KARACHI CAMPUS\n");
	printf("                                       HERE YOU CAN PROVIDED ALL THE DETAILES WHICH YOU WANT TO KNOW\n");
	printf("SELECT YOU ARE NEW USER OR STUDENT \n");
	printf("1:NEW USER\n2:STUDENT\n");
	scanf("%d",&select);
	if(select==1)
	{
		input();   //here we call input fuction(line 614-643) which is used to input the basic information of new-user 
		do
		{
		printf("                              \n\nSELECT THE INFORMATION YOU WANT TO KNOW\n");
		printf("1: DIRECTOR ADDRESS\n2: HEAD OF DEPARTMENT ADDRESS(HOD)\n3: ADMISSION CRITERIA\n4: SCOLARSHIPS\n5: LOANS\n6: FEES STRUCTURE\n7: EXIT\n\n");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				system("cls");
				heading();
				printf("NAME : DR.JAWWAD AHMED SHAMSI\n");
				printf("EMAIL ADDRESS : jawwad.shamsi@nu.edu.pk\n");
				break;
			case 6:
				system("cls");
				heading();
				printf("ADMISSION FEES = 15,000 (FOR ALL PROGRAMS)\n");
				printf("TUTION FEES FOR BBA/BS PROGRAMS ARE 7,500 PER CREDIT HOUR\n");
				printf("Admission fees is non-refundable\n");
				break;
			case 2:
				system("cls");
				heading();
				printf("COMPUTER SCIENCE(BSCS)/ARTIFICAL INTELLIGENCE(BSAI)/CYBER SECURITY(BSCC) : ATIF TAHIR\n");
				printf("EMAIL ADDRESS = atif.tahir@nu.edu.pk\n");
				printf("ELECTRICAL ENGINEERING(BSEE) : DR SYED ATIF SALEEM\n");
				printf("EMAIL ADDRESS = syedsaleem@nu.edu.pk\n");
				printf("BACHELOR OF BUSINESS ADMINISTRATION(BBA) : NAZIA NAZEER\n");
				printf("EMAIL ADDRESS = nazia.nazeer@nu.edu.pk\n");
				break;
			case 3:	
			    system("cls");
			    heading();
				printf("                          \n\nTHE ADMISSION CRITERIA FOR ELECTRICAL ENGINEERING WILL BE AS FOLLOWING\n\n");
				printf("THE ELIGIBLITY CRITERIA :\n");
				printf("*At least 60%% marks in SSC (Matric)\n*At least 60%% marks in the Pre-Engineering\n*Must have studied Mathematics at the HSSC level.\n");	
				printf("ADMISSION ON THE BASIS OF NTS-NAT MARKS :\n");
				printf("*Selection is based on marks obtained in NTS NAT IE\n*Cut-off marks to be determined by the University.\n");
				printf("ADMISSION ON THE BASIS OF NU ADMISSION TEST :\n");
				printf("*Merit List is prepared by assigning 50%% weight to marks obtained in Intermediate (part-I)\n*50%% weight is assigned to score obtained in NU Admission Test.\n*In case, Intermediate result is not available, Matriculation marks are used and multiplied by a factor of 0.9 (to equate it to average Intermediate marks.\n");
                printf("ADMISSION ON BASIS OF SAT SCORE : \n");
                printf("*Combined score of 1,000 or more in the SAT-I examination\n*At least 550 in the SAT-II (Math Level IIC) examination.\n");	
				printf("                           \n\nTHE ADMISSION CRITERIA FOR BACHELOUR IN COPUTER SCIENCE WILL BE AS FOLLOWING\n\n");
				printf("THE ELIGIBLITY CRITERIA :\n");
				printf("*At least 60%% marks in SSC (Matric).\n*At least 50%% marks in the HSSC.\n*Must have studied Mathematics at the HSSC level.\n");
                printf("ADMISSION ON THE BASIS OF NTS-NAT MARKS :\n");
                printf("*Admission on the basis of NTS-NAT Marks.\n*Selection is based on marks obtained in NTS NAT IE, or NAT-ICS.\n*Cut-off marks to be determined by the University.\n");
                printf("ADMISSION ON THE BASIS OF NU ADMISSION TEST\n");
                printf("*Merit List is prepared by assigning 50%% weight to marks obtained in Intermediate (part-I).\n*50%% weight is assigned to score obtained in NU Admission Test.\n*In case, Intermediate result is not available, Matriculation marks are used and multiplied by a factor of 0.9 (to equate it to average Intermediate marks.\n");
                printf("ADMISSION ON THE BASIS OF SAT SCORE\n");
                printf("*Combined score of 1,000 or more in the SAT-I examination.\n*At least 550 in the SAT-II (Math Level IIC) examination.\n");
				printf("                            \n\nTHE ADMISSION CRITERIA FOR BACHELOR OF BUSINESS ADMINISTRATION\n\n");
				printf("THE ELIGIBLITY CRITERIA :\n\n");
				printf("*At least 60%% marks in SSC (Matric).\n*At least 50%% marks in HSSC\n");
                printf("ADMISSION ON THE BASIS NTS-NAT MARKS :\n\n");
                printf("*Selection is based on marks obtained in NTS NAT IE, NAT-ICS, NAT-ICOM, or NAT-IGS.\n*Cut-off marks to be determined by the University.");
                printf("ADMISSION ON THE BASIS OF NU ADMISSION TEST\n\n");
                printf("*Merit List is prepared by assigning 50%% weight to marks obtained in Intermediate (part-I).\n*50%% weight is assigned to score obtained in NU Admission Test.\n*In case, Intermediate result is not available, Matriculation marks are used and multiplied by a factor of 0.9 (to equate it to average Intermediate marks\n");
                printf("ADMISSION ON THE BASIS OF SAT SCORE :\n\n");
				printf("Combined score of 1,000 or more in the SAT-I examination.\n");
				break;
			case 4:
				system("cls");
				heading();
				printf("\n\nTHE MERIT SCOLARSHIPS FOR BACHELOUR STUDENT\n\n");
				printf("*Merit scholarship is awarded to the Top THREE position holders in each Group of each Examination Board.\n");
                printf("*Scholarship is also offered to top three position holders in the merit list of NU admission merit list.\n");
                printf("*This scholarship is for four years of un-interrupted studies with full course load and is equal to the full tuition fee.\n");
                printf("\nNOTE\n");
				printf("*Continuation of merit scholarship is subject to maintaining semester GPA of 3.0 or higher.");	
				printf("\n\nSINDH GOVERNMENT ENDOWMENT BOARD SCOLARSHIPS\n\n");
				printf("The Sindh Government offers scholarships to students of Karachi campus on need-cum-merit for both under-graduate and graduate studies.\nThe scholarship covers full tuition fee for entire duration of the program, renewable every year.\nThe quota for students from rural sector is 60%%, and the remaining 40%% is for the students from urban sector.\nAbout 25 new scholarships are offered every year under this scheme.\n");
				printf("\n\nBALOCHISTAN  GOVERNMENT ENDOWMENT BOARD SCOLARSHIPS\n\n");
				printf("Baluchistan Government offers scholarships to students of Karachi campus on need-cum-merit for both under-graduate and graduate studies.\nThe scholarship covers full tuition fee for entire duration of the program, renewable every year.\n");
			    printf("\n\nOTHER SCOLARSHIPS\n\n");
				printf("In addition to the above scholarships there are various community based scholarships offered by various committees and foundations such as,\nMemon Community Scholarships, Bohra Community Scholarships, INFAQ Foundation scholarships,\n Agha Khan Foundation Scholarships, etc.For Karachi campus, Alumni Association, Hindu Community,\nand Agha Khan Foundation also provides scholarships in limited numbers.\n");
				break;
			case 5:
				system("cls");
				heading();
			    printf("\n\nTHE VARIOUS TYPES OF STUDENT LOANS ARE AS FOLLOWING\n\n");
				printf("In addition to the above scholarships there are various community based scholarships offered by various committees and foundations such as,\n Memon Community Scholarships, Bohra Community Scholarships, INFAQ Foundation scholarships, Agha Khan Foundation Scholarships, etc.\nFor Karachi campus, Alumni Association, Hindu Community, and Agha Khan Foundation also provides scholarships in limited numbers.\n");
				printf("\n\nBANK LOANS\n\n");
				printf("PICIC Commercial Bank, NIB Bank, Bank Alfalah, Bank Islami and MCB offer loans to students.\n");
				printf("\n\nOSAF FINANCIAL ASSISTANCE(STUDY LOAN)\n\n");
				printf("OSAF (Old Students Association of FAST) arranges financial assistance for those students who cannot afford to pay their full fee.\n");
				printf("\n\nSTUDY LOANS\n\n");
				printf("Realizing that the fees may not be affordable for some of its students,\nFAST arranges financial assistance in the form of interest-free study loans for bright indigent students.\nThis assistance is subject to renewal every semester in light of the student’s academic performance. Financial assistance is limited to tuition fee only and is discontinued\nif the student’s CGPA falls below the minimum specified to avoid warning. Loan recipients MUST take full load of courses offered.\n");
				break;		        
		}
		
	    }
	    while(num!=7);	
	}
	else if(select==2)
	{
		int b;
		inputstudent();    //here we call inputstudent fuction(line 644-671) which is used to input the basic information of student
	    do
	    {
	    printf("\n\nSELECT THE DETAIL WHICH YOU WANT TO KNOW\n\n");
	    printf("1:SHEDULE OF DAILY CLASSES\n2:UPCOMING EVENT(IF AVAILABLE)\n3:PRICE LIST OF CAFETERIA AND DHABA\n4:SOCIETTIES\n5:LIBRARY\n6:EXIT\n");
	    scanf("%d",&num);
	    fflush(stdin);
	    switch(num)
	    {
	    	case 1:
	    		system("cls");
	    		heading();
	    		printf("\n\nHERE YOU CAN EASILY NOW THE CLASSES SHEDULE\n\n");
	    		printf("SELECT YOUR FIELD\n");
	    		printf("\n1:Computer Science(BSCS)\n2:Artifical Intelligence\n3:Software Engineering\n4:Electrical Engineering\n5:Cyber Security\n");
	    		scanf("%d",&field);
	    		system("cls");
	    		heading();
	    		fflush(stdin);
	    		if(field==1)
	    		{
	    			printf("\n\nNOW SELECT THE SECTION\n\n");
	    			printf("1:A\n2:B\n3:C\n4:D\n5:E\n6:F\n");
	    			scanf("%d",&section);
	    			{    //here we print all the shedule using pointers
	    				if(section==1)
	    				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(csa+i)+j));
								}
								printf("\n");
							}
						}
						else if(section==2)
	    				{
	    					for(i=0;i<5;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(csb+i)+j));
								}
								printf("\n");
							}
						}
						else if(section==3)
	    				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(csc+i)+j));
								}
								printf("\n");
							}
						}
						else if(section==4)
	    				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(csd+i)+j));
								}
								printf("\n");
							}
						}
						else if(section==5)
	    				{
	    					for(i=0;i<5;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(cse+i)+j));
								}
								printf("\n");
							}
						}
						else if(section==6)
	    				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(csf+i)+j));
								}
								printf("\n");
							}
						}
					}
				}
				else if(field==2)
				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(aia+i)+j));
								}
								printf("\n");
							}
				}
				else if(field==3)
				{
					printf("\n\nNOW SELECT THE SECTION\n\n");
	    			printf("1:A\n2:B\n3:C\n");
	    			scanf("%d",&section);				
					if(section==1)
	    				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(sea+i)+j));
								}
								printf("\n");
							}
						}
					else if(section==2)
	    				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(seb+i)+j));
								}
								printf("\n");
							}
						}
					else if(section==3)
	    				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(sec+i)+j));
								}
								printf("\n");
							}
						}		
				}
				else if(field==4)
				{
					printf("\n\nNOW SELECT THE SECTION\n\n");
	    			printf("1:A\n2:B\n");
	    			scanf("%d",&section);
	    			if(section==1)
	    				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(eea+i)+j));
								}
								printf("\n");
							}
						}
					else if(section==2)
	    				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(eeb+i)+j));
								}
								printf("\n");
							}
						}					
				}
				else if(field==5)
				{
	    					for(i=0;i<4;i++)
	    					{
	    						for(j=0;j<100;j++)
	    						{
	    							printf("%c",*(*(sec+i)+j));
								}
								printf("\n");
							}
				}
				printf("\n\n");
				break;
	    	case 2:
	    		system("cls");
	    		heading();
	    		printf("\n\nTHEREE IS NO UPCOMING EVENT DUE TO THE COVID-19 HOLIDAYS,WILL RESUME INSHALLAH HOLIDAYS\n\n");
			    break;
			case 3:
				system("cls");
				heading();
				cafeteria();   //function define in line(346-533)
				break;
			case 4:
				system("cls");
				heading();
				societies();  //function define in line(534-602)
				break;
			case 5:
				system("cls");
				heading();
			    library();	//function define in line(603-613)				 	
		}
		
		}while(num!=6);
				
	}
	
}
void cafeteria(void)
{
	int sum=0;
	int choice;
	printf("		\t\t\t\t\tWELCOME TO FAST-NUCES's CAFETERIA ");
	do
	{
	printf("\n\n1.Roll Paratha\t\tRs.50\t\t2.Mayo Roll\t\tRs.60\n3.BBQ Roll\t\tRs.80\t\t4.Burger\t\tRs.50\n5.French fries\t\tRs.30\t\t6.Chicken roll\t\tRs.60\n7.simple roll\t\tRs.30\t\t8.Zinger burger\t\tRs.170\n9.Chicken broast\tRs.190\t\t10.cheese burger\tRs.150\n11.Chicken biryani\tRs.90\t\t12.mutton biryani\tRs.220\n13.beef biryani\t\tRs.190\t\t14.single plate bryani\tRs.50\n\n15.white rice\t\tRs.90\t\t16.piza deal complete\tRs.320\n17.piza deal with zinger Rs.490\t\t18.pizza family pack\tRs.500\n19.small piza\t\tRs.250\t\t20.full colddrink\tRs.120\n21.single coldrdink\tRs.60\t\t22.tin pack\t\tRs.50\n23.1.5 liter bottle\tRs.90\t\t24.juices\t\tRs.40\n25.tea\t\t\tRs.30\t\t26.water bottle full\tRs.70\n27.biscuits\t\tRs.15\t\t28.water bottle smal\tRs.50\n29.exit\t\t");
	printf("\nSelect any thing you want to eat:");
	scanf("%d", &choice); // "CC" is used to store the code for Cafeteria menu
   int total=0,rpo,mro,bbq,burger,ff,cro,sro,zb,chb,chbur,chbr,mbr,bbr,spbr,vbr,wr,pizza,pz,pf,sp,fcl,scl,tp,lbottle,juices,tea,wb,biscuits,wbs;
   switch(choice)
	{
	    case 1:
			 printf("\nHow many Roll Paratha do you want to order: ");
			 scanf("%d", &rpo); // "rpo" is used to store the quantity of ordered Roll Paratha
			 total=rpo*50;
			 printf("\n%d roll parhata Rs. %d\n",rpo,total);
			 break;
	    case 2:
		    printf("\nHow many Mayo Roll do you want to order: ");
		    scanf("%d", &mro); // "mro" is used to store the quantity of ordered Mayo Roll	
		    total=mro*60;
		    printf("\n%d mayo roll Rs. %d\n",mro,total);
		    break;	
		case  3:
		    printf("\nHow many bbq roll do you want to order: ");
		    scanf("%d", &bbq); // "bbq" is used to store the quantity of ordered bbq roll
	        total=bbq*80;
		    printf("\n%d bbq roll Rs. %d\n",bbq,total);	
			break;	
	    case 4:
		   printf("\nHow many burgers do you want to order: ");
		   scanf("%d", &burger); // "rpo" is used to store the quantity of burger
		   total=burger*50;
		   printf("\n%d burgers Rs. %d\n",burger,total);
		   break;	
		case 5:
		   printf("\nHow many packets of french fries  do you want to order: ");
		   scanf("%d", &ff); // "ff" is used to store the quantity of orered french fries
		   total=ff*30;
		   printf("\n%d french fries Rs. %d\n",ff,total);
		   break;
		case 6:
		   printf("\nHow many chicken roll  do you want to order: ");
		   scanf("%d", &cro); // "cro" is used to store the quantity of ordered chicken roll
		   total=60*cro;
		   printf("\n%d chicken roll Rs. %d\n",cro,total);
		   break;
		case 7:
		   printf("\nHow many simple roll do you want to order: ");
		   scanf("%d", &sro); // "sro" is used to store the quantity of ordered simple Roll 
		   total=sro*30;
		   printf("\n%d simple roll Rs. %d \n",sro,total);
			break;
		case 8:
		   printf("\nHow many zinger burger do you want to order: ");
		   scanf("%d", &zb); // "zb" is used to store the quantity of ordered zinger burger
		   total=zb*170;
		   printf("\n%d zinger burgur Rs. %d\n",zb,total);
		   break;
		case 9:
		   printf("\nHow many  chicken broast do you want to order: ");
		   scanf("%d", &chb); // "chb" is used to store the quantity of ordered chicken broast
		   total=190*chb;
		   printf("\n%d chicken broast Rs. %d\n",chb,total);
		   break;
		case 10:
		   printf("\nHow many chesse burger do you want to order: ");
		   scanf("%d", &chbur); // "chbur" is used to store the quantity of ordered cheese burger
		   total=150*chbur;
		   printf("\n%d chesse burgur Rs. %d\n",chbur,total);
			break;
	    case 11:
	       printf("\nHow many plate of chicken biryani do you want to order: ");
		   scanf("%d", &chbr); // "chbr" is used to store the quantity of ordered chicken biryani
		   total=chbr*90; 
	      printf("\n%d chicken biryani Rs. %d\n",chbr,total);
			break;
	    case 12:
		   printf("\nHow many plate of mutton bryani   do you want to order: ");
		   scanf("%d", &mbr); // "mbr" is used to store the quantity of ordered mutton biryani
		   total=220*mbr;
		   printf("\n%d mutton biryani Rs. %d\n",mbr,total);
			break;
	    case 13:
		  printf("\nHow many plate of beef biryani do you want to order: ");
		  scanf("%d", &bbr); // "bbr" is used to store the quantity of ordered beef biryani
		  total=bbr*190;
		  printf("\n%d beef biryani Rs. %d\n",bbr,total);
		  break;
		case 14:
		   printf("\nHow many single plate biryani do you want to order: ");
		   scanf("%d", &spbr); // "spbr" is used to store the quantity of ordered single plate biryani
		   total=spbr*50;
		   printf("\n%d single plate biryani Rs. %d\n",spbr,total);
		   break;
		case 15:
			printf("\nHow many plate of white rice  do you want to order: ");
			scanf("%d", &wr); // "vbr" is used to store the quantity of ordered white rice
			total=wr*90;
			printf("\n%d plate of white rice Rs. %d\n",wr,total);
			break;
		case 16:
			printf("\nHow many pizza deal complete do you want to order: ");
			scanf("%d", &pizza); // "pizza" is used to store the quantity of ordered pizza deal
			total=320*pizza;
			printf("\n%d pizza deal complete Rs. %d\n",pizza,total);
			break;
		case 17:
			printf("\nHow many pizza with broast  do you want to order: ");
			scanf("%d", &pz); // "pz" is used to store the quantity of ordered pizza with broast
			total=490*pz;
			printf("\n%d pizza with broast Rs. %d\n",pz,total);
			break;
		case 18:
			printf("\nHow many pizza family pack   do you want to order: ");
			scanf("%d", &pf); // "pf" is used to store the quantity ordered family pizza pack
			total=500*pf;
			printf("\n%d pizza family Rs. %d\n",pf,total);
			break;
		case 19:
			printf("\nHow many small  piza  do you want to order: ");
			scanf("%d", &sp); // "sp" is used to store the quantity of ordered small pizzza
			total=sp*250;
			printf("\n%d small pizza Rs. %d\n",sp,total);
			break;
	    case 20:
			printf("\nHow many full colddrink  do you want to order: ");
			scanf("%d", &fcl); // "fcl" is used to storedm full colddrink.
			total=fcl*120;
			printf("\n%d full cold drink Rs. %d\n",fcl,total);
			break;
		case 21:
			printf("\nHow many single colddrink do you want to order: ");
			scanf("%d", &scl); // "fcl" is used to store the quantity of ordered single colddrink
			total=fcl*60;
			printf("\n%d single cold drink Rs. %d\n",scl,total);
			break;
		case 22:
			printf("\nHow many tin pack do you want to order: ");
			scanf("%d", &tp); // "tp" is used to store the quantity of ordered tin pack
			total=scl*50;
			printf("\n%d tin pack Rs. %d\n",tp,total);
			break;
		case 23:
			printf("\n1.5 litter bottle  do you want to order: ");
			scanf("%d", &lbottle); // "tp" is used to store the quantity of ordered 1.5 litter bottle
			total=lbottle*90;;
			printf("\n%d 1.5 litter bottle Rs. %d\n",lbottle,total);
			break;
		case 24:
			printf("\nHow many juices   do you want to order: ");
			scanf("%d", &juices); // "juices" is used to store the quantity of ordered juices
			total=40*juices;
			printf("\n%d juices Rs. %d\n",juices,total);
			break;
		case 25:
			printf("How many cup of tea  do you want to order: ");
			scanf("%d", &tea); // "tea" is used to store the quantity of ordered tea
			total=tea*30;
			printf("\n%d tea Rs. %d\n",tea,total);
			break;
		case 26:
			printf("\nHow many water bottles of  do you want to order: ");
			scanf("%d", &wb); // "wb" is used to store the quantity of ordered water bottles
			total=wb*70;
			printf("\n%d watter bottle Rs. %d\n",wb,total);
			break;
	    case 27:
			printf("\nHow many paxket of biscuits do you want to order: ");
			scanf("%d", &biscuits); // "biscuits" is used to store the quantity of ordered biscuits
		    total=biscuits*15;
			printf("\n%d packet of biscuit Rs. %d\n",biscuits,total);
			break;
	    case 28:
			printf("\nHow many small bottles of water: ");
			scanf("%d",&wbs); // "wbs" is used to store the quantity of small water bottles
		    total=wbs*50;
			printf("\n%d small bottles Rs. %d\n",wbs,total);
			break;
    }
    system("cls");
    heading();
    sum=sum+total;
}while(choice!=29);
    printf("\n**********************************************************************************************************\n");
    printf("\n\n                        THE TOTAL BILL WILL BE   %d \n",sum);
    printf("\n\n**********************************************************************************************************\n");   
}
void societies(void)
{
	int sc;
	printf("\t\t\t\t\t\t\tWELCOME TO FAST-NUCES's SOCIETIES");
	do
	{
	printf("\n\n1.FAST Managment Society");
	printf("\n2.DECS");
	printf("\n3.The Literacy Club (TLC)");
	printf("\n4.The Webmaster");
	printf("\n5.Association for Computing Machienry(ACM)");
	printf("\n6.Google Developers Society");
	printf("\n7.Character Building Society");
	printf("\n8:Exit");
	printf("\n\nFor Information Press Respective key:\n\n");
	scanf("%d", &sc); // "sc" is used to store Society Code
	fflush(stdin);
	printf("\n");
		switch(sc)
		{
			case 1:
				system("cls");
				heading();
				printf("FMS");
				printf("\nDo you believe you have what it takes to make an excellent team? \nProve your talents now and apply for the team of FMS, where you \nwill learn and test your skills, all on an exploratory journey with us.");
				printf("\nYou can apply for the following positions:\n\n*Deputy\n*Member");
				break;
			case 2:
				system("cls");
				heading();
				printf("DECS");
				printf("\nFAST NU’s most entertaining society, DECS, is back this year again \nto save you from the horrors of an everyday boring routine. \nOnce again, we are bringing to you some of the most enthralling events. ");
				printf("\nIntroductory session will offer you:");
				printf("\n1. Musical Performances by the DECS Music House.\n2. A Theatre play by the DECS Drama House.\n3. A Brief Introduction of the Society.\n4. Description of the upcoming events and our vision.\n\nSo, Do not forget to be there!");
				break;
			case 3:
				system("cls");
				heading();
				printf("TLC");
				printf("\nGrab that pen, grab that paintbrush, hold the mic, and the lens, \neven closer. As yet again, The Literary Club (TLC) is officially back in\nthe game with several exhilarating events, opportunities, \ncompetitions and so much more! ");		
				break;
			case 4:
				system("cls");
				heading();
				printf("The Webmaster");
				printf("\nDear FASTians, The wait is finally over! Inductions for The WebMasters are now \nlive. If you know any skills then now is the time to show them off \nby joining the most prestigious society of FAST.\nNo skills? Don't worry, Learners are encouraged to join, so they \ncan participate in upcoming workshops and events.");
				break;
			case 5:
				system("cls");
				heading();
				printf("Association for Computing Machienry(ACM)");
				printf("\nACM is here, for yet another day, to welcome you into a highly \nprofessional team of individuals, a team where you will not only \nlearn but will also grow.\n\nSo head right over to the team inductions for ACM and become a \npart of an internationally recognized society.");	
				break;
			case 6:
				system("cls");
				heading();
				printf("DSC");
				printf("\nFront End Web Development must have introduced you to the basics of Javascript \nand it's unending library of modules. We are sure that you must be intrigued to \nknow what comes next. This week would be based upon Back End Web Development with NodeJs. \nNodeJs is a very interesting feature mainly used as a runtime environment to execute Javascript code. \nSo what are you waiting for? Register for this session and devise plans to \nmanage your website perfectly!");
				break;
			case 7:
				system("cls");
				heading();
				printf("CBS");
				printf("\nEvery fall, at the Character Building Society, the bright and passionate minds, young \nand new alike, take the pledge of making the world a little bit better! \nA world with a few more trees, a great many smiles and lots of love to go around! \nSo in these unprecedented times, of uncertainty and crisis, they are ready to meet the \nmoment with kindness, empathy and ambition. We proudly introduce the \nCBS Excom for 2020-2021.");
				break;								
		}
	}
	while(sc!=8);
}
void library(void)
{
	printf("\n\nWELCOME TO THE FAST UNIVERSITY LIBRARY\n\n");
	printf("\nHERE YOU CAN PROVIDED THE RULES REGARDING ISSUE OF THE BOOK\n\n");
	printf("1: If you want to issue the book you would concern with the counter in the libary\n");
	printf("2: The book is only available for 15 days\n");
	printf("3: If you want the book more than 15 days you would apply it to re-issue the book\n");
	printf("4: At the late return of the book you will be awarded fine of 5 Rs per day\n");
	printf("5: There are some combine study and meeting rooms privided in the the library if you want to avail it you would reserve it by informing the counter\n");
	printf("6: There is one lab in the library where efficient desktops and internet service are available\n");
}
void input()//the functionality in this fuction is that if the user is visiting first time so the basic data will be feeded in the file or if it is visiting more than one time so as he/she enter there CNIC number the fuction alerady reads there previous data and show them on the screen 
{
	FILE *user;
	printf("ENTER FIRST FIVE NUMBERS OF YOUR CNIC\n");
	scanf("%d",&u.cnic);
	user=fopen("userfile.txt","a+");
	while(1){
	fscanf(user,"%d  %[^\n]  %[^\n]",&u1.cnic,u1.name,u1.phnum);
	if(u1.cnic==u.cnic)
	{
	printf("THE CNIC NUMBER WILL BE : %d\nTHE NAME WILL BE : %s\nTHE PHONE NUMBER WILL BE : %s\n",u1.cnic,u1.name,u1.phnum);
	break;
	}
	if(feof(user))
	{
	printf("ENTER YOUR NAME \n");
	fflush(stdin);
	gets(u.name);
	fflush(stdin);
	printf("ENTER YOUR PHONE NUMBER \n");
	fflush(stdin);
	gets(u.phnum);
	fprintf(user,"%d\n%s\n%s\n",u.cnic,u.name,u.phnum);
	break;
	}
	else
	continue;
	}
	fclose(user);
}
void inputstudent()//the functionality in this fuction is that if the student is visiting first time so the basic data will be feeded in the file or if it is visiting more than one time so as he/she enter there ROLLNO number the fuction alerady reads there previous data and show them on the screen 
{
	FILE *student;
	printf("ENTER YOUR ROLLNO AFTER 20K-");
	scanf("%d",&st.rollno);
	fflush(stdin);
	student=fopen("studentfile.txt","a+");
	while(1){
	fscanf(student,"%d  %[^\n]",&st1.rollno,st1.name);
	if(st1.rollno==st.rollno)
	{
	printf("THE ROLL NUMBER WILL BE : %d\nTHE NAME WILL BE : %s\n",st1.rollno,st1.name);
	break;
	}
	if(feof(student))
	{
	printf("ENTER YOUR NAME: ");
	fflush(stdin);
	gets(st.name);
	fflush(stdin);
	fprintf(student,"%d\n%s\n",st.rollno,st.name);
	break;
	}
	else
	continue;
	}
	fclose(student);
}
void heading()
{
	printf("                                               WELCOME TO THE FAST UNIVERSITY KARACHI CAMPUS\n");
	printf("                                       HERE YOU CAN PROVIDED ALL THE DETAILES WHICH YOU WANT TO KNOW\n");

}

