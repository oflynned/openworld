#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Player.h"

class Environment{
	public:
		Environment();
		~Environment();
		
		//images
		BITMAP *cloud;
		BITMAP *background;
		BITMAP *pipe;
		
		BITMAP *character_r[3];
		BITMAP *character_l[3];
		BITMAP *character_s[2];
		BITMAP *enemy_r[3];
		BITMAP *enemy_l[3];
		BITMAP *enemy_s[2];
	
		//functions
		void Init();
		void Update();
		void Draw(BITMAP *Buffer,BITMAP *cloud);
};

#endif
