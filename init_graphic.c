/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:18:21 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/06 18:21:49 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_texture(t_mlx *mlx, int i)
{
	if (i == 0)
	{
		if (!mlx->tex.s.img || !mlx->tex.w.img || !mlx->tex.e.img
			|| !mlx->tex.p.img || !mlx->tex.c.img)
		{
			ft_printf("ERROR TEXTURE\n");
			free_map(mlx->map);
			free(mlx);
			exit(0);
		}
	}
	if (i == 1)
	{
		if (!mlx->tex.s.addr || !mlx->tex.w.addr || !mlx->tex.e.addr
			|| !mlx->tex.p.addr || !mlx->tex.c.addr)
		{
			ft_printf("ERROR TEXTURE\n");
			free_map(mlx->map);
			free(mlx);
			exit(0);
		}
	}
}

void	init_texture(t_mlx *mlx)
{
	int	h;
	int	l;

	mlx->tex.c.img = mlx_xpm_file_to_image(mlx->mlx, "./img/col.xpm", &l, &h);
	mlx->tex.p.img = mlx_xpm_file_to_image(mlx->mlx, "./img/plyr.xpm", &l, &h);
	mlx->tex.e.img = mlx_xpm_file_to_image(mlx->mlx, "./img/exit.xpm", &l, &h);
	mlx->tex.s.img = mlx_xpm_file_to_image(mlx->mlx, "./img/floor.xpm", &l, &h);
	mlx->tex.w.img = mlx_xpm_file_to_image(mlx->mlx, "./img/wall.xpm", &l, &h);
	check_texture(mlx, 0);
	mlx->tex.c.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.c.img,
			&mlx->tex.c.bpp, &mlx->tex.c.ll, &mlx->tex.c.end);
	mlx->tex.p.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.p.img,
			&mlx->tex.p.bpp, &mlx->tex.p.ll, &mlx->tex.p.end);
	mlx->tex.e.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.e.img,
			&mlx->tex.e.bpp, &mlx->tex.e.ll, &mlx->tex.e.end);
	mlx->tex.s.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.s.img,
			&mlx->tex.s.bpp, &mlx->tex.s.ll, &mlx->tex.s.end);
	mlx->tex.w.addr = (unsigned int *)mlx_get_data_addr(mlx->tex.w.img,
			&mlx->tex.w.bpp, &mlx->tex.w.ll, &mlx->tex.w.end);
	check_texture(mlx, 1);
}

void	resolution(char	**map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	g_height = i * MAPSIZE;
	g_lenght = ft_strlen(map[1]) * MAPSIZE;
}

void	init_player(t_mlx *mlx, char **map)
{
	mlx->plyr = malloc(sizeof(t_player));
	mlx->plyr->map = map;
	mlx->plyr->end = 0;
	mlx->plyr->step = 0;
	mlx->plyr->coins = total_coins(mlx);
}

t_mlx	*init_graphic(char **map)
{
	t_mlx	*mlx;

	resolution(map);
	mlx = malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, g_lenght, g_height, "so long");
	mlx->img = mlx_new_image(mlx->mlx, g_lenght, g_height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->ll, &mlx->end);
	mlx->map = map;
	return (mlx);
}
