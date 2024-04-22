#include"so_long.h"

int main(){
    char *path = "./texteurs/wall4.xpm";
    void *mlx_ptr = NULL;
    int x = 0;
    int y = 0;
    int i =0;
    mlx_ptr = mlx_init();
    mlx_xpm_file_to_image(mlx_ptr, path, &x, &y);
    ft_printf("x = %d ,y = %d\n",x,y);
    while(i <= 14)
        ft_printf("wall%d\n",i++);
}