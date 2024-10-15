/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movements_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 03:49:12 by afarachi          #+#    #+#             */
/*   Updated: 2024/07/31 05:19:35 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_move_right(t_var *var)
{
	if (var->map.data[var->enemy.pos.h][var->enemy.pos.w + 1] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map.data[var->enemy.pos.h][var->enemy.pos.w] = '0';
	var->enemy.pos.w += 1;
	var->map.data[var->enemy.pos.h][var->enemy.pos.w] = 'Y';
	var->game.enemy_count++;
}

void	enemy_move_down(t_var *var)
{
	if (var->map.data[var->enemy.pos.h + 1][var->enemy.pos.w] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map.data[var->enemy.pos.h][var->enemy.pos.w] = '0';
	var->enemy.pos.h += 1;
	var->map.data[var->enemy.pos.h][var->enemy.pos.w] = 'Y';
	var->game.enemy_count++;
}

void	enemy_move_left(t_var *var)
{
	if (var->map.data[var->enemy.pos.h][var->enemy.pos.w - 1] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map.data[var->enemy.pos.h][var->enemy.pos.w] = '0';
	var->enemy.pos.w -= 1;
	var->map.data[var->enemy.pos.h][var->enemy.pos.w] = 'Y';
	var->game.enemy_count++;
}

void	enemy_move_up(t_var *var)
{
	if (var->map.data[var->enemy.pos.h - 1][var->enemy.pos.w] == 'P')
		free_exit(var, "\e[31m\e[1mGAME OVER\n!!!! You LOST !!!!\e[0m\n");
	var->map.data[var->enemy.pos.h][var->enemy.pos.w] = '0';
	var->enemy.pos.h -= 1;
	var->map.data[var->enemy.pos.h][var->enemy.pos.w] = 'Y';
	var->game.enemy_count++;
}

int	enemy_patrol(t_var *var)
{
	usleep(200000);
	get_enemy_position(var);
	if ((var->map.data[var->enemy.pos.h][var->enemy.pos.w + 1] == '0'
		|| var->map.data[var->enemy.pos.h][var->enemy.pos.w + 1] == 'P')
		&& var->game.enemy_count < var->map.size.w)
		enemy_move_right(var);
	else if ((var->map.data[var->enemy.pos.h + 1][var->enemy.pos.w] == '0'
		|| var->map.data[var->enemy.pos.h + 1][var->enemy.pos.w] == 'P')
		&& var->game.enemy_count < (var->map.size.w + var->map.size.h))
		enemy_move_down(var);
	else if ((var->map.data[var->enemy.pos.h][var->enemy.pos.w - 1] == '0'
		|| var->map.data[var->enemy.pos.h][var->enemy.pos.w - 1] == 'P')
		&& var->game.enemy_count < ((2 * var->map.size.w) + var->map.size.h))
		enemy_move_left(var);
	else if ((var->map.data[var->enemy.pos.h - 1][var->enemy.pos.w] == '0'
		|| var->map.data[var->enemy.pos.h - 1][var->enemy.pos.w] == 'P')
		&& var->game.enemy_count < (2 * (var->map.size.w + var->map.size.h)))
		enemy_move_up(var);
	else
		var->game.enemy_count = 0;
	print_map(*var);
	print_steps(var);
	return (0);
}
