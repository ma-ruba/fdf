/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_non.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:02:34 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:02:36 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_non_spec(char *start_ptr, t_specs *specs)
{
	char	*val;

	val = ft_strnew(1);
	val[0] = specs->type;
	print_value(specs, val, 1);
	start_ptr++;
	return (start_ptr);
}
