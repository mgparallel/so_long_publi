/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:06 by menwu             #+#    #+#             */
/*   Updated: 2025/02/13 18:04:21 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	define_e(t_data *d)
{
	int	i;

	i = 0;
	while (d->long_line[i] != 'E')
		i++;
	d->old_e = i;
	d->long_line[d->old_e] = '0';
}

void	init_collective(t_data *d)
{
	int		i;
	int		p;
	char	*light_files[MAX_KEY];

	p = 50;
	i = 0;
	light_files[0] = "img/fly0.xpm";
	light_files[1] = "img/fly1.xpm";
	light_files[2] = "img/fly2.xpm";
	light_files[3] = "img/fly3.xpm";
	light_files[4] = "img/fly4.xpm";
	while (i < MAX_KEY)
	{
		d->light_frame[i] = mlx_xpm_file_to_image(d->mlx_ptr, \
							light_files[i], &p, &p);
		if (!d->light_frame[i])
			frame_free(d, (void **)&light_files, i);
		i++;
	}
	d->current_frame_fly = 0;
	d->light = NULL;
	define_e(d);
}

void	enemy_count(t_data *d)
{
	int	i;

	i = 0;
	while (d->long_line[i] && d->long_line[i] != '\n')
	{
		if (d->long_line[i] == 'X')
			d->x_count++;
		i++;
	}
	d->x = ft_calloc(d->x_count, sizeof(t_enemy));
	if (!d->x)
		free_img(d);
}

void	enemy_array(t_data *d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	enemy_count(d);
	while (d->long_line[i] && d->long_line[i] != '\n')
	{
		if (d->long_line[i] == 'X')
		{
			d->x[count].pos = i;
			d->x[count].flag = 0;
			count++;
		}
		i++;
	}
}

void	init_enemy(t_data *d)
{
	int		i;
	int		p;
	char	*frame_files[MAX_KEY];

	p = 50;
	i = 0;
	frame_files[0] = "img/enemy0.xpm";
	frame_files[1] = "img/enemy1.xpm";
	frame_files[2] = "img/enemy2.xpm";
	frame_files[3] = "img/enemy3.xpm";
	frame_files[4] = "img/enemy4.xpm";
	while (i < MAX_KEY)
	{
		d->enemy_frame[i] = mlx_xpm_file_to_image(d->mlx_ptr, \
						frame_files[i], &p, &p);
		if (!d->enemy_frame[i])
			frame_free(d, (void **)&frame_files, i);
		i++;
	}
	d->current_frame_enemy = 0;
	d->enemy = NULL;
	enemy_array(d);
}
