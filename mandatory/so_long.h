/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:00:04 by afarachi          #+#    #+#             */
/*   Updated: 2024/07/31 12:21:17 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"

# define A_KEY					97
# define W_KEY					119
# define S_KEY					115
# define D_KEY					100
# define ESC					65307
# define SPRITE_H				64
# define SPRITE_W				64
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17

typedef struct l_position
{
	int	width;
	int	height;
}	t_position;

typedef struct l_map
{
	t_position	size;
	char		**data;
}	t_map;

typedef struct l_img
{
	void		*img_ptr;
	char		*spt_path;
	t_position	size;
	t_position	pos;
}	t_imgg;

typedef struct k_game
{
	int			count_collec;
	int			count_steps;
}	t_game;

typedef struct s_var
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_imgg		img;
}	t_var;

//so_long.c
void		init_game(t_var *var);
void		check_args(int argc, char **argv, t_var var);
int			ft_expose(t_var *var);
//map_validation1.c
void		is_surrounded_by_walls(t_var var);
void		is_rectangular(t_var var);
void		contains_one_exit(t_var var);
int			contains_at_least_one_collectible(t_var var);
void		contains_one_starting_position(t_var var);
//map_validation2.c
void		contains_only_valid_items(t_var var);
t_position	find_starting_position(char **data, t_position size);
void		check_pathandcollectibles(t_var var, int **visited);
void		has_valid_paths(t_var var);
void		check_map(t_var var);
//maps.c
int			count_lines(char *filename, t_var *var);
void		read_map_data(t_var *var, char *filename);
void		get_map(t_var *var, char **argv);
void		load_map(t_var var, int row, int col);
void		print_map(t_var var);
//utils.c
int			error(char *msg, t_var *var);
int			error1(char *msg, t_var *var, int **visited);
void		dfs(char **data, t_position current,
				t_position size, int **visited);
//game.c
void		get_init_position(t_var *var);
int			count_collec(t_var *var);
void		check_collect(t_var *var);
void		print_steps(t_var *var);
//movements_AWDS.c
void		move_left(t_var *var);
void		move_right(t_var *var);
void		move_down(t_var *var);
void		move_up(t_var *var);
void		movements(int key, t_var *var);
//keys_management.c
int			mlx_close(t_var *var);
int			key_press(int key, t_var *var);
//free.c
void		free_map(t_var *var);
int			free_exit(t_var *var, char *msg);
void		free_visited(int **visited, t_position size);

#endif