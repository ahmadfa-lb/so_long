/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_AWDS.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:00:09 by afarachi          #+#    #+#             */
/*   Updated: 2024/07/31 06:03:34 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_var *var)
{
	var->map.data[var->img.pos.height][var->img.pos.width] = '0';
	var->img.pos.width -= 1;
	var->map.data[var->img.pos.height][var->img.pos.width] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/sprite2.xpm";
}

void	move_right(t_var *var)
{
	var->map.data[var->img.pos.height][var->img.pos.width] = '0';
	var->img.pos.width += 1;
	var->map.data[var->img.pos.height][var->img.pos.width] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/sprite1.xpm";
}

void	move_down(t_var *var)
{
	var->map.data[var->img.pos.height][var->img.pos.width] = '0';
	var->img.pos.height += 1;
	var->map.data[var->img.pos.height][var->img.pos.width] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/sprite1.xpm";
}

void	move_up(t_var *var)
{
	var->map.data[var->img.pos.height][var->img.pos.width] = '0';
	var->img.pos.height -= 1;
	var->map.data[var->img.pos.height][var->img.pos.width] = 'P';
	var->game.count_steps++;
	var->img.spt_path = "./img/sprite1.xpm";
}

void	movements(int key, t_var *var)
{
	if ((key == A_KEY)
		&& (var->map.data[var->img.pos.height][var->img.pos.width - 1] == 'E'))
		check_collect(var);
	else if ((key == A_KEY)
		&& (var->map.data[var->img.pos.height][var->img.pos.width - 1] != '1'))
		move_left(var);
	if ((key == D_KEY)
		&& (var->map.data[var->img.pos.height][var->img.pos.width + 1] == 'E'))
		check_collect(var);
	else if ((key == D_KEY)
		&& (var->map.data[var->img.pos.height][var->img.pos.width + 1] != '1'))
		move_right(var);
	if ((key == S_KEY)
		&& (var->map.data[var->img.pos.height + 1][var->img.pos.width] == 'E'))
		check_collect(var);
	else if ((key == S_KEY)
		&& (var->map.data[var->img.pos.height + 1][var->img.pos.width] != '1'))
		move_down(var);
	if ((key == W_KEY)
		&& (var->map.data[var->img.pos.height - 1][var->img.pos.width] == 'E'))
		check_collect(var);
	else if ((key == W_KEY)
		&& (var->map.data[var->img.pos.height - 1][var->img.pos.width] != '1'))
		move_up(var);
}
