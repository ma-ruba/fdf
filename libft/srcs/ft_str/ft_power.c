/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:05:01 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:05:04 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power(double num, int power)
{
	int		count;
	double	number;

	number = 1;
	count = 1;
	if (power == 0)
		return (1);
	else
	{
		while (count++ <= ABS(power))
			if (power < 0)
				number = number / num;
			else if (power > 0)
				number *= num;
	}
	return (number);
}
