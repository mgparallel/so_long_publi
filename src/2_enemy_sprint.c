/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_enemy_sprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:12 by menwu             #+#    #+#             */
/*   Updated: 2025/02/17 15:02:15 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	light_sprint(t_data *d)
{
	d->counter_fly++;
	if (d->counter_fly >= d->frame_delay)
	{
		d->current_frame_fly = (d->current_frame_fly + 1) % MAX_KEY;
		d->light = d->light_frame[d->current_frame_fly];
		d->counter_fly = 0;
	}
	return (0);
}

void	check_no_p(t_data *d, int next_i)
{
	if (d->long_line[next_i] == 'P')
		d->game_over = 1;
}

void	enemy_pattern_util(t_data *d, int current_i, int i)
{
	check_no_p(d, current_i + d->width);
	if (current_i + d->width < d->width * d->height && \
				d->long_line[current_i + d->width] == '0')
	{
		d->long_line[current_i] = '0';
		d->long_line[current_i + d->width] = 'X';
		d->x[i].pos = current_i + d->width;
	}
	else
		d->x[i].flag = 0;
}

void	enemy_pattern(t_data *d)
{
	int	i;
	int	current_i;

	i = 0;
	current_i = 0;
	while (i < d->x_count)
	{
		current_i = d->x[i].pos;
		if (d->x[i].flag == 0)
		{
			check_no_p(d, current_i - d->width);
			if (current_i - d->width > 0 && \
					d->long_line[current_i - d->width] == '0')
			{
				d->long_line[current_i] = '0';
				d->long_line[current_i - d->width] = 'X';
				d->x[i].pos = current_i - d->width;
			}
			else
				d->x[i].flag = 1;
		}
		if (d->x[i].flag == 1)
			enemy_pattern_util(d, current_i, i);
		i++;
	}
}

int	enemy_sprint(t_data *d)
{
	d->counter_enemy++;
	d->counter_pattern++;
	if (d->counter_enemy >= d->frame_delay)
	{
		d->current_frame_enemy = (d->current_frame_enemy + 1) % MAX_KEY;
		d->enemy = d->enemy_frame[d->current_frame_enemy];
		d->counter_enemy = 0;
	}
	if (d->counter_pattern >= 50)
	{
		enemy_pattern(d);
		d->counter_pattern = 0;
	}
	return (0);
}
