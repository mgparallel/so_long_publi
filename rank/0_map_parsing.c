/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_map_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:50:20 by menwu             #+#    #+#             */
/*   Updated: 2025/03/29 19:56:54 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_rank.h"

void	init_data(t_data *d)
{
	ft_memset(d, 0, sizeof(t_data));
	d->mv_flag = 1;
	d->start = 1;
	d->frame_delay = 50;
	d->width = 18;
	d->height = 10;
	d->long_line = NULL;
	d->mlx_ptr = NULL;
	d->win_ptr = NULL;
}

int	read_map_util(t_data *d, char *line)
{
	char	*temp;

	temp = map_concate(d->long_line, line);
	if (!temp)
		return (free(d->long_line), free(line), 0);
	free(d->long_line);
	d->long_line = temp;
	return (1);
}

int	read_map(t_data *d, const char *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			if (!read_map_util(d, line))
				return (0);
			free(line);
		}
		else
			break ;
	}
	while (d->long_line[i] && d->long_line[i] != '\n')
	{
		if (d->long_line[i] == 'C')
			d->all_to_collect++;
		i++;
	}
	close(fd);
	return (1);
}
