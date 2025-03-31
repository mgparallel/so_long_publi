/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_play.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:09 by menwu             #+#    #+#             */
/*   Updated: 2025/03/31 18:02:37 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_play(t_data *d)
{
	int	p;

	p = 50;
	d->bush = mlx_xpm_file_to_image(d->mlx_ptr, BUSH, &p, &p);
	d->background = mlx_xpm_file_to_image(d->mlx_ptr, TILE, &p, &p);
	d->p_init = mlx_xpm_file_to_image(d->mlx_ptr, INIT, &p, &p);
	d->p_fr = mlx_xpm_file_to_image(d->mlx_ptr, FR, &p, &p);
	d->p_fr_mv = mlx_xpm_file_to_image(d->mlx_ptr, FR1, &p, &p);
	d->p_bk = mlx_xpm_file_to_image(d->mlx_ptr, BK, &p, &p);
	d->p_bk_mv = mlx_xpm_file_to_image(d->mlx_ptr, BK1, &p, &p);
	d->p_l = mlx_xpm_file_to_image(d->mlx_ptr, L, &p, &p);
	d->p_l_mv = mlx_xpm_file_to_image(d->mlx_ptr, L1, &p, &p);
	d->p_r = mlx_xpm_file_to_image(d->mlx_ptr, R, &p, &p);
	d->p_r_mv = mlx_xpm_file_to_image(d->mlx_ptr, R1, &p, &p);
	d->out = mlx_xpm_file_to_image(d->mlx_ptr, OUT, &p, &p);
	d->end_win = mlx_xpm_file_to_image(d->mlx_ptr, WIN, &p, &p);
	if (!d->bush || !d->background || !d->out || !d->end_win \
		|| !d->p_fr || !d->p_fr_mv || !d->p_bk || !d->p_bk_mv \
		|| !d->p_l || !d->p_l_mv || !d->p_r || !d->p_r_mv)
	{
		perror("Error loading image here!\n\n");
		end_game(d);
	}
	d->p = NULL;
}

void	axis_x_y(t_data *d, int index)
{
	int	axis_x;
	int	axis_y;

	axis_x = (index % d->width) * 50;
	axis_y = (index / d->width) * 50;
	d->axis_x = axis_x;
	d->axis_y = axis_y;
}

void	show_map_util(t_data *d, int i, int x_, int y_)
{
	if (d->long_line[i] == '1')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->bush, x_, y_);
	else if (d->long_line[i] == '0')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->background, x_, y_);
	else if (d->long_line[i] == 'E')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->out, x_, y_);
	else if (d->long_line[i] == 'C')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, \
				d->light_frame[d->current_frame_fly], x_, y_);
}

void	show_counter(t_data *d)
{
	if (d->start == 1)
	{
		mlx_string_put(d->mlx_ptr, d->win_ptr, 60, \
			(d->height * 50) - 30, 0xFFFFFF, "MOVES");
		mlx_string_put(d->mlx_ptr, d->win_ptr, 70, \
			(d->height * 50) - 15, 0xFFFFFF, "0");
	}
	else if (!d->start)
		update_counter(d);
}

void	show_map(t_data *d, char *long_line)
{
	int	i;

	i = 0;
	while (long_line[i] && long_line[i] != '\n')
	{
		axis_x_y(d, i);
		if (long_line[i] == 'P')
		{
			if (d->start == 1)
				mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, \
						d->p_init, d->axis_x, d->axis_y);
			else
				mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, \
						d->p, d->axis_x, d->axis_y);
			d->npc_x = d->axis_x;
			d->npc_y = d->axis_y;
		}
		else
			show_map_util(d, i, d->axis_x, d->axis_y);
		i++;
	}
	show_counter(d);
}
