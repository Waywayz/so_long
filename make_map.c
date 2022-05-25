/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:13:46 by rovillar          #+#    #+#             */
/*   Updated: 2022/05/25 17:56:13 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_map_rl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_printf("ERROR RETURN LINE\n");
			free(str);
			exit(1);
		}
		i++;
	}
}

void	error_fd(void)
{
	ft_printf("ERROR FD\n");
	exit(1);
}

static char	*convert_map(char **map)
{
	int		fd;
	char	*str;
	char	*line;

	fd = open(*map, O_RDONLY);
	str = ft_strdup("");
	if (fd < 0)
		error_fd();
	line = get_next_line(fd);
	if (!line)
		error_fd();
	while (line)
	{
		str = ft_strjoin(str, line);
		if (!str)
			return (0);
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}

char	**make_map(char **av)
{
	char	*str;
	char	**map;

	str = convert_map(av);
	check_map_rl(str);
	map = ft_split(str, '\n');
	if (!map)
		return (0);
	free(str);
	check_map(map);
	return (map);
}
