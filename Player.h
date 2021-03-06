#ifndef PLAYER_H
#define PLAYER_H

#include <allegro.h>
#include "map.h"

class Player{
	public:
		Player();
		~Player();
		
		BITMAP *p_r;
		BITMAP *p_l;
		
		void Init();
		void Update();
		void Draw(BITMAP *Buffer);
		
		void debugValues(BITMAP *Buffer,Map &map, Player &player);
		
		void Controls();
		void SetPosition();
				
		int width;
		int height;
		int x;
		int y;
		int x2;
		int y2;
		int origX;
		int origY;
		int velx;
		int vely;
		int speed;
		int hDir; //if = 1 right, if = 2  left, if = 0 doing nothing
		int vDir; //if = 1  up, if = 2 down due to gravity, if = 0 doing nothing
		int jumpspeed;
		int gravity;
		bool Jump; //if true, can jump; if false, not on ground
		bool Platform; //activates gravity if true
};

#endif
