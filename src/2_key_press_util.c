/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_key_press_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:35:45 by menwu             #+#    #+#             */
/*   Updated: 2025/02/15 15:36:19 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_right(t_data *d)
{
	int	i;

	i = 0;
	while (d->long_line[i] != 'P')
		i++;
	if (d->long_line[i + 1] != '1' && !is_exit(d, d->long_line[i + 1]))
	{
		d->start = 0;
		if (d->long_line[i + 1] == 'C')
			d->collected += 1;
		d->long_line[i + 1] = 'P';
		d->long_line[i] = '0';
		move_msg(d);
		move_util(d, d->p_r, d->p_r_mv);
	}
}

void	move_left(t_data *d)
{
	int	i;

	i = 0;
	while (d->long_line[i] != 'P')
		i++;
	if (d->long_line[i - 1] != '1' && !is_exit(d, d->long_line[i - 1]))
	{
		d->start = 0;
		if (d->long_line[i - 1] == 'C')
			d->collected += 1;
		d->long_line[i - 1] = 'P';
		d->long_line[i] = '0';
		move_msg(d);
		move_util(d, d->p_l, d->p_l_mv);
	}
}
