/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 05:21:13 by afarachi          #+#    #+#             */
/*   Updated: 2024/07/31 05:24:47 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_lines(char *filename, t_var *var)
{
	int		fd;
	int		num_lines;
	char	*line;

	num_lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("map not found", var);
	line = get_next_line(fd);
	while (line != NULL)
	{
		num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (num_lines);
}

void	read_map_data(t_var *var, char *filename)
{
	int		fd;
	char	*line;
	int		line_length;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error("map not found", var);
	line = get_next_line(fd);
	while (line != NULL)
	{
		var->map.data[var->map.size.h] = line;
		line_length = ft_strlen1(line);
		if (line[line_length - 1] == '\n')
		{
			line[line_length - 1] = '\0';
			line_length--;
		}
		if (var->map.size.h == 0)
			var->map.size.w = line_length;
		var->map.size.h++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
}

void	get_map(t_var *var, char **argv)
{
	int	num_lines;

	var->map.data = NULL;
	var->map.size.h = 0;
	var->map.size.w = 0;
	num_lines = count_lines(argv[1], var);
	var->map.data = (char **)malloc(num_lines * sizeof(char *));
	if (!var->map.data)
		error("memory allocation failed", var);
	read_map_data(var, argv[1]);
}

void	load_map(t_var var, int row, int col)
{
	if (var.map.data[row][col] == '1')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/wall.xpm",
				&var.img.size.w, &var.img.size.h);
	else if (var.map.data[row][col] == '0')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/floor.xpm",
				&var.img.size.w, &var.img.size.h);
	else if (var.map.data[row][col] == 'E')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/exit.xpm",
				&var.img.size.w, &var.img.size.h);
	else if (var.map.data[row][col] == 'C')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, "./img/drgn_ball.xpm",
				&var.img.size.w, &var.img.size.h);
	else if (var.map.data[row][col] == 'P')
		var.img.img_ptr = mlx_xpm_file_to_image(var.mlx, var.img.spt_path,
				&var.img.size.w, &var.img.size.h);
	else if (var.map.data[row][col] == 'Y' && var.enemy_detected > 0)
		enemy_animation(&var);
	mlx_put_image_to_window(var.mlx, var.win, var.img.img_ptr, SPRITE_W * col,
		SPRITE_H * row);
	mlx_destroy_image(var.mlx, var.img.img_ptr);
}

void	print_map(t_var var)
{
	int		row;
	int		col;

	row = 0;
	while (row < var.map.size.h)
	{
		col = 0;
		while (col < var.map.size.w)
		{
			load_map(var, row, col);
			col++;
		}
		row++;
	}
}
