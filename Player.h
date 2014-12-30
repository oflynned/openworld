#include <allegro.h>

class Player{
	public:
		Player();
		~Player();
		
		void Init();
		void Update();
		void Draw(BITMAP *Buffer);
		
		void Controls();
		void SetPosition();
		
		int width;
		int height;
		int x;
		int y;
		int x2;
		int y2;
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
