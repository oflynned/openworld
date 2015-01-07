#ifndef MAP_H
#define MAP_H

#include <allegro.h>
#include "Global.h"
#include <fstream>
using namespace std;

class Map{
	public:
		Map();
		~Map();
		
		void Init();
		void Update();
		void Draw(BITMAP *Buffer);
		
		void LoadMap(const char*filename,int level);
		int getLevel(int level);
		void setLevel(int value);
		
		int level;
		
		//sprites
		BITMAP *block;	
		BITMAP *g_l;	
		BITMAP *g_s;	
		BITMAP *g_r;
		
	private:
		int loadCounterX, loadCounterY;
		int mapSizeX, mapSizeY;
		int MapFile[2][100][100];
		
};

#endif
