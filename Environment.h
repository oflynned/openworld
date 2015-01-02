#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

class Environment{
	public:
		Environment();
		~Environment();
		
		//images
		BITMAP *background;
		BITMAP *pipe;
		BITMAP *cloud;
		BITMAP *character;
		
		//functions
		void Draw();
		void Init();
};

#endif
