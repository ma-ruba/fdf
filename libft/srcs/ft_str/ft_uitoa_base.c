/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:10:50 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:10:52 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_unsllonglen(unsigned long long num, int base)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (i = 1);
	while (num)
	{
		i++;
		num /= base;
	}
	return (i);
}

char			*ft_uitoa_base(unsigned long long num, int base)
{
	char	*str;
	size_t	digits;

	digits = ft_unsllonglen(num, base);
	str = ft_strnew(digits);
	while (digits-- > 0)
	{
		if (num % base < 10)
			str[digits] = num % base + '0';
		else
			str[digits] = num % base + 87;
		num /= base;
	}
	return (str);
}
