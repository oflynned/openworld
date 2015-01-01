#include "Map.h"

Map::Map(){
	
}

Map::~Map(){
	
}

void Map::Init(){
	loadCounterX = loadCounterY = 0;
	level = 0;
	Map::LoadMap("Resources/Maps/map1.txt",0);	//level 1
	Map::LoadMap("Resources/Maps/map2.txt",1);	//level 2
}

void Map::Update(){
	
}

void Map::Draw(BITMAP *Buffer){
	BITMAP *block = load_bitmap("Resources/Images/Environment/Blocks/Block.bmp",NULL);	
	BITMAP *g_l = load_bitmap("Resources/Images/Environment/Blocks/g_l.bmp",NULL);	
	BITMAP *g_s = load_bitmap("Resources/Images/Environment/Blocks/g_s.bmp",NULL);	
	BITMAP *g_r = load_bitmap("Resources/Images/Environment/Blocks/g_r.bmp",NULL);	
	
	for(int i=0;i<mapSizeX;i++){
		for(int j=0;j<mapSizeY;j++){
			//sky
			if(MapFile[level][i][j]==1){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,255));
			}
			//ground
			else if (MapFile[level][i][j]==2){
				draw_sprite(Buffer, g_s, (i*BlockSize), (j*BlockSize));
			}
			//platforms
			else if(MapFile[level][i][j]==3){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,255));
				draw_sprite(Buffer, g_s, (i*BlockSize), (j*BlockSize));
			}
			else if(MapFile[level][i][j]==4){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,255));
				draw_sprite(Buffer, g_l, (i*BlockSize), (j*BlockSize));
			}
			else if(MapFile[level][i][j]==5){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,255));
				draw_sprite(Buffer, g_r, (i*BlockSize), (j*BlockSize));
			}
			//level changer
			else if(MapFile[level][i][j]==6){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(255,255,0));
			}
		}
	}
}

void Map::LoadMap(const char*filename,int level){
	ifstream openfile(filename);
	if(openfile.is_open()){
		openfile >> mapSizeX >> mapSizeY;
		while(!openfile.eof()){
			openfile >> MapFile[level][loadCounterX][loadCounterY];
			loadCounterX++;
			
			if (loadCounterX>=mapSizeX){
				loadCounterX=0;
				loadCounterY++;
			}
		}
		loadCounterX = loadCounterY = 0;
	} //file is opened
	else allegro_message("Map file couldn't be found!");
}

int Map::getLevel(){
	return level;
}

void Map::setLevel(int value){
	level = value;
}
