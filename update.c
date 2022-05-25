/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:11:26 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/06 19:11:42 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	refresh(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, g_lenght, g_height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->ll, &mlx->end);
}

int	core(t_mlx *mlx)
{
	draw_map(mlx, mlx->plyr->map);
	if (mlx->plyr->end == 1)
		mlx_string_put(mlx->mlx, mlx->mlx_win, g_lenght / 2, g_height / 2,
			0x0000FFFF, "END !!");
	return (0);
}

int	update(void *mlx)
{
	refresh((t_mlx *)mlx);
	keyboard((t_mlx *)mlx);
	gameplay((t_mlx *)mlx);
	core((t_mlx *)mlx);
	return (0);
}
