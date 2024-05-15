/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:07:03 by aweissha          #+#    #+#             */
/*   Updated: 2024/05/15 18:03:19 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_ray(int ray_index, t_data *data)
{
	t_player	*player;
	t_ray		*ray;

	if (data->ray == NULL)
		data->ray = malloc(sizeof(t_ray));
	if (data->ray == NULL)
		ft_error_and_free("Memory allocation of ray failed\n", errno, data);	
	player = data->player;
	ray = data->ray;
	ray->index = ray_index;
	ray->start_pos.x = player->position.x;
	ray->start_pos.y = player->position.y;
	ray->pos.x = player->position.x;
	ray->pos.y = player->position.y;
	ray->screen_x = ((2 * ray_index) / data->screen_width) - 1;
	ray->dir.x = player->direction.x + player->screen.x * ray->screen_x;
	ray->dir.y = player->direction.y + player->screen.y * ray->screen_x;
	ray->map_x = (int)player->position.x;
	ray->map_y = (int)player->position.y;
	ray->wall = 0;
	ray->side = 0;
	ray->perp_length = 0;
	ray->line_height = 0;
	ray->line_bottom = 0;
	ray->line_top = 0;
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init(data->screen_width, data->screen_height, "Cub3d", false);
	if (data->mlx == NULL)
		ft_mlx_error_and_free(mlx_strerror(mlx_errno), mlx_errno, data);
	data->img = mlx_new_image(data->mlx, data->screen_width, data->screen_height);
	if (data->img == NULL)
		ft_mlx_error_and_free(mlx_strerror(mlx_errno), mlx_errno, data);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		ft_mlx_error_and_free(mlx_strerror(mlx_errno), mlx_errno, data);
	
}

void	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (data->player == NULL)
		ft_error("Memory allocation of player struct failed\n", errno);
	// set default values for plazer location and view angle
	data->player->position.x = 22;
	data->player->position.y = 4;
	data->player->direction.x = 0.1;
	data->player->direction.y = -0.5;
	data->player->screen.x = 0.5;
	data->player->screen.y = 0.1;
}

t_data	*init_data(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		ft_error("Memory allocation of data struct failed\n", errno);
	data->argc = argc;
	data->argv = argv;
	data->screen_width = 640;
	data->screen_height = 480;
	data->mlx = NULL;
	data->img = NULL;
	data->player = NULL;
	data->ray = NULL;
	data->time = 0;
	data->prev_time = 0;
	init_player(data);
	ft_init_mlx(data);
	return (data);
}
