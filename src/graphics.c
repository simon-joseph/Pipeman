#include <allegro5/allegro.h>
#include "graphics.h"
#include "mechanics.h"



MENU cfg_menu[] = {
      { "&Sound",       NULL,    NULL, D_DISABLED, NULL },
      { "Si&ze",        NULL,    NULL, 0,          NULL },
      { "Hall of Fame", NULL,    NULL, 0,          NULL },
      { NULL,           NULL,    NULL, 0,          NULL }
};

MENU game_menu[] = {
      { "&Play",         panel,   NULL, 0,          NULL },
      { "",              NULL,    NULL, 0,          NULL },
      { "E&xit",         quitter, NULL, 0,          NULL },
      { NULL,            NULL,    NULL, 0,          NULL }
};

MENU main_menu[] = {
      { "&Game",    NULL, game_menu, 0, NULL },
      { "&Options", NULL, cfg_menu,  0, NULL },
      { NULL,       NULL, NULL,      0, NULL }
};

  
void change_color(int r, int g, int b) {
    RGB col;
    col.r = r;
    col.g = g;
    col.b = b;
    vsync();
    set_color(254, &col);
}

int quitter() {
    return D_CLOSE;
}

void game() {
    set_palette(desktop_palette);
    buffer = create_bitmap(640, 480);
    bc_buffer = create_bitmap(640, 480);
    bmp = create_bitmap(30, 30);
    clear_to_color(bmp, 0);
    clear_to_color(buffer, 1);
    clear_to_color(bc_buffer, 3); 
    change_color(0, 0, 0);
    do_dialog(main_dialog, -1);
    
}
//char *msg_1[];


DIALOG main_dialog[] = {
      /* (dialog proc)   (x)    (y)  (w)  (h)
                         (fg)   (bg) (key)
                         (flags)(d1) (d2) (dp) */

      { d_clear_proc,    0,     0,   622, 480,
                         0,     3,   0,
                         0,     0,   0,   NULL },

      { d_menu_proc,     0,     0,   0,   0,
                         0,     0,   0,
                         0,     0,   0,   main_menu },
                         
    {d_box_proc,  9,    59,  605, 305,
                         1,     1,   0,   
                         0,     0,   0,   NULL  },
                         
    {d_box_proc,  0,    191,  10, 11,
                         1,     1,   0,   
                         0,     0,   0,   NULL  },
                         
    {d_box_proc,  612,  191,  10, 11,
                         1,     1,   0,   
                         0,     0,   0,   NULL  },
                         
      { d_text_proc,      10,  460,   0,   0,
                         8,     -1,  0,
                         0,     0,   0,    "To end already started game press 'Backspace'. To exit game press 'Esc'" },
                         

      { d_keyboard_proc, 0,     0,   0,   0,
                         0,     0,   0,
                         0,     0,   0,   quitter },
                         
    //{ d_edit_proc,       30,   30,   35,  10,
//                         255,  0,    0,    0,
//                         3,   0,    name },

      { NULL,            0,     0,   0,   0,
                         0,     0,   0,
                         0,     0,   0,   NULL }
};
