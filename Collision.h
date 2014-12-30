#ifndef COLLISION_H
#define COLLISION_H

#include <allegro.h>
#include <fstream>
#include <sstream>
#include "Global.h"

using namespace std;

class Collision{
	public:
		Collision();
		~Collision();
		
		void Init();
		void Update(BITMAP *Buffer, Player &player);
		void Draw(BITMAP *Buffer);
		
		void LoadCollisionMap(const char*filename);
		
		void PlatformCollision(BITMAP *Buffer, Player &player);
		
	private:
		int loadCounterX;
		int loadCounterY;
		int mapSizeX;
		int mapSizeY;
		int ColMapFile[40][15];
};

#endif
