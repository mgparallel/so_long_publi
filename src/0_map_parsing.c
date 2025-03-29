/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_map_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:53:56 by menwu             #+#    #+#             */
/*   Updated: 2025/02/13 17:53:57 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_data(t_data *d)
{
	d = ft_memset(d, 0, sizeof(t_data));
	d->wall = 1;
	d->flag = 1;
	d->start = 1;
	d->frame_delay = 50;
	d->mlx_ptr = NULL;
	d->win_ptr = NULL;
	d->long_line = NULL;
	d->current_line = NULL;
	d->long_line = NULL;
}

int	parsing_line(t_data *d, char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (map_error(6), 0);
	while (line[i + 1] && line[i + 1] != '\n')
	{
		if (line[i] == '1')
			d->wall++;
		else if (line[i] == '0')
			d->back++;
		else if (line[i] == 'C')
			d->all_to_collect++;
		else if (line[i] == 'E')
			d->exit++;
		else if (line[i] == 'P')
			d->npc++;
		else if (line[i] != 'X')
			return (map_error(2), 0);
		i++;
	}
	if (line[i] != '1')
		return (map_error(6), 0);
	return (1);
}

int	read_map_util(t_data *d, char *line)
{
	char	*temp;

	d->height++;
	d->current_line = line;
	if (!parsing_line(d, line))
		return (free(line), 0);
	if (d->height == 1)
		d->width = count_width(d->current_line);
	else if (count_width(d->current_line) != d->width)
		return (map_error(1), free(line), 0);
	temp = map_concate(d->long_line, line);
	if (!temp)
		return (free(d->long_line), free(line), 0);
	free(d->long_line);
	d->long_line = temp;
	return (1);
}

int	read_map(t_data *d, char *map)
{
	int		fd;
	char	*line;

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
	if (!check_cep(d) || !check_first_last(d))
		return (0);
	close(fd);
	return (1);
}

int	init_parsing(t_data *d, char *map)
{
	size_t	len;
	int		count;

	len = ft_strlen(map);
	count = 0;
	if (map[len - 1] != 'r' || map[len - 2] != 'e' \
				|| map[len - 3] != 'b' || map[len - 4] != '.')
		return (map_error(5), 0);
	while (map[--len])
	{
		if (map[len] == '.')
			count++;
	}
	if (count != 1)
		return (map_error(5), 0);
	if (!read_map(d, map) || !check_accessibility(d, len))
		return (0);
	return (1);
}
