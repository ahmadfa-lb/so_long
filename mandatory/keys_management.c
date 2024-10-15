/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:00:19 by afarachi          #+#    #+#             */
/*   Updated: 2024/08/03 15:10:06 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_close(t_var *var)
{
	free_exit(var, "\e[33m\e[1mGame closed! (❌)\e[0m\n");
	return (0);
}

int	key_press(int key, t_var *var)
{
	int	init_steps;

	init_steps = 0;
	init_steps = var->game.count_steps;
	if (key == ESC)
		free_exit(var, "\e[33m\e[1mGame closed! (ESC)\e[0m\n");
	else
		movements(key, var);
	if (init_steps != var->game.count_steps)
		printf("⟹ 📍 Steps: %d\n", var->game.count_steps);
	print_map(*var);
	print_steps(var);
	return (0);
}
