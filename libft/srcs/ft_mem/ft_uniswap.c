/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uniswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:00:04 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:00:06 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_uniswap(void *a, void *b, size_t size)
{
	char	c[size];

	ft_memcpy(c, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, c, size);
}
