/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:10:36 by rovillar          #+#    #+#             */
/*   Updated: 2022/05/25 16:53:12 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
}

int	main(int ac, char **av)
{
	char	**map;
	t_mlx	*mlx;

	if (ac != 2)
	{
		ft_printf("ERROR ARGUMENT\n");
		return (0);
	}
	map = make_map(&av[1]);
	mlx = init_graphic(map);
	init_texture(mlx);
	init_player(mlx, map);
	mlx_loop_hook(mlx->mlx, update, mlx);
	mlx_loop(mlx);
	return (0);
}
