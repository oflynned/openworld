#include "Player.h"
#include "Global.h"

Player::Player(){
	
}

Player::~Player(){
	
}

void Player::Init(){
	//sprites
	p_r = load_bitmap("Resources/Images/Characters/p_r.bmp",NULL);
	p_l = load_bitmap("Resources/Images/Characters/p_l.bmp",NULL);
	
	x = (ScreenWidth-width)/8;
	//x = (BufferWidth-BlockSize);
	y = (ScreenHeight-height)/2;
	x = origX;
	y = origY;
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

void Player::debugValues(BITMAP *Buffer){
	//debug
	//movement values
	textprintf_centre_ex(Buffer, font, ScreenWidth / 16, ScreenHeight / 32, makecol(255, 0, 0), -1, "vely: %d", vely);
	textprintf_centre_ex(Buffer, font, ScreenWidth / 16, ScreenHeight / 16, makecol(255, 0, 0), -1, "velx: %d", velx);
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

