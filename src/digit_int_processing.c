/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_int_processing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:46:27 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/03 13:46:29 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*digit_int_processing(t_flags *fl, va_list *ap)
{
	char *s;

	s = NULL;
	if (fl->h_mod == 1)
		s = ft_itoa((short)va_arg(*ap, int));
	else if (fl->h_mod == 2)
		s = ft_itoa((signed char)va_arg(*ap, int));
	else if (fl->l_mod == 1)
		s = ft_itoa_long(va_arg(*ap, long));
	else if (fl->l_mod == 2)
		s = ft_itoa_longlong(va_arg(*ap, long long));
	else
		s = ft_itoa(va_arg(*ap, int));
	s = digit_redactor(s, fl);
	return (s);
}
