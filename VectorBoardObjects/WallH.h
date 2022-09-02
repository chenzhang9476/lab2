
enum WallState { SOLID };

#include "BoardObjectH.h"

class Wall : public BoardObject
{
	/**

	   @brief this is wall class
	   @var color1: color one
   */
private:
	ObjectColours color1;

public:
	Wall(int start_x, int start_y) :BoardObject(start_x, start_y)
	{
		color1 = BLACK;
		myClass = A_WALL;
	};

	void touch();
};
