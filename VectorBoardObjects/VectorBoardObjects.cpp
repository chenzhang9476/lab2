#include <iostream>
#include "VectorBoardObjects.h"
#include "BoardObjectH.h"
using namespace std;
/**
	@brief this is VectorBoardObject

*/

VectorBoardObjects::VectorBoardObjects(p_BoardObject newOne) :list()
{
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	list.insert(it, newOne);
}

p_BoardObject VectorBoardObjects::fitrstObject()
{
	if (0 < list.size())
	{
		internalIterator = list.begin();
		return (*internalIterator);
	}
	else
		return NULL;
}


void VectorBoardObjects::addOne(p_BoardObject newOne)
{
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	list.insert(it, newOne);
}

p_BoardObject VectorBoardObjects::nextObject()
{
	internalIterator++;
	if (internalIterator < list.end())
	{
		return (*internalIterator);
	}
	else
		return NULL;
}

void VectorBoardObjects::elimiantePlayer()
{
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	while (it < list.end())
	{
		if (A_PLAYER == (*it)->get_Type())
		{
			list.erase(it); return;
		}
		it++;
	}

	return;
}


bool VectorBoardObjects::isThereAWall()
{
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	while (it < list.end())
	{
		if (A_WALL == (*it)->get_Type())
		{
			return true;
		}
		it++;
	}

	return false;
}


int VectorBoardObjects::cookieValue()
{
	int temp = 0;
	std::vector <p_BoardObject>::iterator it;
	it = list.begin();
	while (it < list.end())
	{
		if (A_COOKIE == (*it)->get_Type())
		{
			temp = ((Cookie*)(*it))->get_value();
			list.erase(it);
			return temp;
		}
		it++;
	}

	return temp;
}
//void main() {
	// Classify a variable
	//p_BoardObject init_object = new BoardObject(1,1);
	//Constructor
	//VectorBoardObjects vectorobject(init_object);
	//fitrstObject
	//p_BoardObject first = vectorobject.fitrstObject();
	//cout << "The first object memory address is : " << first << endl;
	//Get size 
	//int next = vectorobject.isThereAWall();
	//cout << "The wall value is : " << next << endl;
	//
	//for (int i = 0; i < 5; i++) {
		//add One
		//vectorobject.addOne(new BoardObject(1, 1));
	//}
	//for (int i = 0; i < 5; i++) {
	//next object
		//p_BoardObject next = vectorobject.nextObject();
		//cout << "The next object memory address is : " << next << endl;
	//}
	
//}
