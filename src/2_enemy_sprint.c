/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_enemy_sprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:12 by menwu             #+#    #+#             */
/*   Updated: 2025/03/31 18:03:38 by menwu            ###   ########.fr       */
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
