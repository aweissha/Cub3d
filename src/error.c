/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sparth <sparth@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:11:02 by aweissha          #+#    #+#             */
/*   Updated: 2024/06/11 18:20:56 by sparth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
			free(data->map[i++]);
		free (data->map);
	}
}

void	free_everything(t_data *data)
{
	if (data->mlx)
		mlx_terminate(data->mlx);
	if (data->player)
		free(data->player);
	if (data->ray)
		free(data->ray);
	if (data->ea_texture)
		free(data->ea_texture);
	if (data->no_texture)
		free(data->no_texture);
	if (data->so_texture)
		free(data->so_texture);
	if (data->we_texture)
		free(data->we_texture);
	free_map(data);
	if (data)
		free(data);
}

void	ft_error(const char *message, int code)
{
	write(2, message, ft_strlen(message));
	exit(code);
}

void	ft_error_and_free(const char *message, int code, t_data *data)
{
	free_everything(data);
	ft_error(message, code);
}
