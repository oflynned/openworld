#include "Global.h"
#include "Environment.h"
#include "Player.h"

Environment::Environment(){
	
}

Environment::~Environment(){
	
}

void Environment::Init(){
	cloud = load_bitmap("Resources/Images/Characters/clouds.bmp",NULL);
}

void Environment::Draw(BITMAP *Buffer, BITMAP *cloud){
	draw_sprite(Buffer, cloud, 200, 200);
}


