/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:05:04 by aharder           #+#    #+#             */
/*   Updated: 2024/12/20 16:42:43 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdfheader.h"

void	pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = data->addr + (y * data->line + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	swap(t_vars *data, t_coords *start, t_coords *end)
{
	data->utils.steep = abs(end->y - start->y) > abs(end->x - start->x);
	if (data->utils.steep)
	{
		ft_swap(&start->x, &start->y);
		ft_swap(&end->x, &end->y);
	}
	if (start->x > end->x)
	{
		ft_swap(&start->x, &end->x);
		ft_swap(&start->y, &end->y);
	}
}

void	drawline(t_vars *data, t_coords start, t_coords end)
{
	float	pixel;
	float	y;
	int		x;

	swap(data, &start, &end);
	pixel = (float)abs(end.y - start.y) / abs(end.x - start.x);
	y = start.y;
	x = start.x;
	while (x <= end.x)
	{
		draw_pixel(data, x, y);
		if (end.y > start.y)
			y += pixel;
		else
			y += -pixel;
		x++;
	}
}

void	draw_tile(t_vars *d, t_map map, t_coords c, float size)
{
	int	alt0;
	int	alt1;
	int	alt2;

	while (d->utils.j < map.sizex)
	{
		if (d->utils.i < map.sizey && d->utils.j < map.sizex)
			alt0 = map.alt[d->utils.i][d->utils.j] * (size / 3);
		if (d->utils.j != map.sizex - 1)
		{
			alt1 = map.alt[d->utils.i][d->utils.j + 1] * (size / 3);
			drawline(d, coords(c.x, c.y - alt0),
				coords(c.x + 2 * size, c.y - alt1 - size));
		}
		if (d->utils.i != map.sizey - 1)
		{
			alt2 = map.alt[d->utils.i + 1][d->utils.j] * (size / 3);
			drawline(d, coords(c.x, c.y - alt0),
				coords(c.x + size * 2, c.y - alt2 + size));
		}
		c.x += size * 2;
		c.y -= size;
		d->utils.j++;
	}
}

void	generategrid(t_vars *data, t_map map, float size)
{
	int	x;
	int	y;
	int	sizey;
	int	sizex;

	sizex = 2 * size;
	sizey = sizex / 2;
	x = data->defaultx;
	y = data->defaulty;
	data->utils.i = 0;
	while (data->utils.i < map.sizey)
	{
		data->utils.j = 0;
		draw_tile(data, map, coords(x, y), size);
		x += sizex;
		y += sizey;
		data->utils.i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
