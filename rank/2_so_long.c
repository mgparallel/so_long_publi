/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:50:00 by menwu             #+#    #+#             */
/*   Updated: 2025/03/29 19:58:17 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_rank.h"

void	load_map(t_data *d)
{
	const char *map_files[] = {"maps/level_1.ber", "maps/level_2.ber", "maps/level_3.ber", "maps/level_4.ber" \
									"maps/level_5.ber", "maps/level_6.ber", "maps/level_7.ber"};
	int i;

	while (i < 7)
	{
		read_map(d, map_files[i]);
		init_data(d);
		show_map(d, d->long_line);
		mlx_loop_hook(d->mlx_ptr, &event_loop, d);
		mlx_hook(d->win_ptr, KeyPress, KeyPressMask, &key_press, d);
		mlx_hook(d->win_ptr, 17, 1L << 17, &end_game, d);
		mlx_loop(d->mlx_ptr);
		if (d->game_over == 2)
			write(1, "Next level--->", 14);
		else if (d->game_over == 1)
			write(2, "failed", 6);
		i++;
	}
	write(1, "Congrates, you win!", 19);
}

void	initial(t_data *d)
{
	init_play(d);
	init_collective(d);
	init_enemy(d);
}

int	main(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (1);
	//init_data(d);
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->width * 50, \
					d->height * 50, "so_long");
	if (!d->win_ptr)
		return (free_img(d), 1);
	initial(d);
	load_map(d);
	return (0);
}