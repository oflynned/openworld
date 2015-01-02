#include "Includes.h"

volatile long counter;
bool done = false;
void Increment(){
	counter++;
}

int main(){
	allegro_init();
	install_keyboard();
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT, "A");
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED,ScreenWidth,ScreenHeight,0,0);
	LOCK_VARIABLE(counter);
	LOCK_FUNCTION(Increment);
	install_int_ex(Increment,BPS_TO_TIMER(60));
	
	BITMAP *Buffer = create_bitmap(BufferWidth,BufferHeight);
	
	Player player;
	Camera camera;
	Map map;
	Collision collision;
	Environment environment;
	
	player.Init();
	camera.Init();
	map.Init();
	collision.Init();
	environment.Init();
	
	while(!done){
		while(counter>0){
			//input
			if (key[KEY_ESC]){
				done=true;
			}
			//update
			map.Update();
			player.Update();
			collision.Update(Buffer, player, map);
			camera.Update(player.x,player.y);
			counter--;
		}
		//draw
		map.Draw(Buffer);
		player.Draw(Buffer);
		player.debugValues(Buffer,map,player);
		camera.Draw(Buffer);
		//gets to here
		environment.Draw(Buffer,environment.cloud);
		clear_bitmap(Buffer);		
	}
	//clear resources
	destroy_bitmap(environment.cloud);
	
	return 0;
}
END_OF_MAIN()

