#include<stdio.h>
main()
{
	int n;
	printf("\t\tWelcome to National University of Computer and Emerging Sciences Karachi\n\nGreetings to my dear students, friends, and alumni. It is my great pleasure to serve our students and National \nUniversity of Computer and Emerging Sciences, as the Director of NUCES-FAST Karachi Campus.\nFor more than 30 years NUCES-FAST continues to play an important role in educating and fostering its students for their enlightened careers in Computer Science, Electrical Engineering and Management Sciences. Significant number of our graduates hold leading positions not only in Karachi but throughout Pakistan and globally.\nWe are indeed gifted with immense talent and intellect among our faculty, staff, and students and I believe it is our responsibility to use these gifts to catalyze a positive impact on our careers and especially where it is needed the most. Our emphasis is not only on the quality of education but on development of necessary skills as well as on integration of entrepreneurship into the curriculum.\nI would like to extend my sincere regards for having an amazing development experience during your time at National University of Computer and Emerging Sciences.\nI encourage you to explore our website, visit the Campus, meet with our advisors and faculty, attend our events.\n");
	printf("\nIf you are a student press 1:\n");
	printf("If you are a visitor press 2:\n");
	
	char a, s;
	scanf("%d", &n);
	
	if(n==2 || n==1)
	{
		if(n==2)
		{
		printf("Hello Sir");
		printf("\nHow Can We Help You");
	
		printf("\nPress 'A' to know about Admission policy: ");
		scanf(" %c", &a);
		
		if(a=='a' || a=='A')
		{
			printf("So, Our Admission Policy Starts In Every July Of The Year");
			printf("\nFAST-NUCES Provides A Certified Knowledge");
			printf("\nDegrees Provided By FAST-NUCES are;");
			printf("\nBechlor Of Computer Sciences BS(CS)");
			printf("\nBechlor Of Software Engineering BS(SE)");
			printf("\nBechlor Of Artificial Intelligence BS(BDF)");
			printf("\nBechlor Of Electrical Engineering BS(EE)");
			printf("\nBechlor Of Cyber Security BS(EE)");
			
			printf("\nPress 'C' To Get Information About BS(CS):");
			printf("\nPress 'S' To Get Information About BS(SE):");
			printf("\nPress 'A' To Get Information About BS(AI):");
			printf("\nPress 'E' To Get Information About BS(EE):");
			printf("\nPress 'B' To Get Information About BS(BDF):\n");
			
			
			scanf(" %c", &s);
		}
			
			if(s=='c' || s=='C')
			{
				printf("\nComputer Science Is A Four Degree Program Which Is Provided By FAST-NUCES For Last 40 Years. \nOur Degree Is verified By HEC and PEC");
				printf("\nFee Structure is:");
				printf("\nAdmission Fee Rs.20000 Once.");
				printf("\nSecurity Fee Rs.15000 Once Refendable.");
				printf("\nFee Per Credit hour is Rs.8000.");
				printf("\nLibrary Fee Per Semester Rs.20000.");
			}
			else if(s=='s' || s=='S')
			{
				printf("\nSoftware Engineering Is A Four Degree Program Which Is Provided By FAST-NUCES Since 2018. \nOur Degree Is verified By HEC and PEC. \nWe Have HEC Recognized Labs And Students Are Allow To Do Their Activity At Campus Labs.");
				printf("\nFee Structure is:");
				printf("\nAdmission Fee Rs.20000 Once.");
				printf("\nSecurity Fee Rs.15000 Once Refendable.");
				printf("\nFee Per Credit hour is Rs.7500");
				printf("\nLibrary Fee Per Semester Rs.20000.");
			}
			else if(s=='a' || s=='A')
			{
				printf("\nArtificial Intelligence Is A Four Degree Program Which Is Provided By FAST-NUCES Since 2020. Artificial Intelligence degree program is based on the core modules such as machine learning, deep learning, information theory, interference and learning algorithms.");
				printf("\nFee Structure is:");
				printf("\nAdmission Fee Rs.20000 Once.");
				printf("\nSecurity Fee Rs.15000 Once Refendable.");
				printf("\nFee Per Credit hour is Rs.7500");
				printf("\nLibrary Fee Per Semester Rs.20000.");
			}
			else if(s=='e' || s=='E')
			{
				printf("\nElectrical Engineering Is A Four Degree Program Which Is Provided By FAST-NUCES Since 2012. \nOur Degree Is verified By HEC and PEC. \nWe Have HEC Recognized Labs And Students Are Allow To Do Their Activity At Campus Labs.");
				printf("\nFee Structure is:");
				printf("\nAdmission Fee Rs.20000 Once.");
				printf("\nSecurity Fee Rs.15000 Once Refendable.");
				printf("\nFee Per Credit hour is Rs.7500");
				printf("\nLibrary Fee Per Semester Rs.20000.");
			}
			else if(s=='b' || s=='B')
			{
				printf("\nCyber Security is a four degree program delivered by FAST-NUSEC.\nCyber security degree program is based on the core modules such as programming, networks and IT Security");
				printf("\nFee Structure is:");
				printf("\nAdmission Fee Rs.20000 Once.");
				printf("\nSecurity Fee Rs.15000 Once Refendable.");
				printf("\nFee Per Credit hour is Rs.7500");
				printf("\nLibrary Fee Per Semester Rs.20000.");
			}
			else 
			printf("Please enter provided code.");
		}
		
		else
		{
			printf("\nWelcome Dear Fastian. We hope you are fine.");
			printf("\nIf you want to check time table press 1:\nIf you want to know about upcoming event press 2:\nIf you want information about cafeteria and Dhaba press 3:\nIf you want information about Societies press 4:");
			scanf("%d", n);
			
			if(n==1)
			{
				printf("We have 6 days classes in a week. We have talented teachers and professors\n studied by abroad and they know how to make a schedule so studnts can easliy manage.");
			}
			if(n==2)
			{
				printf("")
			}
		}
	}
			
		
		

}
	

