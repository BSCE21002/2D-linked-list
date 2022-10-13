#include <iostream>
#include "Functions.h"
using namespace std;


int main() //driver code
{
	int opt;
	bool run = true;
	
	do {
		cout << "\n\nEnter data type:";
		cout << "\n\n1. int";
		cout << "\n2. float";
		cout << "\n\n";
		cin >> opt; //input data type
		
		while(opt < 0 or opt > 2) //invalid option check
		{
			cout << "\nInvalid input\nTry again ";
			cin >> opt;
		}
		
		switch(opt)
		{
			case 1: //int type
			{
				LinkedList2D<int> list1;
				menu<int>(list1);
				
				break;
			}
			case 2: //float type
			{
				LinkedList2D<float> list1;
				menu<float>(list1);
				
				break;	
			}
		}
		
	} while(run != false);
	
	return 0;
}
