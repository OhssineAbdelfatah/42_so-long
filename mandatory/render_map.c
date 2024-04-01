#include"so_long.h"


t_map count_hw(){
    int fd_map ;
    t_map mtrx;
    char *line;
    mtrx.w = 0;
    mtrx.h = 0;
    fd_map = open("map.ber",O_RDONLY);
    // handle error
    while( (line = get_next_line(fd_map)) ){
        while(line[mtrx.w])
            mtrx.w++;
        mtrx.h++;
    }
    free(line);
    close(fd_map);
    return mtrx;
}



char **fill_map(int h){
    char **map;
    int i;
    int fd_map;

    fd_map = open("map.ber",O_RDONLY);
    // handel error
    i = 0 ;
    map = (char **)malloc((h+1)*sizeof(char *));
    //handle error
    while(i< h){
        map[i] = get_next_line(fd_map);
        i++;
    }
    map[i]= NULL;
    return map;
}

int render_map(t_data *data){
    int i;
    int j;
    int x;
    int y;

    y = 0;
    i = 0 ;
    while((*data).map_arr[i] ){
        x = 0;
        j = 0 ;
        while( (*data).map_arr[i][j] ){
            if((*data).map_arr[i][j] == '1')
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[0]->img_ptr ,x,y);
            else if((*data).map_arr[i][j] == 'P')
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[1]->img_ptr,x+8,y);
            else if((*data).map_arr[i][j] == 'C')
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[2]->img_ptr,x,y);
            else if((*data).map_arr[i][j]   )
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[3]->img_ptr,x+6,y);
            j++;
            x+=(*data).images[0]->xw;
        }
        y+=(*data).images[0]->yh;
        i++;
    }
    return 0;
}