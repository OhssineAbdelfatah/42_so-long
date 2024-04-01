#include"so_long.h"

#include<stdio.h>


int get_button_exit(__unused long keycode, __unused t_data vars ){
    exit(-1);
}


t_game count_collect(t_data *data){
    int i;
    int j;
    t_game g1;

    i = 0 ;
    g1.coll_0 = 0;
    g1.coll_var = 0;
    g1.exit = 0;

 
    while((*data).map_arr[i]){
        j = 0;
        while ((*data).map_arr[i][j])
        {
            if((*data).map_arr[i][j] == 'C')
                g1.coll_0++;
            j++;
        }
        i++;
    }
    return g1;
}

int get_movs(long keycode,t_data *vars){
    if(keycode == 53)
        exit(2);
    if(keycode == 124) // right
        move_right(vars);
    if(keycode == 123)
        move_left(vars); // left
    if(keycode == 126)
        move_up(vars); // up
    if(keycode == 125)
        move_down(vars); // down
    return 0;
}

int start_game()
{
    t_data data;
    t_game game;
    t_img img[4];

    t_map mtrx;
    


    img[0].path = "./texteurs/wall.xpm";
    img[1].path = "./texteurs/player.xpm";
    img[2].path = "./texteurs/col.xpm";
    img[3].path = "./texteurs/home.xpm";
    
    data.images[0] = &img[0]; 
    data.images[1] = &img[1]; 
    data.images[2] = &img[2]; 
    data.images[3] = &img[3]; 
    // map check first
    
    mtrx = count_hw();
    data.map = &mtrx; 

    data.map_arr = fill_map(mtrx.h);
    // check return
    data.mlx_ptr = mlx_init();

    data.images[0]->img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, data.images[0]->path, &(data.images[0]->xw), &(data.images[0]->yh));
    data.images[1]->img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, data.images[1]->path, &(data.images[1]->xw), &(data.images[1]->yh));
    data.images[2]->img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, data.images[2]->path, &(data.images[2]->xw), &(data.images[2]->yh));
    data.images[3]->img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, data.images[3]->path, &(data.images[3]->xw), &(data.images[3]->yh));
    
    (data).win_ptr = mlx_new_window((data).mlx_ptr,(data).map->w * img[0].xw,(data).map->h*img[0].yh,"So Long @_@");

    game = count_collect(&data);
    data.game = &game;
    data.movs = 0 ;
    render_map(&data); // check error

    mlx_hook(data.win_ptr,2,0,get_movs,&data);
    mlx_hook(data.win_ptr,17,0,get_button_exit,&data);
    mlx_loop(data.mlx_ptr);
    return 0;
}

int main(){
   int err;
    err = start_game();
    if(err != 0)
        return -1;
    return 0;

}