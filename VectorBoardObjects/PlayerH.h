#ifndef H_PLAYER
#define H_PLAYER
#include <iostream>

enum PlayerState { ALIVE, DEAD };

#include "BoardObjectH.h"

class Player : public BoardObject
{
	/**

	   @brief this is player class
	   @var status: player State
	   @var color1: color one
	   @var color2: color two
   */
private:
	PlayerState status;
	ObjectColours color1;
	ObjectColours  color2;

public:
	Player(int start_x, int start_y) :BoardObject(start_x, start_y)
	{
		status = ALIVE;
		color1 = RED;
		color2 = BLUE;
		myClass = A_PLAYER;
	};

	virtual void touch();
};
#endif#pragma once
