/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:21:16 by aharder           #+#    #+#             */
/*   Updated: 2024/12/20 16:44:11 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdfheader.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("Keycode : %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->img);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		free_map(vars->map);
		exit(0);
	}
	if (keycode == 65362)
	{
		vars->size += 1;
		ft_bzero(vars->addr, 1920 * 1080 *(vars->bpp / 8));
		generategrid(vars, vars->map, vars->size);
	}
	if (keycode == 65364)
	{
		vars->size -= 1;
		ft_bzero(vars->addr, 1920 * 1080 *(vars->bpp / 8));
		generategrid(vars, vars->map, vars->size);
	}
	if (keycode == 113)
	{
		vars->defaultx += 5;
		ft_bzero(vars->addr, 1920 * 1080 *(vars->bpp / 8));
		generategrid(vars, vars->map, vars->size);
	}
	if (keycode == 100)
	{
		vars->defaultx -= 5;
		ft_bzero(vars->addr, 1920 * 1080 *(vars->bpp / 8));
		generategrid(vars, vars->map, vars->size);
	}
	if (keycode == 122)
	{
		vars->defaulty += 5;
		ft_bzero(vars->addr, 1920 * 1080 *(vars->bpp / 8));
		generategrid(vars, vars->map, vars->size);
	}
	if (keycode == 115)
	{
		vars->defaulty -= 5;
		ft_bzero(vars->addr, 1920 * 1080 *(vars->bpp / 8));
		generategrid(vars, vars->map, vars->size);
	}
	return (0);
}
/*
int mouse_event(int button, int x, int y, void *param)
{
    t_vars *tutorial = param;
    (void)button;
    mlx_pixel_put(tutorial->mlx, tutorial->win, x, y, 0xFFFFFF);
    
    return (1);
}*/
