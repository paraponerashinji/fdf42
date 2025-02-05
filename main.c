/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:17:28 by aharder           #+#    #+#             */
/*   Updated: 2024/12/20 11:48:45 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdfheader.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	(void)argc;
	vars.map = getmap(argv[1]);
	createwindow(vars);
}

void	createwindow(t_vars va)
{
	va.size = 2;
	va.defaultx = 1920 / 2 - ((va.map.sizex / va.size) * 8);
	va.defaulty = 525;
	va.mlx = mlx_init();
	va.win = mlx_new_window(va.mlx, 1920, 1080, "FdF V2");
	va.img = mlx_new_image(va.mlx, 1920, 1920);
	va.addr = mlx_get_data_addr(va.img, &va.bpp, &va.line, &va.endian);
	generategrid(&va, va.map, va.size);
	mlx_hook(va.win, 2, 1L << 0, key_hook, &va);
	mlx_hook(va.win, 17, 0, free_and_exit, &va);
	mlx_loop(va.mlx);
}

/*
void	printmap(t_map map)
{
	int	i;
	int	ii;
	
	i = 0;
	while (i < map.sizey)
	{
		ii = 0;
		while (ii < map.sizex)
		{
			printf("%i ", map.alt[i][ii]);
			ii++;
		}
		i++;
		printf("\n");
	}
}*/
