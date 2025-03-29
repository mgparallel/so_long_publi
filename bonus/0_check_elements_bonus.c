/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_check_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:02:49 by menwu             #+#    #+#             */
/*   Updated: 2025/02/15 15:03:37 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_first_last(t_data *d)
{
	int	i;
	int	len;
	int	last_init;

	i = 0;
	len = count_width(d->long_line);
	last_init = len - d->width;
	while (i < d->width)
	{
		if ((d->long_line)[i] != '1')
			return (map_error(6), 0);
		i++;
	}
	while (len > last_init)
	{
		if ((d->long_line)[len - 1] != '1')
			return (map_error(6), 0);
		len--;
	}
	return (1);
}

int	check_cep(t_data *d)
{
	if (d->npc != 1)
		return (map_error(3), 0);
	if (d->exit != 1)
		return (map_error(4), 0);
	if (d->all_to_collect < 1)
		return (map_error(7), 0);
	return (1);
}

int	check_accessibility(t_data *d, int len)
{
	t_point		*size;
	t_point		*start;
	char		*full_map;

	size = ft_calloc(4, sizeof(int));
	start = ft_calloc(4, sizeof(int));
	if (!size || !start)
		return (0);
	size->x = d->width;
	size->y = d->height;
	len = 0;
	full_map = ft_strdup(d->long_line);
	if (!full_map)
		return (1);
	while (d->long_line[len] != 'P')
		len++;
	start->x = len % d->width;
	start->y = len / d->width;
	flood_fill(full_map, size, start);
	free(full_map);
	if (size->count_c != d->all_to_collect || size->count_e != 1)
		return (map_error(8), free(size), free(start), 0);
	return (free(size), free(start), 1);
}
