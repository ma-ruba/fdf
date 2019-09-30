/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bconwy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:43:53 by bconwy            #+#    #+#             */
/*   Updated: 2018/11/27 17:43:57 by bconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					*ft_arrcpy(int *source, size_t n)
{
	size_t			i;
	int				*res;

	i = -1;
	res = (int*)malloc(sizeof(int) * n);
	while (++i < n)
		res[i] = source[i];
	return (res);
}
