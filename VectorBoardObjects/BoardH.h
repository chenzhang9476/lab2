#define ROWS 20
#define COLUMNS 20

#include <vector>
#include  "BoardObjectH.h"
#include  "VectorBoardObjects.h"
#include  "PlayerH.h"
#include  "WallH.h"
#include  "CookieH.h"

typedef  VectorBoardObjects* p_ListBoardObjects;

/**

	@brief this is Board class
	@param the_rows: total rows
	@param the_cols: total columns
	@param lives: total lives
	@param mySpace:the space
	@param player_id_x : player x axis
	@param player_id_y : player y axis
	@param startPlayer: a point toward start player
	@param currentScore: the current score
*/
class Board
{

private:

	int the_rows, the_cols;

	bool setOK;
	bool gameOn;
	int lives;
	p_ListBoardObjects   mySpace[ROWS][COLUMNS];
	int player_id_x;
	int player_id_y;
	Player* startPlayer;
	int currentScore;


public:

	Board(int rows, int cols)
	{
		if ((ROWS >= rows) && (COLUMNS >= cols))
		{
			setOK - true; the_rows = rows; the_cols = cols;
			lives = 3000000; gameOn = true;
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
				{
					BoardObject* aBackground = new BoardObject(i, j);
					p_ListBoardObjects aList = new VectorBoardObjects(aBackground);
					mySpace[i][j] = aList;
				}
			player_id_x = the_rows / 2;
			player_id_y = the_cols / 2;
			startPlayer = new Player(player_id_x, player_id_y);
			currentScore = 0;

			(mySpace[player_id_x][player_id_y])->addOne(startPlayer);

			for (int i = 1; i < the_rows - 1; i++)
			{
				Wall* aWall = new Wall(i, 1);
				(mySpace[i][1])->addOne(aWall);
				aWall = new Wall(i, the_cols - 2);
				(mySpace[i][the_cols - 2])->addOne(aWall);
			}

			for (int i = 1; i < the_rows - 1; i = i + 2)
			{
				Cookie* aCookie = new Cookie(i, 0);
				(mySpace[i][0])->addOne(aCookie);
				aCookie = new Cookie(i, the_cols - 1);
				(mySpace[i][the_cols - 1])->addOne(aCookie);
			}
		}
		else
			setOK = false;

	};

	bool setBoardOK() { return setOK; };

	void paint();

	void move(char command);

	bool IamAlive() {
		if (0 < lives) { lives--; return true; }
		else return false;
	}
};