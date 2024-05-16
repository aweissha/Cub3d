/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:07:59 by aweissha          #+#    #+#             */
/*   Updated: 2024/05/16 20:41:16 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[mapHeight][mapWidth]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// for testing, parse_map() just defines data->map as worldMap
void	parse_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
    for (int i = 0; i < mapWidth; i++) 
	{
        for (int j = 0; j < mapHeight; j++) 
		{
            data->map[i][j] = worldMap[i][j];
			printf("%d,", data->map[i][j]);
        }
		printf("\n");
    }
}

// void	print_map(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
//     for (int y = 0; y < mapHeight; y++) 
// 	{
//         for (int x = 0; x < mapWidth; x++) 
// 		{
// 			printf("%d,", data->map[x][y]);
//         }
// 		printf("\n");
//     }
// }

void    black_window(t_data *data)
{
    int x;
    int y;
    y = -1;
    while (++y != 480)
    {
        x = 0;
        while (x != 640)
            mlx_put_pixel(data->img, x++, y, 0x00000011);
    }
}

void	ft_hook(void *param)
{
	t_data *data = param;
	float	temp_y;
	float	temp_x;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		temp_x = data->player->direction.x;
		temp_y = data->player->direction.y;
		data->player->direction.x = temp_x * cos(1 * (PI / 180)) - temp_y * sin(1 * (PI / 180));
		data->player->direction.y = temp_x * sin(1 * (PI / 180)) + temp_y * cos(1 * (PI / 180));
		temp_x = data->player->screen.x;
		temp_y = data->player->screen.y;
		data->player->screen.x = temp_x * cos(1 * (PI / 180)) - temp_y * sin(1 * (PI / 180));
		data->player->screen.y = temp_x * sin(1 * (PI / 180)) + temp_y * cos(1 * (PI / 180));
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		temp_x = data->player->direction.x;
		temp_y = data->player->direction.y;
		data->player->direction.x = temp_x * cos(-1 * (PI / 180)) - temp_y * sin(-1 * (PI / 180));
		data->player->direction.y = temp_x * sin(-1 * (PI / 180)) + temp_y * cos(-1 * (PI / 180));
		temp_x = data->player->screen.x;
		temp_y = data->player->screen.y;
		data->player->screen.x = temp_x * cos(-1 * (PI / 180)) - temp_y * sin(-1 * (PI / 180));
		data->player->screen.y = temp_x * sin(-1 * (PI / 180)) + temp_y * cos(-1 * (PI / 180));
	}
	printf("x: %f\n", data->player->direction.x);
	printf("y: %f\n", data->player->direction.y);
	black_window(data);
	raycaster(data);
	
}

int	main(int argc, char **argv)
{
	t_data	*data;

	// printf("hello\n");
	data = init_data(argc, argv);
	parse_map(data);
	// print_map(data);
	raycaster(data);

	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	free_everything(data);
}
//  to do:
// reset image before raycasting whenever a movement is made