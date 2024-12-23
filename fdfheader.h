/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfheader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:57:26 by aharder           #+#    #+#             */
/*   Updated: 2024/12/22 17:17:47 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "mlx.h"
#include "get_next_line.h"
#include "libft.h"

typedef struct s_map
{
	int	**alt;
	int	sizey;
	int	sizex;
}	t_map;

typedef struct s_camera
{
	int		fov;
	double	x_perspective;
	double	y_perspective;
	double	z_perspective;
}	t_camera;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_utils
{
	int	i;
	int	j;
	int	xbuffer;
	int	ybuffer;
	int	steep;
}	t_utils;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			size;
	int			defaultx;
	int			defaulty;
	int			bpp;
	int			line;
	int			endian;
	t_utils		utils;
	t_map		map;
	t_camera	camera;
}	t_vars;

// main.c || creating window and calling everything
int			main(int argc, char *argv[]); // TODO nice thing with error handling
void		createwindow(t_vars vars); // TODO clean shit
void		printmap(t_map map);

// getmap.c || Parsing the file to put the map in an array
t_map		getmap(char *file); // TODO cleaning and map error handling
void	free_map(t_map map);
// colors.c || Manipulating rgb colors
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

// utils.c || Some utils
t_coords	coords(int x, int y);
int			ABS(int x);
void		ft_swap(int *a, int *b);
float		fpart(float	number);
int			color(int r, int g, int b, float transparency);

// drawing.c
void		drawline(t_vars *data, t_coords start, t_coords end); // TODO colorhandling
void		generategrid(t_vars *data, t_map map, float size);
void		pixel_put(t_vars *data, int x, int y, int color);
// draw_utils.c
void		draw_pixel(t_vars *data, int x, float y);
// TODO better zoom because this thing is shit
// math.c
/*
// TODO camera and rotation shit
t_coords	projectpoint(int x, int y, t_vars vars);
void	rotate_x(int *y, int *z, double x_perspective);
void	rotate_y(int *x, int *z, double y_perspective);
void	rotate_z(int *x, int *y, double z_perspective);

*/
// events.c
int     key_hook(int keycode, t_vars *vars); // TODO cleaning in separate functions
