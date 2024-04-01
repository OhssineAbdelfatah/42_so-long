#include"so_long.h"

t_map get_player_position(t_data data){
    char **map = data.map_arr;
    t_map mtrx;

    mtrx.h = 0;
    mtrx.w = 0;
    int i;
    int j;

    i = 0 ;
    while(map[i]){
        j = 0;
        while(map[i][j]){
            if(map[i][j] == 'P'){
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

void move_left(t_data *data){
    t_map location;
    location = get_player_position(*data);
    printf("i %d,j %d\n",location.w,location.h);
    if(location.w - 1 > 0 && location.w - 1 < (*data).map->w && (*data).map_arr[location.h][location.w - 1] != '1'){
        (*data).map_arr[location.h][location.w - 1] = 'P';
        (*data).map_arr[location.h][location.w ] = '0';
        mlx_clear_window((*data).mlx_ptr,(*data).win_ptr);
        render_map(data);

    }
    return ;
}

void move_right(t_data *data){
    t_map location;
    
    location = get_player_position(*data);
    if(location.w + 1 > 0 && location.w + 1 < (*data).map->w  && (*data).map_arr[location.h][location.w + 1] != '1'){
        (*data).map_arr[location.h][location.w + 1] = 'P';
        (*data).map_arr[location.h][location.w ] = '0';
        mlx_clear_window((*data).mlx_ptr,(*data).win_ptr);
        render_map(data);
    }
    return ;
}

void move_down(t_data *data){
    t_map location;
    
    location = get_player_position(*data);
    if(location.h + 1 > 0  && (*data).map_arr[location.h+1][location.w] != '1'){
        (*data).map_arr[location.h+1][location.w] = 'P';
        (*data).map_arr[location.h][location.w ] = '0';
        mlx_clear_window((*data).mlx_ptr,(*data).win_ptr);
        render_map(data);
    }

    return ;
}

void move_up(t_data *data){
    t_map location;
    location = get_player_position(*data);
    if(location.h - 1 > 0 && (*data).map_arr[location.h-1][location.w] != '1'){
        (*data).map_arr[location.h-1][location.w] = 'P';
        (*data).map_arr[location.h][location.w] = '0';
        mlx_clear_window((*data).mlx_ptr,(*data).win_ptr);
        render_map(data);
    }
  
    return ;
}