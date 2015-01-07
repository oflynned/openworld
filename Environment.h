#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment{
	public:
		Environment();
		~Environment();
		
		BITMAP *cloud;
		
		int x;
		int y;
		
		int cloudNo;
		
		int origX;
		int origY;
		
		void Init();
		void Update();
		void Draw(BITMAP *Buffer);
		void SetPosition();
};

#endif
