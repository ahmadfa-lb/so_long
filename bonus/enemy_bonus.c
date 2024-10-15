/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 02:59:03 by afarachi          #+#    #+#             */
/*   Updated: 2024/08/03 12:59:00 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_enemy(t_var *var)
{
	int		i;
	int		j;

	i = 0;
	while (i < var->map.size.h)
	{
		j = 0;
		while (var->map.data[i][j])
		{
			if (var->map.data[i][j] == 'Y')
				var->enemy_detected++;
			j++;
		}
		i++;
	}
}

void	get_enemy_position(t_var *var)
{
	int		i;
	int		j;

	i = 0;
	while (i < var->map.size.h)
	{
		j = 0;
		while (j <= var->map.size.w)
		{
			if (var->map.data[i][j] == 'Y')
			{
				var->enemy.pos.w = j;
				var->enemy.pos.h = i;
			}
			j++;
		}
		i++;
	}
}

void	hit_the_enemy(int key, t_var *var)
{
	if ((key == A_KEY)
		&& (var->map.data[var->img.pos.h][var->img.pos.w - 1] == 'Y'))
	{
		free_exit(var, "\e[31m\e[1m☢️ GAME OVER\n!! You LOST💥 !!\e[0m\n");
	}
	if ((key == D_KEY)
		&& (var->map.data[var->img.pos.h][var->img.pos.w + 1] == 'Y'))
	{
		free_exit(var, "\e[31m\e[1m☢️ GAME OVER\n!! You LOST💥 !!\e[0m\n");
	}
	if ((key == S_KEY)
		&& (var->map.data[var->img.pos.h + 1][var->img.pos.w] == 'Y'))
	{
		free_exit(var, "\e[31m\e[1m☢️ GAME OVER\n!! You LOST💥 !!\e[0m\n");
	}
	if ((key == W_KEY)
		&& (var->map.data[var->img.pos.h - 1][var->img.pos.w] == 'Y'))
	{
		free_exit(var, "\e[31m\e[1m☢️ GAME OVER\n!! You LOST💥 !!\e[0m\n");
	}
}

void	enemy_animation(t_var *var)
{
	if (var->enemy.pos.w % 2 == 0)
		var->img.img_ptr = mlx_xpm_file_to_image(var->mlx, "./img/enemy1.xpm",
				&var->img.size.w, &var->img.size.h);
	else
		var->img.img_ptr = mlx_xpm_file_to_image(var->mlx, "./img/enemy2.xpm",
				&var->img.size.w, &var->img.size.h);
}
