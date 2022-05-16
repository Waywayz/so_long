/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poss_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:11:02 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/06 19:11:05 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_move(char **map, t_pos *pos, t_move move)
{
	if (move.up && map[pos->y - 1][pos->x] == '1')
		return (1);
	else if (move.down && map[pos->y + 1][pos->x] == '1')
		return (1);
	else if (move.right && map[pos->y][pos->x + 1] == '1')
		return (1);
	else if (move.left && map[pos->y][pos->x - 1] == '1')
		return (1);
	return (0);
}

int	coins_move(char **map, t_pos *pos, t_move move)
{
	if (move.up && map[pos->y - 1][pos->x] == 'C')
		return (1);
	else if (move.down && map[pos->y + 1][pos->x] == 'C')
		return (1);
	else if (move.right && map[pos->y][pos->x + 1] == 'C')
		return (1);
	else if (move.left && map[pos->y][pos->x - 1] == 'C')
		return (1);
	return (0);
}

void	item_move(t_mlx *mlx, t_pos *pos, t_move move)
{
	if (exit_move(mlx->plyr->map, pos, move))
	{
		if (mlx->plyr->coins <= 0)
		{
			mlx->plyr->map[pos->y][pos->x] = '0';
			mlx->plyr->step++;
			ft_printf("STEPS : %d\n", mlx->plyr->step);
			ft_printf("GGWP !!\n");
			mlx->plyr->end = 1;
			return ;
		}
	}
	else
	{
		if (check_move(move) && mlx->plyr->pressed == 1)
		{
			mlx->plyr->step++;
			ft_printf("STEPS : %d\n", mlx->plyr->step);
			mlx->plyr->pressed = 0;
		}
		if (coins_move(mlx->plyr->map, pos, move))
			mlx->plyr->coins--;
		new_pos(mlx->plyr->map, pos, move);
	}
}

int	exit_move(char **map, t_pos *pos, t_move move)
{
	if (move.up && map[pos->y - 1][pos->x] == 'E')
		return (1);
	else if (move.down && map[pos->y + 1][pos->x] == 'E')
		return (1);
	else if (move.right && map[pos->y][pos->x + 1] == 'E')
		return (1);
	else if (move.left && map[pos->y][pos->x - 1] == 'E')
		return (1);
	return (0);
}
