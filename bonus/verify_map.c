#include"so_long.h"

int check_map_name(char *name)
{
    int i;
    int j;
    int k;
    char *ext;

    ext = ".ber";
    i = 0;
    k = 3;
    while(name[i++]);    
    j = i;
    i--;
    while(i-- > j-4){
        if(name[i] != ext[k]){
            return -1;
        }
        k--;
    }
    return 0;
}

int check_lines(t_data data)
{
    int i;

    i = 0;
    while(data.map_arr && i+1 < (data.map->h) ){
        if(ft_strlen(data.map_arr[i]) != ft_strlen(data.map_arr[i+1])){
            ft_printf("lines error\n");
            return -1;
        }
        i++;
    }
    return 0;
}

int check_boundry(t_data data)
{
    int i;
    i = 0;

    while(data.map_arr[0][i] != '\0' && data.map_arr[data.map->h-1][i] != '\0'){
        if(data.map_arr[0][i] != '1' || data.map_arr[data.map->h-1][i] != '1'){
            ft_printf("walls error\n");
            return -1;
        }
        i++;
    }
    i=0;
    while(data.map_arr && data.map_arr[i] != NULL){
        if(data.map_arr[i][0] != '1' || data.map_arr[i][data.map->w-1] != '1'){
            ft_printf("walls error\n");
            return -1;
        }
        i++;
    }
   
    return 0;
}

int check_object(t_data data)
{
    int exit;
    int player;
    int coll;
    t_map mtrx;

    mtrx.h = 0;
    exit = 0;
    player = 0;
    coll = 0;

    while(data.map_arr &&  data.map_arr[mtrx.h]){
        mtrx.w = 0;
        while(data.map_arr[mtrx.h][mtrx.w]){
            if(data.map_arr[mtrx.h][mtrx.w] == 'P')
                player++;
            else if(data.map_arr[mtrx.h][mtrx.w] == 'E')
                exit++;
            else if(data.map_arr[mtrx.h][mtrx.w] == 'C')
                coll++;
            mtrx.w++;
        }
        mtrx.h++;
    }
    if(player != 1 || exit != 1 || coll < 1){
        ft_printf("objects error\n");
        return -1;
    }
    return 0;  
}

int valid_path(int x,int y,int *col,int *exit,char **map_arr){
    if(map_arr[x][y] == '1' || map_arr[x][y] == '\0' || map_arr[x] == NULL || map_arr[x][y] == 'V')
        return 0;
    if(map_arr[x][y] == 'C')
            *col +=1;
    if(map_arr[x][y] != 'E')
            *exit = 1;
    map_arr[x][y] = 'V';
    valid_path(x +1, y ,col ,exit,map_arr);
    valid_path(x -1, y ,col ,exit,map_arr);
    valid_path(x , y +1,col ,exit,map_arr);
    valid_path(x , y -1,col ,exit,map_arr);
    return 0;
}

int check_valid_path(char *name){
    char **map_arr;
    t_map mtrx;
    t_map p_pos;
    int col;
    int exit;

    col = 0;
    exit = 0;
    mtrx = count_hw(name);
    map_arr = (char **)malloc(((mtrx.h)+1)*sizeof(char *));
    map_arr = fill_map(mtrx.h , name); 
    p_pos = get_player_position(map_arr);
    valid_path(p_pos.h ,p_pos.w , &col ,&exit ,map_arr);
    ft_printf("col %d exit %d\n",col,exit);

    return 0;
}
// col lines