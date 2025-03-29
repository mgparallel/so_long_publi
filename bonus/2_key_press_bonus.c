/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_key_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:16 by menwu             #+#    #+#             */
/*   Updated: 2025/02/15 14:14:41 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_util(t_data *d, void *ini, void *mv)
{
	if (d->flag == 1)
	{
		d->p = ini;
		d->flag = 0;
	}
	else
	{
		d->p = mv;
		d->flag = 1;
	}
}

void	move_down(t_data *d)
{
	int	i;

	i = 0;
	while (d->long_line[i] != 'P')
		i++;
	if (d->long_line[i + d->width] == 'X')
	{
		d->game_over = 1;
		return ;
	}
	if (d->long_line[i + d->width] != '1' \
			&& !is_exit(d, d->long_line[i + d->width]))
	{
		d->start = 0;
		if (d->long_line[i + d->width] == 'C')
			d->collected += 1;
		d->long_line[i + d->width] = 'P';
		d->long_line[i] = '0';
		move_msg(d);
		move_util(d, d->p_fr, d->p_fr_mv);
	}
}

void	move_up(t_data *d)
{
	int	i;

	i = 0;
	while (d->long_line[i] != 'P')
		i++;
	if (d->long_line[i - d->width] == 'X')
	{
		d->game_over = 1;
		return ;
	}
	if (d->long_line[i - d->width] != '1' \
				&& !is_exit(d, d->long_line[i - d->width]))
	{
		d->start = 0;
		if (d->long_line[i - d->width] == 'C')
			d->collected += 1;
		d->long_line[i - d->width] = 'P';
		d->long_line[i] = '0';
		move_msg(d);
		move_util(d, d->p_bk, d->p_bk_mv);
	}
}

int	key_press(int keysym, t_data *d)
{
	if (keysym == XK_Escape)
		end_game(d);
	else if (keysym == 119 || keysym == 65362)
		move_up(d);
	else if (keysym == 97 || keysym == 65361)
		move_left(d);
	else if (keysym == 115 || keysym == 65364)
		move_down(d);
	else if (keysym == 100 || keysym == 65363)
		move_right(d);
	if (d->start != 0)
		d->p = d->p_r;
	if (d->exit_flag == 1)
		d->long_line[d->old_e] = 'E';
	if (d->game_over == 0)
		show_map(d, d->long_line);
	return (0);
}
