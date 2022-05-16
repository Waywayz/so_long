/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:12:07 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/06 19:16:06 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>

# define MAPSIZE 64

int	g_lenght;
int	g_height;

typedef struct s_img
{
	void			*img;
	unsigned int	*addr;
	int				ll;
	int				bpp;
	int				end;
}		t_img;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_textures
{
	t_img	p;
	t_img	c;
	t_img	e;
	t_img	w;
	t_img	s;
}		t_textures;

typedef struct s_move
{
	int	up;
	int	down;
	int	right;
	int	left;
}		t_move;

typedef struct s_player
{
	t_move	move;
	int		coins;
	int		step;
	int		end;
	char	**map;
	int		pressed;
}		t_player;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		**map;
	char		*addr;
	int			bpp;
	int			ll;
	int			end;
	t_textures	tex;
	t_player	*plyr;
}		t_mlx;

int		ft_printf(const char *input, ...);
void	check_map(char **map);
char	**make_map(char **av);
void	draw_map(t_mlx *mlx, char **map);
void	init_texture(t_mlx *mlx);
t_mlx	*init_graphic(char **map);
int		update(void *mlx);
void	keyboard(t_mlx *mlx);
int		total_coins(t_mlx *mlx);
void	gameplay(t_mlx *mlx);
void	init_player(t_mlx *mlx, char **map);
int		check_move(t_move move);
int		wall_move(char **map, t_pos *pos, t_move move);
void	item_move(t_mlx *mlx, t_pos *pos, t_move move);
int		exit_move(char **map, t_pos *pos, t_move move);
int		new_pos(char **map, t_pos *pos, t_move move);
void	free_map(char **map);

#endif
