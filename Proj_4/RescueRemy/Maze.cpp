#include "Maze.h"
#include <queue>
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;


void Maze::print_dfsExitPath()
{
   stack<Position> path;
   Position current, nbr;
   // FILL IN MISSING CODE


}

void Maze::printShortestPath()
{
   queue<Position> Q;
   Position current, nbr;
   // Allocate the two dimensional predecessor array
   // The predecessor of Position P is given by
   // predecessor[P.row][P.col]
   Position** predecessor = new Position *[size];
   for(int i = 0; i < size; ++i) {
      predecessor[i] = new Position[size];
      for(int j = 0; j < size; ++j)
	 predecessor[i][j] = NULLPOS;
   }
   // FILL IN MISSING CODE

}

