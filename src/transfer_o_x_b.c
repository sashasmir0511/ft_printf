/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_o_x_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:33:42 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/03 15:33:44 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*transfer(t_flags *fl, va_list *ap, int base)
{
	char	*s;

	s = NULL;
	if (fl->h_mod == 1)
		s = ft_itoa_base((unsigned short)va_arg(*ap, int), base);
	else if (fl->h_mod == 2)
		s = ft_itoa_base((unsigned char)va_arg(*ap, int), base);
	else if (fl->l_mod == 1)
		s = ft_itoa_base_unsigned(va_arg(*ap, unsigned long), base);
	else if (fl->l_mod == 2)
		s = ft_itoa_base_unsigned(va_arg(*ap, unsigned long long), base);
	else
		s = ft_itoa_base(va_arg(*ap, unsigned int), base);
	return (s);
}

static void	convert(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ft_toupper(str[i]);
		i++;
	}
}

char		*transfer_o_x_b(t_flags *fl, va_list *ap)
{
	char	*s;

	s = NULL;
	if (fl->type == 'o')
		s = transfer(fl, ap, 8);
	else if (fl->type == 'b')
		s = transfer(fl, ap, 2);
	else if (fl->type == 'x')
		s = transfer(fl, ap, 16);
	else if (fl->type == 'X')
	{
		fl->type = 'x';
		s = transfer(fl, ap, 16);
		s = digit_redactor(s, fl);
		convert(s);
		return (s);
	}
	s = digit_redactor(s, fl);
	return (s);
}
