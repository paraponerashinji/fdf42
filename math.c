/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:28:51 by aharder           #+#    #+#             */
/*   Updated: 2024/12/19 17:56:14 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_coords	projectpoint(int x, int y, t_vars vars)
{
	t_coords	coords;

	coords.z = vars->map->alt[x][y]
	coords.x = x;
	coords.y = y;
}

void	rotate_x(int *y, int *z, double x_perspective)
{
}

void	rotate_y(int *x, int *z, double y_perspective)
{
}

void	rotate_z(int *x, int *y, double z_perspective)
{
}
