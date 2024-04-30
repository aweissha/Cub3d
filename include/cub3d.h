/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:02:00 by aweissha          #+#    #+#             */
/*   Updated: 2024/04/30 17:12:04 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	t_vector	screen;
}	t_player;

typedef struct s_ray
{
	int			index;
	t_vector	start_pos;
	t_vector	pos;
	t_vector	dir;
	int			screen_x;
	int			map_x;
	int			map_y;
	int			wall;
	int			side;
	double		perp_length;
	int			line_height;
	int			line_bottom;
	int			line_top;
}	t_ray;

typedef struct s_data
{
	int			argc;
	char		**argv;
	int			screen_width;
	int			screen_height;
	int			**map;
	mlx_t 	 	*mlx;
	mlx_image_t	*img;
	t_player	*player;
	t_ray		*ray;
	double		time;
	double		prev_time;	
}	t_data;

// init.c
void	ft_init_mlx(t_data *data);
t_data	*init_data(int argc, char **argv);

// error.c
void	free_everything(t_data *data);
void	ft_error(char *message, int code);
void	ft_mlx_error(const char *message, int code);
void	ft_mlx_error_and_free(const char *message, int code, t_data *data);
void	ft_error_and_free(char *message, int code, t_data *data);
