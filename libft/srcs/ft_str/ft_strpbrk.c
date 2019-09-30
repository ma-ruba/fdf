/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:09:40 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:09:42 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *accept)
{
	size_t	lenaccept;
	size_t	i;

	lenaccept = ft_strlen((char*)accept);
	i = 0;
	if (s == NULL || accept == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (ft_memchr(accept, s[i], lenaccept) != NULL)
			return ((char*)s + i);
	}
	return (NULL);
}
