/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:00:14 by afarachi          #+#    #+#             */
/*   Updated: 2024/08/03 15:12:05 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	contains_only_valid_items(t_var var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var.map.size.height)
	{
		j = 0;
		while (j < var.map.size.width)
		{
			if (var.map.data[i][j] != '1' && var.map.data[i][j] != '0' &&
			var.map.data[i][j] != 'E' && var.map.data[i][j] != 'P' &&
			var.map.data[i][j] != 'C')
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
	start.width = -1;
	start.height = -1;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			if (data[i][j] == 'P')
			{
				start.height = i;
				start.width = j;
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
	while (i < var.map.size.height)
	{
		j = 0;
		while (j < var.map.size.width)
		{
			if ((var.map.data[i][j] == 'E' || var.map.data[i][j] == 'C')
			&& !visited[i][j])
			{
				if (var.map.data[i][j] == 'E')
					error1("invalid map: no valid path!❗️❌❗️", &var, visited);
				if (var.map.data[i][j] == 'C')
					error1("invalid map:not all C r reachable!", &var, visited);
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

	size.width = var.map.size.width;
	size.height = var.map.size.height;
	visited = (int **)malloc(var.map.size.height * sizeof(int *));
	if (!visited)
		free_map(&var);
	i = 0;
	while (i < var.map.size.height)
	{
		visited[i] = (int *)ft_calloc(var.map.size.width, sizeof(int));
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
