/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:21:23 by afarachi          #+#    #+#             */
/*   Updated: 2024/08/02 12:09:15 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error(char *msg, t_var *var)
{
	printf("\e[31m\e[1mError\n%s \e[0m \n", msg);
	free_map(var);
	exit (EXIT_FAILURE);
}

int	error1(char *msg, t_var *var, int **visited)
{
	printf("\e[31m\e[1mError\n%s \e[0m \n", msg);
	if (visited)
		free_visited(visited, var->map.size);
	free_map(var);
	exit (EXIT_FAILURE);
}

void	dfs(char **data, t_position current, t_position size, int **visited)
{
	int			i;
	t_position	next_positions[4];

	next_positions[0].w = current.w;
	next_positions[0].h = current.h + 1;
	next_positions[1].w = current.w;
	next_positions[1].h = current.h - 1;
	next_positions[2].w = current.w + 1;
	next_positions[2].h = current.h;
	next_positions[3].w = current.w - 1;
	next_positions[3].h = current.h;
	if (current.h < 0 || current.h >= size.h
		|| current.w < 0 || current.w >= size.w
		|| data[current.h][current.w] == '1'
		|| visited[current.h][current.w])
		return ;
	visited[current.h][current.w] = 1;
	i = 0;
	while (i < 4)
	{
		dfs(data, next_positions[i], size, visited);
		i++;
	}
}
