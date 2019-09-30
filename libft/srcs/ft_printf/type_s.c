/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrolfe <mrolfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:03:10 by mrolfe            #+#    #+#             */
/*   Updated: 2019/09/02 13:03:12 by mrolfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_s(t_specs *specs, va_list *ap)
{
	char	*val;
	char	*tmp_str;
	int		len;

	if (specs->size == l)
	{
		val = ft_strdup(va_arg(*ap, char *));
	}
	else
		val = ft_strdup(va_arg(*ap, char *));
	if (val == NULL)
		val = ft_strdup("(null)");
	if (specs->precision >= 0)
	{
		tmp_str = ft_strnew(specs->precision);
		val = ft_strncat(tmp_str, val, specs->precision);
	}
	len = ft_strlen(val);
	if (specs->flags[zero] && !specs->flags[minus])
		val = filling_zero(val, specs->width - len);
	else if (specs->flags[zero] && specs->flags[minus])
		specs->flags[zero] = 0;
	len = ft_strlen(val);
	print_value(specs, val, len);
}
