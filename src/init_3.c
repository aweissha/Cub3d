/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sparth <sparth@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:24:43 by sparth            #+#    #+#             */
/*   Updated: 2024/06/11 18:28:15 by sparth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_textures_4(t_data *data)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("./textures/knive_stab.png");
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->weapon_shot_textures[2] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->weapon_shot_textures[2])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("./textures/door.png");
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->door_texture[0] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->door_texture[0])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
}

void	init_textures_3(t_data *data)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png("./textures/knive.png");
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->weapon_textures[2] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->weapon_textures[2])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("./textures/gun_shot.png");
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->weapon_shot_textures[0] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->weapon_shot_textures[0])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("./textures/gun_2_shot.png");
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->weapon_shot_textures[1] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->weapon_shot_textures[1])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
	init_textures_4(data);
}

void	init_textures_2(t_data *data)
{
	mlx_texture_t	*tmp;

	tmp = mlx_load_png(data->we_texture);
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->textures[3] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->textures[3])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("./textures/gun.png");
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->weapon_textures[0] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->weapon_textures[0])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
	tmp = mlx_load_png("./textures/gun_2.png");
	if (!tmp)
		ft_error_and_free("mlx_load_png failed\n", mlx_errno, data);
	data->weapon_textures[1] = mlx_texture_to_image(data->mlx, tmp);
	if (!data->weapon_textures[1])
		ft_error_and_free("mlx_texture_to_image failed\n", mlx_errno, data);
	mlx_delete_texture(tmp);
}
