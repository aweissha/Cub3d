/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:07:03 by aweissha          #+#    #+#             */
/*   Updated: 2024/04/30 15:21:36 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	data->player->position.y = 12;
	data->player->direction.x = -1;
	data->player->direction.y = 0;
	data->player->screen.x = 0;
	data->player->screen.y = 0.66;
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
