/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:02:54 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:02:57 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_p(t_specs *specs, va_list *ap)
{
	char				*val;
	unsigned long long	nbr;
	int					len;

	nbr = (unsigned long long)va_arg(*ap, void *);
	if (nbr == 0 && !specs->precision)
		val = ft_strnew(1);
	else
	{
		val = ft_uitoa_base(nbr, 16);
		len = ft_strlen(val);
		if (specs->precision || specs->flags[minus])
			specs->flags[zero] = 0;
		if (specs->precision - len > 0)
			val = filling_zero(val, specs->precision - len);
		len = ft_strlen(val);
		if (specs->flags[zero] && (specs->width - len - 2) > 0)
			val = filling_zero(val, specs->width - len + 2);
	}
	val = ft_strjoin_free("0x", val, 2);
	len = ft_strlen(val);
	print_value(specs, val, len);
}
