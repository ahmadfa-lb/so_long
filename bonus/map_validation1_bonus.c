/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:21:08 by afarachi          #+#    #+#             */
/*   Updated: 2024/08/03 12:44:17 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	is_surrounded_by_walls(t_var var)
{
	int	i;

	i = 0;
	while (i < var.map.size.w)
	{
		if (var.map.data[0][i] != '1' ||
		var.map.data[var.map.size.h - 1][i] != '1')
			error("Invalid map: top or down wall not configured❗️❌❗️", &var);
		i++;
	}
	i = 0;
	while (i < var.map.size.h)
	{
		if (var.map.data[i][0] != '1' ||
		var.map.data[i][var.map.size.w - 1] != '1')
			error("Invalid map: lateral wall not configured❗️❌❗️", &var);
		i++;
	}
}

void	is_rectangular(t_var var)
{
	int	i;

	i = 0;
	while (i < var.map.size.h)
	{
		if (ft_strlen1(var.map.data[i]) != var.map.size.w)
			error("Invalid map: not a retangle❗️❌❗️", &var);
		i++;
	}
}

void	contains_one_exit(t_var var)
{
	int	exit_count;
	int	i;
	int	j;

	exit_count = 0;
	i = 0;
	while (i < var.map.size.h)
	{
		j = 0;
		while (j < var.map.size.w)
		{
			if (var.map.data[i][j] == 'E')
			{
				exit_count++;
				if (exit_count > 1)
					error("Invalid map: more than  one E detected❗️❌❗️", &var);
			}
			j++;
		}
		i++;
	}
	if (exit_count == 0)
		error("Invalid map: no E detected❗️❌❗️", &var);
}

int	contains_at_least_one_collectible(t_var var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var.map.size.h)
	{
		j = 0;
		while (j < var.map.size.w)
		{
			if (var.map.data[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	error("invalid map : no collectibles detected❗️❌❗️", &var);
	return (0);
}

void	contains_one_starting_position(t_var var)
{
	int	start_count;
	int	i;
	int	j;

	start_count = 0;
	i = 0;
	while (i < var.map.size.h)
	{
		j = 0;
		while (j < var.map.size.w)
		{
			if (var.map.data[i][j] == 'P')
				start_count++;
			j++;
		}
		i++;
	}
	if (start_count == 0)
		error("Invalid map: no starting position detected❗️❌❗️", &var);
	if (start_count > 1)
		error("Invalid map: more than  one P detected❗️❌❗️", &var);
}
