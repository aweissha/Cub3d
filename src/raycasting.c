/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:53:58 by aweissha          #+#    #+#             */
/*   Updated: 2024/04/30 17:30:18 by aweissha         ###   ########.fr       */
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
	ray->screen_x = ((2 * ray_index) / data->screen_width) - 1;
	ray->dir.x = player->direction.x + player->screen.x * ray->screen_x;
	ray->dir.y = player->direction.y + player->screen.y * ray->screen_x;
	ray->start_pos.x = player->position.x;
	ray->start_pos.y = player->position.y;
	ray->pos.x = player->position.x;
	ray->pos.y = player->position.y;
	ray->map_x = (int)player->position.x;
	ray->map_y = (int)player->position.y;
	ray->wall = 0;
	ray->perp_length = 0;
}

double	get_lower(double a, double b)
{
	if (a < b)
		return (a);
	else if (b <= a)
		return (b);
}

double	find_factor(t_ray *ray)
{
	double	a_x;
	double	a_y;
	double	a;

	a_x = DBL_MAX;
	a_y = DBL_MAX;
	if (ray->dir.x > 0)
		a_x = (1 - ray->pos.x + ray->map_x) / ray->dir.x;
	else if (ray->dir.x < 0)
		a_x = (-ray->pos.x + ray->map_x) / ray->dir.x;
	if (ray->dir.y > 0)
		a_y = (1 - ray->pos.y + ray->map_y) / ray->dir.y;
	else if (ray->dir.y < 0)
		a_y = (-ray->pos.y + ray->map_y) / ray->dir.y;
	if (a_x == 0)
		a_x = -1 / ray->dir.x;
	if (a_y == 0)
		a_y = -1 / ray->dir.y;		
	a = get_lower(a_x, a_y);
	return (a);
}

void	elongate_ray(t_ray *ray)
{
	double	a;

	a = find_factor(ray);
	ray->pos.x = ray->pos.x + ray->dir.x * a;
	ray->pos.y = ray->pos.y + ray->dir.y * a;
	ray->map_x = (int)ray->pos.x;
	ray->map_y = (int)ray->pos.y;
}

int is_integer(double x)
{
    return (fabs(x - round(x)) < 1e-9);
}

void	check_side(t_data *data)
{
	t_ray	*ray;
	
	ray=data->ray;
	if (is_integer(ray->pos.x == 1)
		&& is_integer(ray->pos.y == 1))
			ray->side = 0;
	else if (is_integer(ray->pos.x == 1))
		ray->side = 1;
	else if (is_integer(ray->pos.y == 1))
		ray->side = 2;
}

/*
This function checks, if the ray is in a wall. 
The ray is also consideres as in a wall,
when its for example at position (2.0/1.5) and square (1/1) is a wall, 
when the ray is facing to negative x. 
When there is a negative dir in the ray,
the previous square has to be checked.
*/
void	check_for_wall(t_data *data)
{
	t_ray	*ray;
	int		**map;

	ray = data->ray;
	map = data->map;
	if (map[ray->map_x][ray->map_y] != 0)
		ray->wall = map[ray->map_x][ray->map_y];
	else if (ray->dir.x < 0 && is_integer(ray->pos.x) == 1
		&& ray->dir.y < 0 && is_integer(ray->pos.y) == 1
		&& map[ray->map_x - 1][ray->map_y - 1] != 0)
		ray->wall = map[ray->map_x - 1][ray->map_y - 1];
	else if (ray->dir.x < 0 && is_integer(ray->pos.x) == 1
		&& map[ray->map_x - 1][ray->map_y] != 0)
		ray->wall = map[ray->map_x - 1][ray->map_y];
	else if (ray->dir.y < 0 && is_integer(ray->pos.y) == 1
		&& map[ray->map_x][ray->map_y - 1] != 0)
		ray->wall = map[ray->map_x][ray->map_y - 1];
	if (ray->wall != 0)
		check_side(data);
}

double	vector_len(t_vector vector)
{
	return (sqrt(pow(vector.x, 2) + pow(vector.y, 2)));
}

void	calc_perp_length(t_data *data)
{
	t_ray		*ray;
	t_player	*player;

	ray = data->ray;
	player = data->player;
	ray->perp_length =
		(sqrt(pow(ray->pos.x - ray->start_pos.x, 2)
		+ pow(ray->pos.y - ray->start_pos.y, 2))
		- sqrt(pow(vector_len(player->direction), 2)
		+ pow((vector_len(player->screen) * ray->screen_x), 2)))
		/ (sqrt(pow(vector_len(player->direction), 2)
		+ pow((vector_len(player->screen) * ray->screen_x), 2)))
		* vector_len(player->direction);
}

double	ray_algorithm(t_data *data)
{
	t_ray	*ray;

	ray = data->ray;
	check_for_wall(data);
	while (!(ray->wall))
	{
		elongate_ray(ray);
		check_for_wall(data);
	}
	calc_ray_length(ray);
}

void	line_to_image(t_data *data)
{
	t_ray	*ray;
	int		counter;

	ray = data->ray;
	counter = ray->line_top;
	while (counter <= ray->line_bottom)
	{
		mlx_put_pixel(data->img, ray->index, counter, 0xFF0000FF);
		counter++;
	}
}

/*
This functions looks at the length of the last ray
and converts the information into the image by filling
each pixel-column of the image correctly.
*/
void	render_image(t_data *data)
{
	t_ray	*ray;

	ray = data->ray;
	ray->line_height = (int)data->screen_height / ray->perp_length;
	ray->line_bottom = data->screen_height / 2 - ray->line_height / 2;
	ray->line_top = data->screen_height / 2 + ray->line_height / 2;
	line_to_image(data);
}

void	raycaster(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->screen_width)
	{
		init_ray(i, data);
		ray_algorithm(data);
		render_image(data);
		i++;
	}
}
