#include<iostream>

using namespace std;

template <typename T>
class Node {
	public:
		T data;
		Node *nextCol;
		Node *nextRow;
		
		Node(int val)
		{
			data = val;
			nextCol = nullptr;
			nextRow = nullptr;
		}
	
};

template <typename T>
class LinkedList2D { //class of 2D linked list
	public:
		Node<T> *headRow;
		Node<T> *tailRow;
		
		Node<T> *headCol;
		Node<T> *tailCol;
		
		int rowCount;
		
		LinkedList2D()
		{
			headRow = nullptr;
			tailRow = nullptr;
			
			rowCount = 0;
		}
		
		~LinkedList2D()
		{
			delete headRow;
			delete tailRow;
		}
		
		void beginList(Node<T> *temp)
		{
			headRow = temp;
			tailRow = temp;
			rowCount++;
		}
		
		void displayRow(int rowNo)
		{
			if(rowCount < 0 or rowCount > rowNo)
			{
				cout << "\nNo rows available to display.";
			}
			else
			{
				cout << "\n";
				Node<T> *temp = headRow;
				for(int i = 0; i < rowCount; i++)
				{
					cout << temp->data << "\n";
					temp = temp->nextRow;
				}
			}
		}
		
		void addRows(T val)
		{
			Node<T> *temp = new Node<T>(val);
			
			if(headRow == nullptr)
			{
				beginList(temp);
			}
			else
			{
				cout << "\nNew row successfully added.";
				
				tailRow->nextRow = temp;
				tailRow = temp;
				tailRow->nextRow = nullptr;
				
				rowCount++;
			}
			
		}
		
		void insertNodeAtRow(int rowNo, T val)
		{
			if(rowCount < 0 or rowCount > rowNo)
			{
				cout << "\n\nInvalid row number.";
				return;
			}
			else
			{
				if(rowNo == 1)
				{
					cout << "\nNode successfully added.";
					
					Node<T> *temp2 = new Node<T>(val);
					headRow->nextCol = temp2;
					temp2->nextCol = nullptr;
					
				}
				else
				{
					cout << "\nNode successfully added.";
				
					Node<T> *temp = headRow;
					Node<T> *temp2 = new Node<T>(val);
					for(int i = 0; i < rowNo - 1; i++)
					{
						temp = temp->nextRow;
					}
					
					while(temp->nextCol != nullptr)
					{
						temp = temp->nextCol;
					}
				
					temp->nextCol = temp2;
					temp2->nextCol = nullptr;
				}
			}
		}
		
		void deleteNode(int rowNo, int colNo)
		{
			Node<T> *temp = headRow;
			Node<T> *temp2 = headRow;
			for(int i = 0; i < rowNo - 1; i++)
			{
				temp = temp->nextRow;
				temp2 = temp2->nextCol;
			}
			
			for(int i = 0; i < colNo - 2; i++)
			{
				temp = temp->nextCol;
				temp2 = temp2->nextCol;
			}
			
			temp2 = temp2->nextCol;
			
			delete temp2;
			temp->nextCol = nullptr;
		}
		
		void updateNode(int rowNo, int colNo, T val)
		{
			Node<T> *temp = headRow;
			for(int i = 0; i < rowNo - 1; i++)
			{
				temp = temp->nextRow;
			}
			
			for(int i = 0; i < colNo - 1; i++)
			{
				temp = temp->nextCol;
			}
			
			temp->data = val;
		}
		
		T getValueOfNode(int rowNo, int colNo)
		{
			Node<T> *temp = headRow;
			for(int i = 0; i < rowNo - 1; i++)
			{
				temp = temp->nextRow;
			}
			
			for(int i = 0; i < colNo - 1; i++)
			{
				temp = temp->nextCol;
			}
			
			return temp->data;
		}
		
		void reverseRow(int rowNo)
		{
			if(rowCount < 0 or rowCount > rowNo)
			{
				cout << "\n\nInvalid row number.";
				return;
			}
			else
			{
				int rowCount = 0;
				
				Node<T> *temp = headRow;
				for(int i = 0; i < rowNo - 1; i++)
				{
					temp = temp->nextRow;
				}
				
				while(temp != nullptr)
				{
					temp = temp->nextCol;
					rowCount++;
				}
			}
		}

		void splitRow(int rowNo)
		{
			if(rowCount < 0 or rowCount > rowNo)
			{
				cout << "\n\nInvalid row number.";
				return;
			}
			else
			{
				int rowElements = 0;
				
				Node<T> *temp = headRow;
				for(int i = 0; i < rowNo - 1; i++)
				{
					temp = temp->nextRow;
				}
				
				while(temp != nullptr)
				{
					temp = temp->nextCol;
					rowElements++;
				}
				
				int mid = (rowElements + 1)/2;
				
				Node<T> *temp2 = headRow;
				for(int i = 0; i < rowNo - 1; i++)
				{
					temp2 = temp2->nextRow;
				}
				
				while(temp2 != nullptr)
				{
					temp2 = temp2->nextCol;
				}
				
				cout << "\n";
				for(int i = 0; i <= mid; i++)
				{
					cout << temp2->data << " ";
					temp2 = temp2->nextCol;
				}
				
				cout << "\n\n";
				for(int i = mid + 1; i < rowElements; i++)
				{
					cout << temp2->data << " ";
					temp2 = temp2->nextCol;
				}
			}
		}
		
	
		
		
		
		
		
		
		
		
		
		
};

template <typename T>
void menu(LinkedList2D<T> list1);
void unused_function();
