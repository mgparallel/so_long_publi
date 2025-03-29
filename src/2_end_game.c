/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_end_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:48:28 by menwu             #+#    #+#             */
/*   Updated: 2025/02/15 15:48:43 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	cleanup(void *mlx_ptr, void **img)
{
	if (!mlx_ptr || !img || !*img)
		return ;
	mlx_destroy_image(mlx_ptr, *img);
	*img = NULL;
}

void	clean_npc(t_data *d)
{
	cleanup(d->mlx_ptr, (void **)&d->p_bk);
	cleanup(d->mlx_ptr, (void **)&d->p_bk_mv);
	cleanup(d->mlx_ptr, (void **)&d->p_fr);
	cleanup(d->mlx_ptr, (void **)&d->p_fr_mv);
	cleanup(d->mlx_ptr, (void **)&d->p_r);
	cleanup(d->mlx_ptr, (void **)&d->p_r_mv);
	cleanup(d->mlx_ptr, (void **)&d->p_l);
	cleanup(d->mlx_ptr, (void **)&d->p_l_mv);
}

int	end_game(t_data *d)
{
	int	i;

	i = 0;
	if (d->mlx_ptr)
	{
		cleanup(d->mlx_ptr, (void **)&d->bush);
		cleanup(d->mlx_ptr, (void **)&d->background);
		cleanup(d->mlx_ptr, (void **)&d->out);
		cleanup(d->mlx_ptr, (void **)&d->end_fail);
		cleanup(d->mlx_ptr, (void **)&d->p_init);
		clean_npc(d);
		while (i < MAX_KEY)
		{
			cleanup(d->mlx_ptr, (void **)&d->enemy_frame[i]);
			cleanup(d->mlx_ptr, (void **)&d->light_frame[i]);
			i++;
		}
		d->enemy = NULL;
		d->light = NULL;
		free(d->x);
	}
	free_img(d);
	return (0);
}
