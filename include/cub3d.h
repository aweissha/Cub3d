/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:02:00 by aweissha          #+#    #+#             */
/*   Updated: 2024/05/15 13:15:34 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define mapWidth 24
# define mapHeight 24

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
	int			map[mapWidth][mapHeight];
	mlx_t 	 	*mlx;
	mlx_image_t	*img;
	t_player	*player;
	t_ray		*ray;
	double		time;
	double		prev_time;	
}	t_data;

// init.c
void	init_ray(int ray_index, t_data *data);
void	ft_init_mlx(t_data *data);
void	init_player(t_data *data);
t_data	*init_data(int argc, char **argv);

// error.c
void	free_everything(t_data *data);
void	ft_error(char *message, int code);
void	ft_mlx_error(const char *message, int code);
void	ft_mlx_error_and_free(const char *message, int code, t_data *data);
void	ft_error_and_free(char *message, int code, t_data *data);

// raycasting.c
double	get_lower(double a, double b);
double	find_factor(t_ray *ray);
void	elongate_ray(t_ray *ray);
int 	is_integer(double x);
void	check_side(t_data *data);
void	check_for_wall(t_data *data);
double	vector_len(t_vector vector);
void	calc_perp_length(t_data *data);
void	ray_algorithm(t_data *data);
void	line_to_image(t_data *data);
void	render_image(t_data *data);
void	raycaster(t_data *data);

#endif