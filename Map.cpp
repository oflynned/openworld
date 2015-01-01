#include "Map.h"

Map::Map(){
	
}

Map::~Map(){
	
}

void Map::Init(){
	loadCounterX = loadCounterY = 0;
	Map::LoadMap("Resources/Maps/Map1.txt");
	
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
			if(MapFile[i][j]==1){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,255));
			}
			//ground
			else if (MapFile[i][j]==2){
				draw_sprite(Buffer, g_s, (i*BlockSize), (j*BlockSize));
			}
			//platforms
			else if(MapFile[i][j]==3){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,255));
				draw_sprite(Buffer, g_s, (i*BlockSize), (j*BlockSize));
			}
			else if(MapFile[i][j]==4){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,255));
				draw_sprite(Buffer, g_l, (i*BlockSize), (j*BlockSize));
			}
			else if(MapFile[i][j]==5){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,255));
				draw_sprite(Buffer, g_r, (i*BlockSize), (j*BlockSize));
			}
			
		}
	}
}

void Map::LoadMap(const char*filename){
	ifstream openfile(filename);
	if(openfile.is_open()){
		openfile >> mapSizeX >> mapSizeY;
		while(!openfile.eof()){
			openfile >> MapFile[loadCounterX][loadCounterY];
			loadCounterX++;
			
			if (loadCounterX>=mapSizeX){
				loadCounterX=0;
				loadCounterY++;
			}
		}
		loadCounterX = loadCounterY = 0;
	} //file is opened
	else{
		allegro_message("Map file couldn't be found!");
	}//file not opened
}
