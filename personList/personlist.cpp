#include "personlist.h"
#include <iostream>
using namespace std;

struct PersonRec
{
	char name[20];	//contains person's name
	int bribe;		//amount of bribe (highest bribe, first in list)
	PersonRec *link;//pointer to next PersonRec struct (Null if no next node)
};

PersonList::PersonList()
{
	head = nullptr;	
}

//deallocate memory for all the nodes you created with the program
//starts at the beginning of the list and deletes the nodes, one by one, until the last node is deleted
PersonList::~PersonList()
{
	PersonRec* currPtr = nullptr;
	while (head != nullptr)
	{
		currPtr = head->link;
		delete head;
		head = currPtr;
	}
	
}

void PersonList::AddToList()
{
	PersonRec* currPtr = nullptr;
	PersonRec* prev = nullptr;

	char aName[20];
	int aBribe;
	cout << "\nEnter the person's name: ";
	cin.getline(aName, 20);
	cout << "\nEnter the person's contribution: ";
	cin >> aBribe;

	//creates a new PersonRec node using dynamic memory allocation
	PersonRec* tempNode = new PersonRec;
	//assigns to its name and bribe data members the values input by the user
	strcpy_s(tempNode->name, 20, aName);
	tempNode->bribe = aBribe;

	tempNode->link = nullptr;

	//empty list
	if (IsEmpty())
	{
		head = tempNode;
	}
	else
	{
		currPtr = head;
		prev = nullptr;
		
		//find insert location
		while (!EndOfList(currPtr))
		{
			if (currPtr->bribe < tempNode->bribe)
			{
				break;
			}
			else
			{
				prev = currPtr;
				currPtr = currPtr->link;
			}
		}
		//insert as first node
		if (currPtr == head)
		{
			tempNode->link = head;
			head = tempNode;
		}
		//insert after head
		else
		{
			tempNode->link = currPtr;
			prev->link = tempNode;
		}
	}

}

void PersonList::ViewList()
{
	//prints the contents of list or "List is empty" if there are no nodes
	PersonRec* currPtr = head;
	int count = 1;

	if (currPtr == nullptr)
	{
		cout << "\nList is empty." << endl;
	}
	else
	{
		cout << "\n# Name Contribution" << endl;
		cout << "=======================================" << endl;

		while (currPtr != nullptr)
		{
			cout << count << " " << currPtr->name << " $" << currPtr->bribe << endl;
			count++;
			currPtr = currPtr->link;
		}
	}
}

bool PersonList::IsEmpty()
{
	return (head == nullptr);
}

bool PersonList::EndOfList(PersonRec *cPtr)
{
	return(cPtr == nullptr);
}
