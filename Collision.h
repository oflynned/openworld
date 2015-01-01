#ifndef COLLISION_H
#define COLLISION_H

#include <fstream>
#include <sstream>
#include "Global.h"
#include "Map.h"
#include "Player.h"

using namespace std;

class Collision{
	public:
		Collision();
		~Collision();
		
		void Init();
		void Update(BITMAP *Buffer, Player &player, Map &map);
		void Draw(BITMAP *Buffer);
		
		void LoadCollisionMap(const char*filename,int level);
		void LevelEnd(Player &player, Map &map);
		void PlatformCollision(BITMAP *Buffer, Player &player, Map &map);
		
	private:
		int width;
		int height;
		int loadCounterX;
		int loadCounterY;
		int mapSizeX;
		int mapSizeY;
		int ColMapFile[2][40][15];
};

#endif
