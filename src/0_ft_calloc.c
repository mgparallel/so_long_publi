/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ft_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:53:30 by menwu             #+#    #+#             */
/*   Updated: 2025/02/13 17:53:32 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = s;
	while (n > 0)
	{
		*temp = '\0';
		temp++;
		n--;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*temp;
	size_t	total_size;

	total_size = nitems * size;
	if (total_size == 0)
		total_size = 1;
	temp = malloc(total_size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, total_size);
	return (temp);
}
