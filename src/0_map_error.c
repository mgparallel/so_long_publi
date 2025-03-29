/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_map_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:53:47 by menwu             #+#    #+#             */
/*   Updated: 2025/02/15 15:19:22 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	map_error(int n)
{
	write(2, "Error\n", 6);
	if (n == 1)
		write(2, "The map is not rectangle.\n", 26);
	if (n == 2)
		write (2, "Found invalid items.\n", 21);
	if (n == 3)
		write (2, "Invalid number of player.\n", 26);
	if (n == 4)
		write (2, "Incorrect number/access of exit.\n", 33);
	if (n == 5)
		write (2, "Invalid map file format.\n", 25);
	if (n == 6)
		write (2, "Map is not correctly closed.\n", 29);
	if (n == 7)
		write (2, "Error with collectable items.\n", 30);
	if (n == 8)
		write (2, "Error with accessing items/exit.\n", 33);
}
