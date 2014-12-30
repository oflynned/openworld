#include "Map.h"

Map::Map(){
	
}

Map::~Map(){
	
}

void Map::Init(){
	loadCounterX = loadCounterY = 0;
	//Map::LoadMap("Map1.txt");
	Map::LoadMap("map_fallvel.txt");
}

void Map::Update(){
	
}

void Map::Draw(BITMAP *Buffer){
	for(int i=0;i<mapSizeX;i++){
		for(int j=0;j<mapSizeY;j++){
			if(MapFile[i][j]==1){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,255));
			}
			else if (MapFile[i][j]==2){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(0,255,0));
			}
			else if(MapFile[i][j]==3){
				rectfill(Buffer, i*BlockSize, j*BlockSize, i*BlockSize + BlockSize, j*BlockSize + BlockSize,makecol(255,0,255));
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
