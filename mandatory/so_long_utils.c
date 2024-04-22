#include"so_long.h"

t_game count_collect(char **map_arr)
{
    int i;
    int j;
    t_game g1;

    i = 0 ;
    g1.coll_0 = 0;
    g1.coll_var = 0;
    g1.exit = 0;

    while(map_arr[i]){
        j = 0;
        while (map_arr[i][j])
        {
            if(map_arr[i][j] == 'C')
                g1.coll_0++;
            j++;
        }
        i++;
    }
    return g1;
}

int get_button_exit(__unused long keycode, __unused t_data vars ){
    exit(-1);
}

t_map get_player_position(char **map){
    t_map mtrx;

    mtrx.h = 0;
    mtrx.w = 0;
    int i;
    int j;

    i = 0 ;
    while(map[i]){
        j = 0;
        while(map[i][j]){
            if(map[i][j] == 'P' || map[i][j] == 'B'){
                mtrx.h = i;
                mtrx.w = j;
                return mtrx;
            }
            j++;
        }
        i++;
    }
    return mtrx;
}


// free fucntion

// images intializer