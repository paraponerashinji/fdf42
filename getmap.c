/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharder <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:51:21 by aharder           #+#    #+#             */
/*   Updated: 2024/12/20 12:20:06 by aharder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdfheader.h"

void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.sizey)
	{
		free(map.alt[i]);
		i++;
	}
	free(map.alt);
}

t_map	get_size(char *file)
{
	int		fd;
	t_map	map;
	char	*line;
	char	**splittedline;

	map.sizey = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map.sizex = 0;
		splittedline = ft_split(line, ' ');
		free(line);
		while (splittedline[map.sizex] != NULL)
		{
			free(splittedline[map.sizex]);
			map.sizex++;
		}
		free(splittedline);
		map.sizey++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	*parse_line(char *line, int size)
{
	int		*alt_line;
	char	**splittedline;
	int		i;

	alt_line = ft_calloc(size, sizeof(int));
	if (!alt_line)
		return (NULL);
	splittedline = ft_split(line, ' ');
	free(line);
	i = 0;
	while (splittedline[i])
	{
		alt_line[i] = ft_atoi(splittedline[i]);
		free(splittedline[i]);
		i++;
	}
	free(splittedline);
	return (alt_line);
}

t_map	getmap(char *file)
{
	int		fd;
	t_map	map;
	int		i;

	map = get_size(file);
	map.alt = ft_calloc((map.sizey + 1), sizeof(int *));
	fd = open(file, O_RDONLY);
	i = 0;
	file = get_next_line(fd);
	while (file != NULL)
	{
		map.alt[i] = parse_line(file, map.sizex);
		i++;
		file = get_next_line(fd);
	}
	return (map);
}
