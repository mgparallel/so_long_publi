/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_update_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:54:24 by menwu             #+#    #+#             */
/*   Updated: 2025/02/13 17:54:25 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	update_counter(t_data *d)
{
	char	*num;

	num = ft_itoa(d->steps);
	if (!num)
		return (1);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 60, (d->height * 50) - 30, \
					0xFFFFFF, "MOVES");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 70, (d->height * 50) - 15, \
					0xFFFFFF, num);
	free(num);
	return (0);
}
