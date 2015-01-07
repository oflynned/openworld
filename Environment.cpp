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
	
	//random location generation
	srand((unsigned)time(0));	
	x = (rand()%200)+1;
	y = (rand()%200)+1;
}

void Environment::Update(){
		
}

void Environment::Draw(BITMAP *Buffer){
	draw_sprite(Buffer,cloud,x,y);
}

void SetPosition(){
	
}
