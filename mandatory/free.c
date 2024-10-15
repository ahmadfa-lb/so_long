/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:00:25 by afarachi          #+#    #+#             */
/*   Updated: 2024/07/31 11:59:55 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_var *var)
{
	int	row;

	row = 0;
	if (var->mlx)
	{
		mlx_destroy_window(var->mlx, var->win);
		mlx_destroy_display(var->mlx);
	}
	free(var->mlx);
	while (row < var->map.size.height)
	{
		free(var->map.data[row]);
		row++;
	}
	free(var->map.data);
}

int	free_exit(t_var *var, char *msg)
{
	printf("%s", msg);
	free_map(var);
	exit(EXIT_SUCCESS);
}

void	free_visited(int **visited, t_position size)
{
	int	i;

	i = 0;
	while (i < size.height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
