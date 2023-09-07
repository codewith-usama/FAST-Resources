#include <iostream>

using namespace std;

int main()
{
	int a[3][3] = {
					{1,0,0},
					{0,1,0},
					{0,0,1}
				};
	
	int i,j;
	int flag = 0;			
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		if ((a[i][j] != 1) && (a[j][i] != 0))
            {
                flag = 1;
                break;
            }
		

		}
	}
	
	if(flag ==0)
	cout<<"Identity matrix";
	else if(flag == 1)
	cout<<"Not an Identity matrix";
	
	cout<<"Array elements"<<endl;
	
		for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<"a["<<i<<"]"<<"["<<j<<"] = "<<a[i][j]<<endl;
	
		}
	}


	return 0;
}
