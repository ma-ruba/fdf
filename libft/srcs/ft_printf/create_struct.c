/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:00:21 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:00:23 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_specs	*create_new_specs(void)
{
	t_specs	*specs;
	int		i;

	i = -1;
	if (!(specs = (t_specs *)malloc(sizeof(t_specs))))
		return (NULL);
	while (++i < 5)
		specs->flags[i] = 0;
	specs->type = 0;
	specs->width = 0;
	specs->precision = -1;
	specs->size = 0;
	return (specs);
}
