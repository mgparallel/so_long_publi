/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_map_parsing_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:53:52 by menwu             #+#    #+#             */
/*   Updated: 2025/02/13 17:53:53 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	count_width(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

char	*map_concate(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < count_width(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (j < count_width(s2))
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\n';
	result[i + j + 1] = '\0';
	return (result);
}

void	fill(char *map, t_point **size, int x, int y)
{
	int	index;

	index = y * (*size)->x + x;
	if (x > (*size)->x || x < 0 || y > (*size)->y || y < 0)
		return ;
	if (map[index] == '1' || map[index] == 'X' || map[index] == 'A')
		return ;
	if (map[index] == 'C')
		(*size)->count_c++;
	else if (map[index] == 'E')
		(*size)->count_e++;
	map[index] = 'A';
	fill(map, size, x - 1, y);
	fill(map, size, x + 1, y);
	fill(map, size, x, y - 1);
	fill(map, size, x, y + 1);
}

void	flood_fill(char *map, t_point *size, t_point *start)
{
	fill(map, &size, start->x, start->y);
}
