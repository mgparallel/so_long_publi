/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_game_over.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:02 by menwu             #+#    #+#             */
/*   Updated: 2025/03/31 18:05:04 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_game_win(t_data *d)
{
	int	i;

	if (d->gamewin_drawn == 3)
		return ;
	i = 0;
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	while (d->long_line[i] && d->long_line[i] != '\n')
	{
		axis_x_y(d, i);
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->background, \
					d->axis_x, d->axis_y);
		i++;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->end_win, \
			(d->width - 5) * 25, (d->height - 6) * 25);
	mlx_string_put(d->mlx_ptr, d->win_ptr, (d->width - 3) * 25, \
			(d->height + 3) * 25, 0x00FF0000, "Press ESC to exit the game");
	d->gamewin_drawn++;
	mlx_do_sync(d->mlx_ptr);
}

void	show_animation(t_data *d, char *long_line)
{
	int	i;

	i = 0;
	while (long_line[i] && long_line[i] != '\n')
	{
		axis_x_y(d, i);
		if (long_line[i] == '0')
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->background, \
					d->axis_x, d->axis_y);
		if (long_line[i] == 'C')
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, \
					d->light_frame[d->current_frame_fly], d->axis_x, d->axis_y);
		i++;
	}
}

int	event_loop(t_data *d)
{
	if (d->game_over == 1)
		display_game_win(d);
	else
	{
		light_sprint(d);
		show_animation(d, d->long_line);
	}
	return (0);
}
