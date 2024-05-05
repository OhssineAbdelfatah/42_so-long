#include"so_long.h"

int fire(t_data *data)
{
    static int i = 0;
        // mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.images[10]->img_ptr,10,10);
    if(i == 250){

        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[5]->img_ptr,64,64);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[10]->img_ptr,64+16,64+16);
    }
    else if(i == 500){

        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[5]->img_ptr,64,64);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[11]->img_ptr,64+16,64+16);
    }
    else if(i == 750){
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[5]->img_ptr,64,64);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[12]->img_ptr,64+16,64+16);

    }
    else if(i == 1000)
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[5]->img_ptr,64,64);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[13]->img_ptr,64+16,64+16);
    }
    else if(i == 1250)
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->images[5]->img_ptr,64,64);
        i = 0;
    }
    i++;
    return 0;
}