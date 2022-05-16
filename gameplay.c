/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:17:27 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/06 18:17:55 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	new_pos(char **map, t_pos *pos, t_move move)
{
	if (move.up)
		map[pos->y - 1][pos->x] = 'P';
	else if (move.down)
		map[pos->y + 1][pos->x] = 'P';
	else if (move.right)
		map[pos->y][pos->x + 1] = 'P';
	else if (move.left)
		map[pos->y][pos->x - 1] = 'P';
	else
		return (0);
	map[pos->y][pos->x] = '0';
	return (1);
}

t_pos	*player_pos(char **map)
{
	t_pos	*pos;
	int		x;
	int		y;

	pos = malloc(sizeof(t_pos));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				pos->x = x;
				pos->y = y;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

void	reset_move(t_move *move)
{
	move->up = 0;
	move->down = 0;
	move->left = 0;
	move->right = 0;
}

void	move_player(t_mlx *mlx)
{
	t_pos	*pos;
	t_move	move;

	move = mlx->plyr->move;
	pos = player_pos(mlx->plyr->map);
	if (pos && !wall_move(mlx->plyr->map, pos, move))
		item_move(mlx, pos, move);
	if (pos)
		free(pos);
	reset_move(&mlx->plyr->move);
}

void	gameplay(t_mlx *mlx)
{
	if (mlx->plyr->end == 1)
		return ;
	move_player((t_mlx *)mlx);
}
