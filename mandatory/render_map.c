#include"so_long.h"


t_map count_hw(char *name){
    int fd_map ;
    t_map mtrx;
    char *line;
    mtrx.w = 0;
    mtrx.h = 0;
    fd_map = open(name,O_RDONLY);
    // handle error
    while( (line = get_next_line(fd_map)) ){
        while(line[mtrx.w])
            mtrx.w++;
        mtrx.h++;
        free(line);
    }
    free(line);
    close(fd_map);
    return mtrx;
}

char **fill_map(int h, char *name)
{
    char **map;
    int i;
    int fd_map;

    fd_map = open(name,O_RDONLY);
    // handel error
    i = 0 ;
    map = (char **)malloc((h+1)*sizeof(char *));
    if(!map)
        return NULL;
    //handle error
    while(i< h ){
        map[i] = get_next_line(fd_map);
        i++;
    }
    map[i]= NULL;
    return map;
}

int render_map(t_data *data)
{
    int i;
    int j;
    int x;
    int y;
    // char *movs;
    y = 0;
    i = 0 ;
    while((*data).map_arr[i] ){
        x = 0;
        j = 0 ;
        while( (*data).map_arr[i][j] ){
            if((*data).map_arr[i][j] == '1' )
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[0]->img_ptr ,x,y);
            else if((*data).map_arr[i][j] == '0')
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[5]->img_ptr,x,y);
            else if((*data).map_arr[i][j] == 'P'){
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[5]->img_ptr,x,y);
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).canvas.current_img,x,y);
            }
            else if((*data).map_arr[i][j] == 'C'){
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[5]->img_ptr,x,y);
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[2]->img_ptr,x+8,y+8);
            }
            else if((*data).map_arr[i][j] == 'E'  && (*data).game->coll_var != (*data).game->coll_0){
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[5]->img_ptr,x,y);
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[3]->img_ptr,x,y);
            }
            else if((*data).map_arr[i][j] == 'E'  && (*data).game->coll_var == (*data).game->coll_0){
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[5]->img_ptr,x,y);
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[4]->img_ptr,x,y);
            }
            else if((*data).map_arr[i][j] == 'B'){
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[5]->img_ptr,x,y);
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).images[3]->img_ptr,x,y);
                mlx_put_image_to_window((*data).mlx_ptr,(*data).win_ptr,(*data).canvas.current_img,x,y);
            }
            j++;
            x+=(*data).images[0]->xw;
        }
        y+=(*data).images[0]->yh;
        i++;
    }
    // movs = int_to_str((*data).movs);
    if((*data).movs != 0)
        ft_printf("mov number : %d \n",(*data).movs);
    // mlx_string_put((*data).mlx_ptr, (*data).win_ptr, 20, 2, -1,"movs : ");
    // mlx_string_put((*data).mlx_ptr, (*data).win_ptr, 92, 2, -1 ,movs);
    // free(movs);
    return 0;
}

char *int_to_str(int nbr)
{
    int num;
    int len;
    int i;
    char * str;

    num = nbr;
    len = 0;
    i = 0;
    if(nbr == 0)
        len = 1;
    else{
        while(num){
            num=num/10;
            len++;
        }
    }
    str = malloc(len+1);
    while(i< len){
        str[len-1-i] = nbr%10 +48;
        nbr/=10;
        i++; 
    }
    str[len]=0;
    return str;
}