/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:21:16 by aharder           #+#    #+#             */
/*   Updated: 2025/01/30 16:14:21 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfheader.h"

void	free_and_exit(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars->map);
	exit(0);
}

void	zoom(t_vars *vars, int x)
{
	vars->size += x;
	ft_bzero(vars->addr, 1920 * 1080 *(vars->bpp / 8));
	generategrid(vars, vars->map, vars->size);
}

void	horizontal_move(t_vars *vars, int x)
{
	vars->defaulty += x;
	ft_bzero(vars->addr, 1920 * 1080 *(vars->bpp / 8));
	generategrid(vars, vars->map, vars->size);
}

void	vertical_move(t_vars *vars, int x)
{
	vars->defaultx + x;
	ft_bzero(vars->addr, 1920 * 1080 *(vars->bpp / 8));
	generategrid(vars, vars->map, vars->size);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		free_and_exit(vars);
	if (keycode == 65362)
		zoom(vars, 1);
	if (keycode == 65364)
		zoom(vars, -1);
	if (keycode == 113)
		vertical_move(vars, 5);
	if (keycode == 100)
		vertical_move(vars, -5);
	if (keycode == 122)
		horizontal_move(vars, 5);
	if (keycode == 115)
		horizontal_move(vars, -5);
	return (0);
}
