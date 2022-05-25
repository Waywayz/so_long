/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:23:20 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/06 19:10:13 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_pixel(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if (x < g_lenght && x >= 0 && y < g_height && y >= 0)
	{
		dst = data->addr + (y * data->ll + x * (data->bpp / 8));
		*(unsigned int *) dst = color;
	}
}

static void	draw_texture(t_mlx *mlx, int x, int y, t_img tex)
{
	int	i;
	int	j;
	int	pos;

	i = y;
	while (i < y + MAPSIZE)
	{
		j = x;
		while (j < x + MAPSIZE)
		{
			pos = ((i - y) * MAPSIZE + (j - x));
			mlx_pixel(mlx, j, i, tex.addr[pos]);
			j++;
		}
		i++;
	}
}

void	draw_other(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				draw_texture(mlx, j * MAPSIZE, i * MAPSIZE, mlx->tex.p);
			if (map[i][j] == 'E')
				draw_texture(mlx, j * MAPSIZE, i * MAPSIZE, mlx->tex.e);
			if (map[i][j] == 'C')
				draw_texture(mlx, j * MAPSIZE, i * MAPSIZE, mlx->tex.c);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
}

void	draw_map(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1')
				draw_texture(mlx, j * MAPSIZE, i * MAPSIZE, mlx->tex.s);
			else if (map[i][j] == '1')
				draw_texture(mlx, j * MAPSIZE, i * MAPSIZE, mlx->tex.w);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	draw_other(mlx, mlx->map);
}
