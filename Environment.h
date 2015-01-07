#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment{
	public:
		Environment();
		~Environment();
		
		BITMAP *cloud;
		
		int x;
		int y;
		
		void Init();
		void Update();
		void Draw(BITMAP *Buffer);
		void SetPosition();
};

#endif
