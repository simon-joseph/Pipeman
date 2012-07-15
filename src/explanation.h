/*

    LP      Box Position
    0           0 0 0
                1 1 1
                0 0 0
 
    1           0 1 0
                0 1 0
                0 1 0
                
    2           0 1 0
                1 1 0
                0 0 0
                
    3           0 1 0
                0 1 1
                0 0 0

    4           0 0 0
                0 1 1
                0 1 0
                
    5           0 0 0
                1 1 0
                0 1 0
          40 (28->600)
            |       
      12 (0->572)
      |     |
      0 1 2 3 4 5 6 7 8 9 ...
                                                                        __ 62  (0->272)
0     i 0 0 i 0 0 i 0 0 i 0 0 i 0 0 i 0 0 i 0 0 i 0 0 i 0 0 i 0 0        
1     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
2     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0       __ 90  (28->300)
3     i 0 0 i 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
4     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
5     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
6     i 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
7     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
8     0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
9     i 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
10    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
11    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
12    i 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
13    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
14    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0




#1 problem dialog wylaczal sie po uruchomieni wlasciwej gry
    powód - trywialny - dzialajaca pêtla. Nie rozwi¹¿ê go z powodu nirwiedzy na temat 
    alternatywnych metod zczytywania zachowañ myszy w allegro







*/
int main_mech() {        
    for(int i=0; i<30; i++) {
        for(int j=0; j<60; j++) {
            if(array[j][i] == -1)
                array[j][i]=1;
        }
    }
        typedef struct sth {    
                            int x;
                            int y;
                            struct sth *next;
                       }kolejka;         
        int pocz=1;
        int path=1; 
        struct sth *p; 
        struct sth *k; 
        struct sth *l;  
            
              
       // for(int i=0; i<32; i++){       
//            for(int j=0; j<62; j++) {
//                lb[j][i]=0;
//            }
//        }
//        for(int i=0; i<30; i++){      
//            for(int j=0; j<60; j++) {
//                if(array[j][i]==1)
//                    lb[j+1][i+1]=1;
//            }
//        }        
         /*       
        kolejka *base;
        base=(kolejka*)malloc(sizeof(kolejka));
        if(base!=NULL){
            base->x=1;
            base->y=13;
            p=base;
            k=base;
            l=p;
            k->next=base;                                       
        }
        
        if(array[0][13]!=1) {
            pocz=0;
        }
        else {  
            array[0][13]=-1;
            array[1][13]=-1; 
            while(pocz&&path&&p!=NULL) {             
                if(array[(p->x)+1][p->y] == 1) {                      /*na prawo patrz*/
                    array[(p->x)+1][p->y] = -1;
                    kolejka *base;
                    base = (kolejka*)malloc(sizeof(kolejka));
                    if(base!=NULL){
                        base->x=(p->x+1);
                        base->y=(p->y);
                        k->next=base;
                        k=base;
                        k->next=NULL;
                    }
                    if((p->x+1)==(59)&&(p->y)==(13)){                 /*Ostatni krok bedzie w prawo*/
                        path=0;     
                    }                                  
                }
                if(array[(p->x)][(p->y)+1]==1){                      /*do gory patrz*/
                    array[(p->x)][(p->y)+1]=-1;
                    kolejka *base;
                    base=(kolejka*)malloc(sizeof(kolejka));
                    if(base!=NULL){
                        base->x=(p->x);
                        base->y=(p->y+1);
                        k->next=base;
                        k=base;      
                        k->next=NULL;                                 
                    }
                }
                if(array[(p->x)-1][(p->y)]==1){                      /*na lewo patrz*/
                    array[(p->x)-1][(p->y)]=-1;
                    kolejka *base;
                    base=(kolejka*)malloc(sizeof(kolejka));
                    if(base!=NULL){
                        base->x=(p->x-1);
                        base->y=(p->y);
                        k->next=base;
                        k=base;      
                        k->next=NULL;                                 
                    }
                }
                if(array[(p->x)][(p->y)-1]==1){                       /*w dol patrz*/
                    array[(p->x)][(p->y)-1]=-1;
                    kolejka *base;
                    base=(kolejka*)malloc(sizeof(kolejka));
                    if(base!=NULL){
                        base->x=(p->x);
                        base->y=(p->y-1);
                        k->next=base;
                        k=base; 
                        k->next=NULL;                                      
                    }
                }
                if(p->next!=NULL) {
                    l=p;
                    p=p->next;
                    free(l);
                }
                else {
                    pocz=0;
                }                            
            }               
        }
    while(p!=NULL) {
        l=p;
        p=p->next;
        free(l);
    }     
    return path;
}*/
