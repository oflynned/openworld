#include "Global.h"
#include "Environment.h"
#include <cstdlib> 
#include <ctime>

Environment::Environment(){
	
}

Environment::~Environment(){
	
}

void Environment::Init(){	
	//sprites
	cloud = load_bitmap("Resources/Images/Environment/Background/clouds_noblur.bmp",NULL);
	cloudNo = 5;
	
	//random location generation
	srand((unsigned)time(0));
	x = (rand()%(BufferWidth));
	y = (rand()%150);
	origX = 0;
}

void Environment::Update(){
	x+=1;
	if(x>=BufferWidth){
		x=origX;
	}
		
}

void Environment::Draw(BITMAP *Buffer){
	draw_sprite(Buffer,cloud,x,y);
}

void SetPosition(){
	
}
