#include "Player.h"
#include "Global.h"

Player::Player(){
	
}

Player::~Player(){
	
}

void Player::Init(){
	x = (ScreenWidth-width)/8;
	//x = (BufferWidth-BlockSize);
	y = (ScreenHeight-height)/2;
	x2=x+width;
	y2=y+height;
	velx = 0;
	vely = 0;
	speed = 2;
	jumpspeed = -15;
	gravity=1;
	width=10;
	height=10;
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
	rectfill(Buffer,x,y,x+width,y+height,makecol(255,0,0));
}

void Player::Controls(){
	if(key[KEY_RIGHT]){
		if(x < (BufferWidth-width)){
			velx = speed;
			hDir = 1;
		}
		else velx = 0;
	}
	else if(key[KEY_LEFT]){
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
