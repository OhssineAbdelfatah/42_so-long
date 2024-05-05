#include"so_long.h"

void free_map(char  **map_arr)
{
    int i;
    i = 0; 
    while(map_arr[i++])
                free(map_arr[i]);
    free(map_arr);
    return ;
}

int get_movs(long keycode,t_data *vars)
{
    if(keycode == 53 )
        exit(2);
    if(keycode == 124 || keycode == 2) // right
        move_right(vars);
    if(keycode == 123 || keycode == 0)
        move_left(vars); // left
    if(keycode == 126 || keycode == 13)
        move_up(vars); // up
    if(keycode == 125 || keycode == 1)
        move_down(vars); // down
    return 0;
}

t_data init_imgs(t_data data)
{
    t_img *img;
    int i ;
    i = 0 ;
    img = malloc(14*sizeof(t_img));
    img[0].path = "./texteurs/wall1.xpm";
    img[1].path = "./texteurs/player1.xpm";
    img[2].path = "./texteurs/col2.xpm";
    img[3].path = "./texteurs/close1.xpm";
    img[4].path = "./texteurs/open1.xpm";
    img[5].path = "./texteurs/floor5.xpm";
    
    img[6].path = "./texteurs/right_00.xpm";
    img[7].path = "./texteurs/left_00.xpm";
    img[8].path = "./texteurs/up_00.xpm";
    img[9].path = "./texteurs/down_01.xpm";

    img[10].path =  "./texteurs/animation/explo0.xpm";
    img[11].path =  "./texteurs/animation/explo1.xpm";
    img[12].path =  "./texteurs/animation/explo2.xpm";
    img[13].path =  "./texteurs/animation/explo3.xpm";


    while(i < 14){
        data.images[i] = &img[i];
        data.images[i]->img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, data.images[i]->path, &(data.images[i]->xw), &(data.images[i]->yh));
        i++;
    }
    data.canvas.current_img = data.images[6]->img_ptr;

    data.canvas.imgd = data.images[9]->img_ptr;
    data.canvas.imgl = data.images[7]->img_ptr;
    data.canvas.imgu = data.images[8]->img_ptr;
    data.canvas.imgr = data.images[6]->img_ptr;

    return data;
}

int start_game(char *name)
{
    t_data data;
    t_game game;
    t_map mtrx;

    check_valid_path(name);
    data.mlx_ptr = mlx_init();
    data = init_imgs(data);
    mtrx = count_hw(name); 
    data.map = &mtrx; 
    data.map_arr = fill_map(mtrx.h,name);

    // if( data.map_arr[0] != NULL ){
    //     if(check_lines(data) == -1 ||  check_boundry(data) == -1   || check_object(data) == -1){
    //         free_map(data.map_arr);
    //         return -1;
    //     }
    // }else
    //     return -1;

    (data).win_ptr = mlx_new_window((data).mlx_ptr,(data).map->w * data.images[0]->xw ,(data).map->h* data.images[0]->yh,"So Long @_@");
    game = count_collect(data.map_arr);
    data.game = &game;
    data.movs = 0 ;
    render_map(&data); // check error
    mlx_hook(data.win_ptr, 2,0,get_movs,&data);
    mlx_hook(data.win_ptr, 17,0,get_button_exit,&data);
    mlx_loop_hook(data.mlx_ptr ,fire ,&data);
    mlx_loop(data.mlx_ptr);
    return 0;

}

int main(int argc ,char **argv)
{
    int err;    
    
    if(argc == 2 ){
        if(check_map_name(argv[1]))
            return 0;
        err = start_game(argv[1]);
        if(err != 0)
            return -1;
    }else{
        ft_printf("error\n");
    }
    return 0;
}
