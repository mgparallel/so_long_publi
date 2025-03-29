/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: menwu <menwu@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:53:59 by menwu             #+#    #+#             */
/*   Updated: 2025/02/13 17:54:00 by menwu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_msg(t_data *d)
{
	char	*num;

	d->steps += 1;
	num = ft_itoa(d->steps);
	if (!num)
		return ;
	write (1, "You have moved ", 15);
	write (1, num, ft_strlen(num));
	free(num);
	write (1, " steps\n", 7);
}

int	is_exit(t_data *d, char ch)
{
	if (ch == 'C' && d->collected + 1 == d->all_to_collect)
		d->exit_flag = 1;
	if (ch == 'E' && d->collected == d->all_to_collect)
	{
		write (1, "Congrats! You won!\n", 19);
		d->game_over = 2;
		return (1);
	}
	else
		return (0);
}
