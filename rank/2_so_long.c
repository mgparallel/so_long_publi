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

void	reset_win(t_data *d)
{
	d->game_over = 0;
	d->all_to_collect = 0;
	d->collected = 0;
	d->counter_enemy = 0;
	d->counter_fly = 0;
	d->counter_pattern = 0;
	d->enemy_flag = 0;
	d->mv_flag = 1;
	d->start = 1;
	d->gameover_drawn = 0;
	d->old_e = 0;
	d->exit_flag = 0;
	if (d->long_line)
	{
		free(d->long_line);
		d->long_line = NULL;
	}
	int i = 0;
	if (d->mlx_ptr)
	{
		while (i < MAX_KEY)
		{
			cleanup(d->mlx_ptr, (void **)&d->enemy_frame[i]);
			cleanup(d->mlx_ptr, (void **)&d->light_frame[i]);
			i++;
		}
		d->enemy = NULL;
		d->light = NULL;
		free(d->x);
	}
}

void	load_next_level(t_data *d)
{
	const char *map_files[] = {"maps/maps_ranking/level_1.ber", "maps/maps_ranking/level_2.ber", "maps/maps_ranking/level_3.ber", "maps/maps_ranking/level_4.ber", \
									"maps/maps_ranking/level_5.ber", "maps/maps_ranking/level_6.ber", "maps/maps_ranking/level_7.ber"};
	
	if (d->level_num < 6)
	{
		d->level_num++;
		reset_win(d);
		read_map(d, map_files[d->level_num]);
		init_collective(d);
		init_enemy(d);
		show_map(d, d->long_line);
	}
	else
	{
		d->game_over = 2;
		write(1, "Congrates, you win!\n", 20);
	}
}

void	init_map(t_data *d)
{		
		read_map(d,"maps/maps_ranking/level_1.ber");
		init_collective(d);
		init_enemy(d);
		show_map(d, d->long_line);
		mlx_loop_hook(d->mlx_ptr, &event_loop, d);
		mlx_hook(d->win_ptr, KeyPress, KeyPressMask, &key_press, d);
		mlx_hook(d->win_ptr, 17, 1L << 17, &end_game, d);
		mlx_loop(d->mlx_ptr);
	}

int	main(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (1);
	init_data(d);
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
	{
		write(1, "mlx initialization failed\n", 26);
		return (free(d), 1);
	}
	init_play(d);
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->width * 50, \
					d->height * 50, "so_long");
	if (!d->win_ptr)
		return (free_img(d), 1);
	init_map(d);
	return (0);
}