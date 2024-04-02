#include"so_long.h"

int check_boundry(t_data data)
{
    t_map mtrx;

    mtrx.h = 0;
    // check h0 w:var hlast w:var 
    // check h:var w0 h:war w:last 
    while(data.map_arr[0][mtrx.w]){
        if(data.map_arr[0][mtrx.w] != '1')
            return -1;
        mtrx.w;
    }
    while(data.map_arr[data.map->h][mtrx.w]){

    }

}

// hceck lines