#include "Collision.h"

Collision::Collision(){

}

Collision::~Collision(){

}

void Collision::Init(){
	width = 15; 
	height = 28;
	loadCounterX=loadCounterY=0;
	Collision::LoadCollisionMap("Resources/Collision Maps/colmap1.txt",0);
	Collision::LoadCollisionMap("Resources/Collision Maps/colmap2.txt",1);
	}

void Collision::Update(BITMAP *Buffer, Player &player, Map &map){
	Collision::PlatformCollision(Buffer, player, map);
	Collision::LevelEnd(player,map);
}

void Collision::Draw(BITMAP *Buffer){
	
}

void Collision::LoadCollisionMap(const char*filename,int level){
	ifstream openfile(filename);
	if(openfile.is_open()){
		openfile >> mapSizeX >> mapSizeY;
		while(!openfile.eof()){
			openfile>>ColMapFile[level][loadCounterX][loadCounterY];
			loadCounterX++;
			if(loadCounterX>=mapSizeX){
				loadCounterX=0;
				loadCounterY++;
			}
		}
		loadCounterX=loadCounterY=0;
	}
	else{
		allegro_message("Cannot find collision map file");
	}
}

void Collision::PlatformCollision(BITMAP *Buffer, Player &player, Map &map){
	for(int i =0;i<mapSizeX;i++){
		for(int j = 0; j<mapSizeY;j++){
			if(ColMapFile[map.getLevel()][i][j]==1){
				if(player.x>i*BlockSize+BlockSize||player.y>j*BlockSize+BlockSize||player.x2<i*BlockSize||player.y2<j*BlockSize){
					//falling from platforms
					player.Platform=false;
				}
				else
				{
					//falling onto a platform
					if(player.vDir==2&&player.y-player.vely<=j*BlockSize){
						player.y=j*BlockSize-height;
						player.y2=player.y+height;
						player.vely=0;
						player.Platform=true;
						player.Jump=true;
					}
					//disable jumping through playforms
					else if(player.vDir==1){
						player.y+=player.speed*2;
						player.y2=player.y+height;
						player.vely=0;
						player.Platform=false;
						player.Jump=false;
					}
					//jump rightwards
					if(player.hDir==1 && player.Platform == false){
						player.x-=player.speed;
						player.x2=player.x+width;
					}
					//jump leftwards
					else if(player.hDir==2 && player.Platform == false){
						player.x+=player.speed;
						player.x2=player.x+width;
					}
				}
			}
		}
	}
}

void Collision::LevelEnd(Player &player,Map &map){
	for(int i=0;i<mapSizeX;i++){
		for(int j=0;j<mapSizeY;j++){
			if(ColMapFile[map.getLevel()][i][j]==2){
				if(player.x>i*BlockSize+BlockSize||player.y>j*BlockSize+BlockSize||player.x2<i*BlockSize||player.y2<j*BlockSize){
					//no collision
				}
				else{
					int level=map.getLevel();
					level++;
					map.setLevel(level);
					if(level>1){
						map.setLevel(0);
					}
					player.x=player.origX;
					player.y=player.origY;
					clear_to_color(screen,makecol(0,0,0));
					rest(150);
				}
			}
		}
	}
}
