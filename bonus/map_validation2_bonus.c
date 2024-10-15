/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:21:11 by afarachi          #+#    #+#             */
/*   Updated: 2024/08/03 14:35:45 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	contains_only_valid_items(t_var var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var.map.size.h)
	{
		j = 0;
		while (j < var.map.size.w)
		{
			if (var.map.data[i][j] != '1' && var.map.data[i][j] != '0' &&
			var.map.data[i][j] != 'E' && var.map.data[i][j] != 'P' &&
			var.map.data[i][j] != 'C' && var.map.data[i][j] != 'Y')
				error("Invalid map: unknown item detected❗️❌❗️", &var);
			j++;
		}
		i++;
	}
}

t_position	find_starting_position(char **data, t_position size)
{
	t_position	start;
	int			i;
	int			j;

	i = 0;
	start.w = -1;
	start.h = -1;
	while (i < size.h)
	{
		j = 0;
		while (j < size.w)
		{
			if (data[i][j] == 'P')
			{
				start.h = i;
				start.w = j;
				return (start);
			}
			j++;
		}
		i++;
	}
	return (start);
}

void	check_pathandcollectibles(t_var var, int **visited)
{
	int	i;
	int	j;

	i = 0;
	while (i < var.map.size.h)
	{
		j = 0;
		while (j < var.map.size.w)
		{
			if ((var.map.data[i][j] == 'E' || var.map.data[i][j] == 'C')
			&& !visited[i][j])
			{
				if (var.map.data[i][j] == 'E')
					error1("invalid map:there is no valid path", &var, visited);
				if (var.map.data[i][j] == 'C')
					error1("invalid map:not all C r reachbles", &var, visited);
				break ;
			}
			j++;
		}
		i++;
	}
}

void	has_valid_paths(t_var var)
{
	int			**visited;
	int			i;
	t_position	start;
	t_position	size;

	size.w = var.map.size.w;
	size.h = var.map.size.h;
	visited = (int **)malloc(var.map.size.h * sizeof(int *));
	if (!visited)
		free_map(&var);
	i = 0;
	while (i < var.map.size.h)
	{
		visited[i] = (int *)ft_calloc(var.map.size.w, sizeof(int));
		i++;
	}
	i = 0;
	start = find_starting_position(var.map.data, size);
	dfs(var.map.data, start, size, visited);
	check_pathandcollectibles(var, visited);
	i = 0;
	free_visited(visited, size);
}

void	check_map(t_var var)
{
	is_surrounded_by_walls(var);
	is_rectangular(var);
	contains_one_exit(var);
	contains_at_least_one_collectible(var);
	contains_one_starting_position(var);
	contains_only_valid_items(var);
	has_valid_paths(var);
}
