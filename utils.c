/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:55:03 by aharder           #+#    #+#             */
/*   Updated: 2024/12/20 12:22:01 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdfheader.h"

t_coords	coords(int x, int y)
{
	t_coords	coordinate;

	coordinate.x = x;
	coordinate.y = y;
	return (coordinate);
}

int	abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	ft_swap(int *a, int *b)
{
	int	buffer;

	buffer = *a;
	*a = *b;
	*b = buffer;
}

float	fpart(float number)
{
	if (number > 0)
		return (number - (int)number);
	else
		return (number - ((int)number + 1));
}

int	color(int r, int g, int b, float transparency)
{
	int	trgb;

	trgb = create_trgb(0, r * transparency, g * transparency, b * transparency);
	return (trgb);
}
