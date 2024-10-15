/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:00:01 by afarachi          #+#    #+#             */
/*   Updated: 2024/07/31 12:21:09 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	next_positions[0].width = current.width;
	next_positions[0].height = current.height + 1;
	next_positions[1].width = current.width;
	next_positions[1].height = current.height - 1;
	next_positions[2].width = current.width + 1;
	next_positions[2].height = current.height;
	next_positions[3].width = current.width - 1;
	next_positions[3].height = current.height;
	if (current.height < 0 || current.height >= size.height
		|| current.width < 0 || current.width >= size.width
		|| data[current.height][current.width] == '1'
		|| visited[current.height][current.width])
		return ;
	visited[current.height][current.width] = 1;
	i = 0;
	while (i < 4)
	{
		dfs(data, next_positions[i], size, visited);
		i++;
	}
}
