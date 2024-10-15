/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:00:21 by afarachi          #+#    #+#             */
/*   Updated: 2024/08/03 15:01:20 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_init_position(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var->map.size.height)
	{
		col = 0;
		while (col <= var->map.size.width)
		{
			if (var->map.data[row][col] == 'P')
			{
				var->img.pos.width = col;
				var->img.pos.height = row;
			}
			col++;
		}
		row++;
	}
}

int	count_collec(t_var *var)
{
	int		row;
	int		col;

	row = 0;
	var->game.count_collec = 0;
	while (row < var->map.size.height)
	{
		col = 0;
		while (col <= var->map.size.width)
		{
			if (var->map.data[row][col] == 'C')
				var->game.count_collec++;
			col++;
		}
		row++;
	}
	return (var->game.count_collec);
}

void	check_collect(t_var *var)
{
	if (count_collec(var) == 0)
	{
		free_exit(var, "\e[32m\e[5m\e[1m🎉CONGRATULATIONS🎉\n! You WON !\n");
	}
	else
		printf("\e[35m\e[1mPlease, collect all the balls!!!\e[0m\n");
}

void	print_steps(t_var *var)
{
	char	*str;

	str = ft_itoa(var->game.count_steps);
	mlx_string_put(var->mlx, var->win, (var->img.pos.width * SPRITE_W) + 5,
		(var->img.pos.height * SPRITE_H) + 10, 0x833000, str);
	free(str);
}
