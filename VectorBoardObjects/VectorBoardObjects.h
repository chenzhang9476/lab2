#pragma once
#include <vector>
#include  "BoardObjectH.h"
#include  "PlayerH.h"
#include  "CookieH.h"
//#include  "WallH.h"
#ifndef H_LIST_OF_OBJECTS
#define H_LIST_OF_OBJECTS
typedef BoardObject* p_BoardObject;

class VectorBoardObjects
{
	std::vector <p_BoardObject> list;
	std::vector <p_BoardObject>::iterator internalIterator;
public:
		VectorBoardObjects(p_BoardObject newOne);
		p_BoardObject fitrstObject();
		p_BoardObject nextObject();
		void addOne(p_BoardObject newOne);
		void elimiantePlayer();
		bool isThereAWall();
		int cookieValue();
};
#endif