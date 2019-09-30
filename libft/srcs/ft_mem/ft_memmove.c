/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:59:47 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 12:59:50 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			n;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = (unsigned char *)src;
	n = len;
	if (s < d)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
