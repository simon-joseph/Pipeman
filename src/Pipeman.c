/*
 ============================================================================
 Name        : Pipeman.c
 Author      : Szymon Laszczynski
 Version     :
 Copyright   : Copyright © 2012. Szymon Laszczynski

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include "Pipeman.h"
#include "graphics.h"

int main() {
	init();
	game();
	deinit();
	return 0;
} END_OF_MAIN();

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	show_mouse(screen);

	set_window_title("PIPEMAN");
}

void deinit() {
    destroy_bitmap(bmp);
	clear_keybuf();
}

