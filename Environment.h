#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Player.h"

class Environment{
	public:
		Environment();
		~Environment();
		
		BITMAP *cloud;
		BITMAP *mountains;
		
		int x;
		int y;
		
		void Init();
		void Update();
		void Draw(BITMAP *Buffer);
		void SetPosition();
};

#endif
