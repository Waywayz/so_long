/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:22:38 by rovillar          #+#    #+#             */
/*   Updated: 2022/05/30 16:15:47 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_mlx *mlx)
{
	free_map(mlx->map);
	free(mlx->plyr);
	free(mlx);
	exit(0);
	return (0);
}

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == 53 || key == 13 || key == 1 || key == 0 || key == 2)
		mlx->plyr->pressed = 1;
	if (key == 53)
		ft_exit(mlx);
	else if (key == 13)
		mlx->plyr->move.up = 1;
	else if (key == 1)
		mlx->plyr->move.down = 1;
	else if (key == 0)
		mlx->plyr->move.left = 1;
	else if (key == 2)
		mlx->plyr->move.right = 1;
	else
		return (0);
	return (1);
}

int	check_move(t_move move)
{
	if (move.up || move.down || move.right || move.left)
		return (1);
	return (0);
}

void	keyboard(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_win, 2, 0, key_pressed, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, ft_exit, mlx);
}
