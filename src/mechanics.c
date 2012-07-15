#include <allegro5/allegro.h>
#include "graphics.h"     
#include "mechanics.h"  
//#include "bfs.h"

int loop(int pos, int x, int y) {
    int done=1;
    if(pos == 6&&done) {
        array[x+1][y] = 1;
        array[x+1][y+2] = 1;
        array[x][y+1] = 0;
        array[x+2][y+1] = 0;
        array[x][y] = 7;
        done = 0;
    }
    if(pos == 7&&done) {
        array[x+1][y] = 0;
        array[x+1][y+2] = 0;
        array[x][y+1] = 1;
        array[x+2][y+1] = 1;
        array[x][y] = 6;
        done = 0;
    }
    if(pos == 3&&done) {
        array[x+1][y] = 0;
        array[x+1][y+2] = 1;
        array[x][y] = 4;
        done = 0;
    }
    if(pos == 2&&done) {
        array[x][y+1] = 0;
        array[x+2][y+1] = 1;
        array[x][y] = 3;
        done = 0;
    }   
    if(pos == 4&&done) {
        array[x+2][y+1] = 0;
        array[x][y+1] = 1;
        array[x][y] = 5;
        done = 0;
    }
    if(pos == 5&&done) {
        array[x+1][y+2] = 0;
        array[x+1][y] = 1;
        array[x][y] = 2;
        done = 0;
    }
    return D_O_K;
}

int g_init() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<20; j++) {
            array[(j*3)+1][(i*3)+1] = 1;
            array[(j*3)+2][(i*3)+2] = 0;
            array[j*3][(i*3)+2] = 0;
            array[(j*3)+2][i*3] = 0;
            array[(j*3)][i*3] = 2 + (rand() % 5);
            loop(array[j*3][i*3], j*3, i*3);
            loop(array[j*3][i*3], j*3, i*3);
            loop(array[j*3][i*3], j*3, i*3);
            loop(array[j*3][i*3], j*3, i*3);
        }
    }
    return D_O_K;
}


int d_loop() {
    for(int i=0; i<30; i++) {
        for(int j=0; j<60; j++) {
            if(array[j][i] == 1)
                rectfill(buffer, 12+(j*10), 62+(i*10), 20+(j*10), 70+(i*10), 1);
            else
                rectfill(buffer, 12+(j*10), 62+(i*10), 20+(j*10), 70+(i*10), 3);  
            if(array[j][i] == -1) { 
                rectfill(buffer, 12+(j*10), 62+(i*10), 20+(j*10), 70+(i*10), 4);
                array[j][i]=1; 
            }
            
        }
    }
    blit(buffer, screen, 12, 62, 12, 62, 600, 300);
  return D_O_K;
}

int main_mech() { 
    int x=1, y=13, check=1, pocz=1, path=1;       
    for(int i=0; i<30; i++) {
        for(int j=0; j<60; j++) {
            if(array[j][i] == -1)
                array[j][i]=1;
        }
    }
               
        if(array[0][13]!=1) {
            pocz=0;
        }
        else {  
            array[0][13]=-1;
            array[1][13]=-1; 
            while(pocz&&path) {
                check=1;             
                if(array[x+1][y] == 1&&check) {                      /*na prawo patrz*/
                    array[x+1][y] = -1;
                    x++;
                    check=0;
                    if((x)==(59)&&(y)==(13)){                 /*Ostatni krok bedzie w prawo*/
                        path=0;     
                    }                                  
                }
                if(array[x][y+1]==1&&check){                      /*do gory patrz*/
                    array[x][y+1]=-1;
                    y++;
                    check=0;
                }
                if(array[x-1][y]==1&&check){                      /*na lewo patrz*/
                    array[x-1][y]=-1;
                    x--;
                    check=0;
                }
                if(array[x][y-1]==1&&check){                       /*w dol patrz*/
                    array[x][y-1]=-1;
                    y--;
                    check=0;
                }
                if(check) {
                    pocz=0;
                }
            }               
        }    
    return path;
}

int read_mouse(int par_x, int par_y) {
    if(par_x>12&&par_x<612&&par_y>62&&par_y<362) {
        par_x = (par_x - 12)/30;
        par_y = (par_y - 62)/30;
        loop(array[par_x*3][par_y*3], par_x*3, par_y*3);
        brk=main_mech();
        d_loop();      
        while(brk) {
            if(!(mouse_b & 1)) {
                brk=0;
                loop_mouse();
                
            }
        }
        if(!brk) {
            jakiestamcostam();
            end_theme();
        }                    
    }
    else {
        brk=1;
        while(brk) {
            if(!(mouse_b & 1)) {
                brk=0;
                loop_mouse();
            }
        }   
    }
    return D_O_K;
}

void loop_mouse() {
    end=1;
    while(end) {
            if(mouse_b & 1) {
                end=0;
                read_mouse(mouse_x, mouse_y);            
            }
            if(!(rand() % 9000000)&&!(rand() % 40)) {
                int rad = rand() % 30;
                circlefill(bc_buffer, rad + rand() % (640-(2*rad)), rad + rand() % (480-(2*rad)), rad,  makecol(rand() % 255, rand() % 255, rand() % 255));
                rectfill(bc_buffer, 0, 191, 10, 201, 1);
                rectfill(bc_buffer, 612, 191, 621, 201, 1);
                blit(screen, buffer, 9, 59, 9, 59, 605, 305);
                blit(buffer, bc_buffer, 9, 59, 9, 59, 605, 305);
                blit(bc_buffer, screen, 0, 0, 0, 0, 640, 480);
                
            }
            if(key[KEY_BACKSPACE]||key[KEY_ESC]) {
                end=0;
            }
    }
}

void end_theme() {
    while(!keypressed()) {
        textout_centre_ex(screen, font, " Lucky winner!! ", SCREEN_W/2, SCREEN_H/2, rand() % 10, 1);
        textout_centre_ex(screen, font, "!!press space!!", SCREEN_W/2, SCREEN_H/2+10, rand() % 10, 1);
        rest(100);
    }
}

int panel() {
    g_init();
    main_mech();
    d_loop();
    loop_mouse();
  return D_REDRAW;
}

void jakiestamcostam() {
    for(int i=0; i<30; i++) {
        for(int j=0; j<60; j++) { 
            if(array[j][i] == -1) { 
                circlefill(screen, 16+(j*10), 66+(i*10), 40, 10);
                rest(1000); 
            }            
        }
    }
}
