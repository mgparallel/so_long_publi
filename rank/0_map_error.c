/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_map_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:53:47 by menwu             #+#    #+#             */
/*   Updated: 2025/03/29 16:52:01 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_rank.h"

void	frame_free(t_data *d, void **array, int i)
{
	perror("Error loading image!");
	while (i--)
		mlx_destroy_image(d->mlx_ptr, array[i]);
	free_img(d);
	exit(1);
}

void	error_free(t_data *d)
{
	if (!d)
		return ;
	if (d->long_line)
	{
		free(d->long_line);
		d->long_line = NULL;
	}
	free(d);
	exit(0);
}

void	free_img(t_data *d)
{
	if (!d)
		return ;
	if (d->long_line)
	{
		free(d->long_line);
		d->long_line = NULL;
	}
	if (d->mlx_ptr)
	{
		if (d->win_ptr)
			mlx_destroy_window(d->mlx_ptr, d->win_ptr);
		mlx_destroy_display(d->mlx_ptr);
		free(d->mlx_ptr);
	}
	free(d);
	exit(0);
}