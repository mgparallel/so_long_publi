/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_ft_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:53:42 by menwu             #+#    #+#             */
/*   Updated: 2025/02/13 17:53:44 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	count_size(long n)
{
	int	size;

	size = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*recursion(long n, char *result, int i)
{
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	if (n == 0)
		result[i - 1] = '0';
	else
	{
		result[i - 1] = n % 10 + '0';
		i--;
		if (n / 10 != 0)
		{
			n = n / 10;
			recursion(n, result, i);
		}
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	long	new;

	new = (long)n;
	size = count_size(new);
	if (new < 0)
		size += 1;
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	recursion(new, result, size);
	result[size] = '\0';
	return (result);
}
