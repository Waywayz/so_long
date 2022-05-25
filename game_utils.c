/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:14:52 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/06 18:17:05 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	total_coins(t_mlx *mlx)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while (mlx->plyr->map[i])
	{
		j = 0;
		while (mlx->plyr->map[i][j])
		{
			if (mlx->plyr->map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}
