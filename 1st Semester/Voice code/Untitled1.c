//#include<iostream>
#include<mmsystem.h>
#include<windows.h>
using namespace std;

int main()
{
	playSound(TEXT("Voice.wAV"), NULL, SND_SYNC);
	return 0;
}
