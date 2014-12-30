#include <allegro.h>
#include "Global.h"

class Camera{
	public:
		Camera();
		~Camera();
		
		void Init();
		void Update(int x, int y);
		void Draw(BITMAP *Buffer);
		
		void SetPosition(int x, int y);
	
	private:
		int cameraX;
		int cameraY;
};
