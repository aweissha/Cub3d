/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sparth <sparth@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:07:03 by aweissha          #+#    #+#             */
/*   Updated: 2024/06/11 18:28:00 by sparth           ###   ########.fr       */
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
	ray->factor = ((2 * ray_index) / (float)data->screen_width) - 1;
	ray->dir.x = player->direction.x + player->screen.x * ray->factor;
	ray->dir.y = player->direction.y + player->screen.y * ray->factor;
	ray->map_x = (int)player->position.x;
	ray->map_y = (int)player->position.y;
	init_ray_2(data);
}

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init(data->screen_width,
			data->screen_height, "Cub3D", false);
	if (data->mlx == NULL)
		ft_error_and_free("mlx_init failed\n", mlx_errno, data);
	data->img = mlx_new_image(data->mlx, data->screen_width,
			data->screen_height);
	if (data->img == NULL)
		ft_error_and_free("mlx_new_image failed\n", mlx_errno, data);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		ft_error_and_free("mlx_image_to_window failed\n", mlx_errno, data);
}

void	init_player(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	if (data->player == NULL)
		ft_error_and_free("Memory allocation of player struct failed", 1, data);
	find_player(data);
	if (data->init_player_dir == 'N')
		player_dir_init(data, 0, -0.5, 'N');
	else if (data->init_player_dir == 'S')
		player_dir_init(data, 0, 0.5, 'S');
	else if (data->init_player_dir == 'W')
		player_dir_init(data, -0.5, 0, 'W');
	else if (data->init_player_dir == 'E')
		player_dir_init(data, 0.5, 0, 'E');
}

void	init_textures(t_data *data)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png(data->no_texture);
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->textures[0] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->textures[0])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(data->ea_texture);
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->textures[1] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->textures[1])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png(data->so_texture);
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->textures[2] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->textures[2])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
	init_textures_2(data);
	init_textures_3(data);
}

t_data	*init_data(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
	{
		printf("input: './cub3D' 'name_of_map'");
		exit (1);
	}
	data = malloc(sizeof(t_data));
	if (data == NULL)
		ft_error("Memory allocation of data struct failed\n", errno);
	init_data_params(data);
	data->mlx = NULL;
	data->img = NULL;
	data->player = NULL;
	data->ray = NULL;
	data->map = NULL;
	init_data_textures(data);
	parse_map(data, argv);
	init_player(data);
	map_validation(data);
	ft_init_mlx(data);
	init_textures(data);
	return (data);
}
