/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:05:50 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:05:53 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	decs;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ft_putchar_fd('2', fd);
			n = -147483648;
		}
		n *= -1;
	}
	decs = 1;
	while (decs <= n / 10)
		decs *= 10;
	while (decs > 0)
	{
		ft_putchar_fd(n / decs + '0', fd);
		n %= decs;
		decs /= 10;
	}
}
