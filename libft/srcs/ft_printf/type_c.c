/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:01:43 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:01:46 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_c(t_specs *specs, va_list *ap)
{
	char	*val;
	int		len;

	val = ft_strnew(1);
	specs->precision = PREC(specs->precision);
	if (specs->size == l)
	{
		val[0] = va_arg(*ap, int);
		val[0] = (wchar_t)val[0];
	}
	else
	{
		val[0] = va_arg(*ap, int);
		val[0] = (char)val[0];
	}
	if (specs->flags[zero] && !specs->flags[minus])
		val = filling_zero(val, specs->width - 1);
	else if (specs->flags[zero] && specs->flags[minus])
		specs->flags[zero] = 0;
	len = ft_strlen(val);
	if (len == 0)
		len++;
	print_value(specs, val, len);
}
