/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:38:06 by aharder           #+#    #+#             */
/*   Updated: 2024/12/20 16:41:57 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdfheader.h"

void	draw_pixel(t_vars *data, int x, float y)
{
	if (data->utils.steep)
	{
		pixel_put(data, (int)y - 1, x, color(40, 255, 0, 1 - fpart(y)));
		pixel_put(data, (int)y, x, color(40, 255, 0, fpart(y)));
	}
	else
	{
		pixel_put(data, x, (int)y - 1, color(40, 255, 0, 1 - fpart(y)));
		pixel_put(data, x, (int)y, color(40, 255, 0, fpart(y)));
	}
}
