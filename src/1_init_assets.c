/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_init_assets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:06 by menwu             #+#    #+#             */
/*   Updated: 2025/03/31 18:02:28 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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