/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarachi <afarachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 06:00:06 by afarachi          #+#    #+#             */
/*   Updated: 2024/07/31 06:03:04 by afarachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_var *var)
{
	var->mlx = NULL;
	var->win = NULL;
	var->game.count_collec = 0;
	var->game.count_steps = 0;
	var->map.data = NULL;
	var->map.size.height = 0;
	var->map.size.width = 0;
	var->img.img_ptr = NULL;
	var->img.spt_path = "./img/sprite.xpm";
	var->img.size.width = 0;
	var->img.size.height = 0;
	var->img.pos.width = 0;
	var->img.pos.height = 0;
}

void	check_args(int argc, char **argv, t_var var)
{
	if (argc < 2)
		error("Provide map name and extension as argument\n\
Ex: ./so_long maps/map.ber", &var);
	if (argc > 2)
		error("Too many arguments. Provide only map name and extension\n\
Ex: ./so_long maps/map.ber", &var);
	if (ft_strstr(argv[1], ".ber") == NULL)
		error("Invalid map extension. Use .ber", &var);
}

int	ft_expose(t_var *var)
{
	print_map(*var);
	print_steps(var);
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;

	check_args(argc, argv, var);
	init_game(&var);
	get_map(&var, argv);
	check_map(var);
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		error("Failed to initialize MiniLibX", &var);
	var.win = mlx_new_window(var.mlx, var.map.size.width
			* SPRITE_W, var.map.size.height * SPRITE_H, "So long");
	if (var.win == NULL)
	{
		free_map(&var);
		error("Failed to create window", &var);
	}
	get_init_position(&var);
	count_collec(&var);
	print_map(var);
	mlx_hook(var.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &var);
	mlx_hook(var.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &var);
	mlx_expose_hook(var.win, ft_expose, &var);
	mlx_loop(var.mlx);
	free_map(&var);
	return (0);
}
