#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Node
{
public:
	int value;
	Node* prev;
	Node* next;
	
	Node()
	{
		prev = NULL;
		next = NULL;
	}
	
	~Node() //! can use this to delete a node.
	{
		cout << "Node value =  " << value << " has been deleted. " << endl; //! use more of this in the future for classes to delete classes.
		system("pause");
	}
};

class DoublyLinkedList
{
public:
	Node* head; // Head node, or point to first.
	
	DoublyLinkedList()
	{
		head = NULL;
	}
	
	~DoublyLinkedList()
	{
	}
	
	void Display()
	{
		int counter = 0;
		Node* current = head;
		
		while(current != NULL)
		{
			cout << "[" <<counter << "]" << current->value << endl;
			current = current->next;
			counter++;
		}
		
		cout << endl;
		cout << "Total numbers in the linked list : " << counter << endl;
	}
	
	void GetValueOfIndex(int index)
	{
		Node* current = head;
			
		if(index >= 0)
		{
			for(int i = 0; i < index; i++)
			{
				current = current->next;
			}
			cout << "Value of index [" << index << "] is = " << current->value << endl; 
			system("PAUSE");
		}
		else
		{
			cout << "Invalid Input!" << endl;
		}
	}
	
	void PushToBackIndex(int value)
	{
		
		if (head == NULL)
		{
			head = new Node();
			head->value = value;
		}
		else
		{
			Node* current = head;
			while(current->next != NULL)
			{
				current = current->next;
			}
			
			current->next = new Node();
			current->next->value = value;
			current->next->prev = current;
		}	
	}
	
	void PopFromBackIndex()
	{
		if (head != NULL)
		{
			Node* current = head;
			do
			{
				current = current->next;
			}
			while(current->next != NULL);
				
			if (current != head)
			{
				current->prev->next = NULL;
			}
			else
			{
				head = NULL;
			}
				
			delete current; //! use this to delete from ~Node
		}
	}
	
	void InsertAtSpecificIndex(int value, int index)
	{
		Node* current = head;
		for(int i = 0; i < index; i++)
		{
			if (current != NULL)
			{
				current = current->next;
			}
			else
			{
				return;
			}
		}
		if (current != NULL)
		{
			Node* nextNode = new Node();
			nextNode->value = value;
			if (current->prev == NULL)
			{
				nextNode->next = head;
				if (head != NULL)
				{
					head->prev = nextNode;
				}
				head = nextNode;
			}
			else
			{
				nextNode->prev = current->prev;
				nextNode->next = current;
				current->prev->next = nextNode;
				current->prev = nextNode;
			}
		}
		else
		{
			this->PushToBackIndex(value);
		}
	}
	
	void RemoveAtSpecificIndex(int index)
	{
		Node* current = head;
		for(int i = 0; i < index; i++)
		{
			if (current != NULL)
			{
				current = current->next;
			}
			else
			{
				return;
			}
		}
				
		if (current != NULL)
		{
			if (current->next != NULL)
			{
				current->next->prev = current->prev;
			}
			if (current->prev == NULL)
			{
				head = current->next;
			}
			else
			{
				current->prev->next = current->next;
			}
			delete current;
		}
	}
	
	void SwapIndex(int index1, int index2)
	{
		if (index1 == index2)
		{
			return;
		}
	
		Node* value1 = head;
		Node* value2 = head;
		for(int i = 0; i < index1; i++)
		{
			if(value1->next != NULL)
			{
				value1 = value1->next;
			}
			else
			{
				return;
			}
		}
				
		for(int i = 0; i < index2; i++)
		{
			if(value2->next != NULL)
			{
				value2 = value2->next;
			}
			else
			{
				return;
			}
		}
		
		int temp = value1->value;
		value1->value = value2->value;
		value2->value = temp;
	}
};

void Top()
{
	cout << "     ======================     " << endl;
	cout << "     * Doubly Linked List *     " << endl;
	cout << "     ======================     " << endl;
}

void DoChoice(int choice, DoublyLinkedList* list)
{
	if(choice == 1)
	{
		int index;
		cout << "Input index : ";
		cin >> index;
		if (cin.good())
		{
			if (index >= 0)
			{
				list->GetValueOfIndex(index);
			}
		}
	}
	
	else if(choice == 2)
	{
		int value;
		cout << "Input value : ";
		cin >> value;
		if (cin.good())
		{
			list->PushToBackIndex(value);
		}
	}
	
	else if(choice == 3)
	{
		list->PopFromBackIndex();
	}

	else if(choice == 4)
	{
		int index, value;
		cout << "Input index : ";
		cin >> index;
		cout << "Input value : ";
		cin >> value;
		if (cin.good())
		{
			if (index >= 0)
			{
				list->InsertAtSpecificIndex(value, index);
			}
		}
	}
	
	else if(choice == 5)
	{
		int index;
		cout << "Input index : ";
		cin >> index;
		if (cin.good())
		{
			if (index >= 0)
			{
				list->RemoveAtSpecificIndex(index);
			}
		}
	}
	
	else if(choice == 6)
	{
		int index1, index2;
		cout << "Input first index : ";
		cin >> index1;
		cout << "Input second index : ";
		cin >> index2;
			
		if (cin.good())
		{
			if (index1 >= 0 && index2 >= 0)
			{
				list->SwapIndex(index1, index2);
			}
		}
	}
}

int main()
{	
	DoublyLinkedList* numberList = new DoublyLinkedList();
	
	srand(time(NULL));
	numberList->PushToBackIndex(20);
	numberList->PushToBackIndex(22);
	numberList->PushToBackIndex(25);
	numberList->PushToBackIndex(28);
	numberList->PushToBackIndex(29);
	numberList->PushToBackIndex(31);
	numberList->PushToBackIndex(43);
	numberList->PushToBackIndex(27);
	numberList->PushToBackIndex(15);
	numberList->PushToBackIndex(96);
	numberList->PushToBackIndex(120);
	bool exit = false;
	do
	{
		system("cls");
		int choice;
		Top();
		cout << endl;
		numberList->Display();
		cout << endl; 
		cout << "================================" << endl;
		cout << "  1. Get value from index       " << endl;
		cout << "  2. Push to back value         " << endl;
		cout << "  3. Pop from back value        " << endl;
		cout << "  4. Insert at specific index   " << endl;
		cout << "  5. Remove at specific index   " << endl;
		cout << "  6. Swap Index                 " << endl;
		cout << " -1. Exit                       " << endl;
		cout << "================================" << endl;
		cout << "What would you like to do? : ";
		cin >> choice;
		cout << endl;
		if(cin.good())
		{
			if (choice == -1)
			{
				exit = true;
			}
			else
			{
				DoChoice(choice, numberList);
			}
		}
		
		cin.clear();
		cin.ignore(1000, '\n');
		
	} while(!exit);
	
	delete numberList; //! use this to delete from ~Node
	return 0;
}

//! Name : Muhamad Luqman bin Shamsuddin
//! Student ID : 0114642
