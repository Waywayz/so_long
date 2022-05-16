/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:04:41 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/06 18:11:52 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	length_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (--i);
}

void	error_map(int n, char **map)
{
	if (n == 1)
		ft_printf("ERROR WALL\n");
	if (n == 2)
		ft_printf("ERROR RECTANGLE\n");
	if (n == 3)
		ft_printf("ERROR START/END\n");
	if (n == 4)
		ft_printf("ERROR ITEM\n");
	if (n == 5)
		ft_printf("ERROR CHAR\n");
	free_map(map);
	exit(0);
}

void	check_c_e_p(char **map)
{
	int	i;
	int	j;
	int	k;
	int	c;

	i = -1;
	k = 0;
	c = 0;
	while (map[++i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'E')
				k += 1;
			if (map[i][j] == 'C')
				c += 1;
			j++;
		}
		j = 0;
	}
	if (k != 2)
		error_map(3, map);
	if (c < 1)
		error_map(4, map);
	return ;
}

void	check_carac(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != '0' &&
				map[i][j] != 'P' && map[i][j] != 'E')
				error_map(5, map);
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

void	check_map(char **map)
{
	int		i;
	int		l;
	size_t	j;
	int		k;

	i = 1;
	k = 0;
	l = length_map(map);
	j = ft_strlen(map[0]);
	check_carac(map);
	while (map[i])
	{
		if (j != ft_strlen(map[i]))
			error_map(2, map);
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			error_map(1, map);
		while (map[i][k])
		{
			if (map[0][k] != '1' || map[l][k] != '1')
				error_map(1, map);
			k++;
		}
		i++;
	}
	check_c_e_p(map);
}
