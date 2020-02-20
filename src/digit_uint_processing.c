/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_uint_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:20:51 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/03 15:20:53 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*digit_uint_processing(t_flags *fl, va_list *ap)
{
	char *s;

	s = NULL;
	if (fl->h_mod == 1)
		s = ft_itoa_unsigned((unsigned short)va_arg(*ap, unsigned int));
	else if (fl->h_mod == 2)
		s = ft_itoa_unsigned((unsigned char)va_arg(*ap, unsigned int));
	else if (fl->l_mod == 1)
		s = ft_itoa_unsigned(va_arg(*ap, unsigned long));
	else if (fl->l_mod == 2)
		s = ft_itoa_unsigned(va_arg(*ap, unsigned long long));
	else
		s = ft_itoa_unsigned(va_arg(*ap, unsigned int));
	s = digit_redactor(s, fl);
	return (s);
}
