#include "Player.h"
#include "Global.h"
#include "Map.h"

Player::Player(){
	
}

Player::~Player(){
	
}

void Player::Init(){	
	x = 120;
	y = (ScreenHeight)/2;
	origX = x;
	origY = y;
	x2=x+width;
	y2=y+height;
	velx = 0;
	vely = 0;
	speed = 2;
	jumpspeed = -15;
	gravity=1;
	width = 10;
	height = 10;
	Jump=false;
	Platform=false;
	hDir=0;
	vDir=2;	
}

void Player::Update(){
	Player::Controls();
	Player::SetPosition();
}

void Player::Draw(BITMAP *Buffer){
	//player sprite
	rectfill(Buffer,x,y,x+width,y+height,makecol(255,0,0));
	
}

void Player::debugValues(BITMAP *Buffer, Map &map, Player &player){
	//debug
	//movement values
	rect(Buffer, player.x - 110,player.y - 150,player.x - 30,player.y - 85,makecol(255, 0, 0));
	textprintf_ex(Buffer, font, player.x - 100, player.y - 140, makecol(255, 0, 0), -1, "dx: %d", velx);
	textprintf_ex(Buffer, font, player.x - 100, player.y - 130, makecol(255, 0, 0), -1, "dy: %d", (vely*-1));
	textprintf_ex(Buffer, font, player.x - 100, player.y - 120, makecol(255, 0, 0), -1, "x: %d", x);
	textprintf_ex(Buffer, font, player.x - 100, player.y - 110, makecol(255, 0, 0), -1, "y: %d", y);
	textprintf_ex(Buffer, font, player.x - 100, player.y - 100, makecol(255, 0, 0), -1, "level: %d", (map.getLevel()+1));	
}

void Player::Controls(){	
	if(key[KEY_RIGHT]){
		//draw_sprite(Buffer, p_r, x, y);
		if(x < (BufferWidth-width)){
			velx = speed;
			hDir = 1;
		}
		else velx = 0;
	}
	else if(key[KEY_LEFT]){
	//	draw_sprite(Buffer, p_l, x, y);
		if(x>0){
			velx = -speed;
			hDir = 2;
		}
		else velx=0;
	}
	else{
		velx = 0;
		hDir = 0;
	}
	if (key[KEY_UP]&&Jump==true){
		vely=jumpspeed;
		Platform=false;
		Jump=false;
		vDir=1;
	}
}

void Player::SetPosition(){
	if(vely>=0){
		vDir=2;
	}
	if(Platform==false){
		vely+=gravity;
	}
	else{
		vely=0;
	}
	x+=velx;
	y+=vely;
	x2=x+width;
	y2=y+height;
}

