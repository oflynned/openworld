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
		void drawScene(BITMAP *Buffer);
		void drawObjects(BITMAP *Buffer);
		void drawBlocks(BITMAP *Buffer);
		
		void LoadMap(const char*filename,int level);
		int getLevel();
		void setLevel(int value);
		
		int getX();
		int getY();
		
		int x;
		int y;
		
		//sprites
		BITMAP *block;	
		BITMAP *g_l;	
		BITMAP *g_s;	
		BITMAP *g_r;
		
		BITMAP *pipe;
		
	private:
		int loadCounterX, loadCounterY;
		int mapSizeX, mapSizeY;
		int MapFile[2][100][100];
		int level;
};

#endif
