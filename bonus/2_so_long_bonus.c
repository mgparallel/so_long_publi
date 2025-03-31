/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:21 by menwu             #+#    #+#             */
/*   Updated: 2025/02/13 17:54:22 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	initial(t_data *d, char *map)
{
	if (!init_parsing(d, map))
	{
		if (d->mlx_ptr)
			mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
		error_free(d);
		return (0);
	}
	init_play(d);
	init_collective(d);
	init_enemy(d);
	return (1);
}

int	main(int ac, char **ag)
{
	t_data	*d;

	if (ac == 2)
	{
		d = malloc(sizeof(t_data));
		if (!d)
			return (1);
		init_data(d);
		d->mlx_ptr = mlx_init();
		if (!initial(d, ag[1]))
			return (1);
		d->win_ptr = mlx_new_window(d->mlx_ptr, d->width * 50, \
						d->height * 50, "so_long");
		if (!d->win_ptr)
			return (free_img(d), 1);
		show_map(d, d->long_line);
		mlx_loop_hook(d->mlx_ptr, &event_loop, d);
		mlx_hook(d->win_ptr, KeyPress, KeyPressMask, &key_press, d);
		mlx_hook(d->win_ptr, 17, 1L << 17, &end_game, d);
		mlx_loop(d->mlx_ptr);
		return (0);
	}
}
