#include<iostream>
#include"Functions.h"
using namespace std;

template <typename D>
D getData() //function to get input datatype
{
	D data;
	
	cout << "\nEnter value: ";
	cin >> data;
	
	return data;
}

int getRow()
{
	int row;
	
	cout << "\nEnter row number: ";
	cin >> row;
	
	return row;
}

int getCol()
{
	int col;
	
	cout << "\nEnter row number: ";
	cin >> col;
	
	return col;
}

template <typename T>
void menu(LinkedList2D<T> list1) //menu of task 1
{
	int opt;
	bool run = true;
	T val;
	int rowNo;
	int colNo;
	
	do {
		cout << "\n\nMenu:";
		cout << "\n\n1. Add rows";
		cout << "\n2. Insert nodes";
		cout << "\n3. Delete node";
		cout << "\n4. Update node";
		cout << "\n5. Get specific value of node";
		cout << "\n6. Empty list";
		cout << "\n7. Display specific row";
		cout << "\n8. Split row";
		cout << "\n9. Reverse row";
		cout << "\n10. Quit";
		cout << "\n\nWhich task do you want to perform? ";
		cin >> opt; //input user option
		
		while(opt < 0 or opt > 10) //invalid option check
		{
			cout << "\nInvalid input\nTry again ";
			cin >> opt;
		}
		
		switch(opt)
		{
			case 1: //add rows
			{
				val = getData<T>();
				
				list1.addRows(val);
				break;
			}
			case 2: //insert node
			{
				val = getData<T>();
				rowNo = getRow();
				
				list1.insertNodeAtRow(rowNo, val);
				break;	
			}
			case 3: //delete node
			{
				rowNo = getRow();
				colNo = getCol();
				
				list1.deleteNode(rowNo, colNo);
				break;	
			}
			case 4: //update node
			{
				val = getData<T>();
				rowNo = getRow();
				colNo = getCol();
				
				list1.updateNode(rowNo, colNo, val);
				break;
			}
			case 5: //get specific value of node
			{
				rowNo = getRow();
				colNo = getCol();
				
				cout << list1.getValueOfNode(rowNo, colNo);
				break;
			}
			case 6: //make list empty
			{
				
				break;
			}
			case 7:
			{
				rowNo = getRow();
				
				list1.displayRow(rowNo);
				break;
			}
			case 10: //quit
			{
				cout << "\nBye";
				run = false;
				break;
			}	
		}
		
		if(opt != 10)
		{
			char random;
			
			cout << "\nPress any button to go back to menu: ";
			cin >> random;
		}
		
	} while(run != false);
}

void unused_function() //unused function
{
	LinkedList2D<int> list1; //predeclare objects
	LinkedList2D<float> list2;
	
	menu<int>(list1);
	menu<float>(list2);
}
