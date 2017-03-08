#ifndef PERSON_H
#define PERSON_H

struct PersonRec;

class PersonList {

public:
	PersonList();
	~PersonList();
	void AddToList();
	void ViewList();
	
private:
	PersonRec* head;	//points to to first node(highest bribe), or null if empty
	//return state of list
	bool IsEmpty();
	bool EndOfList(PersonRec *cPtr);
};
#endif