/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_pricessing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:46:27 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/03 13:46:29 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_redactor_four(char *s, t_flags *fl)
{
	char	*str;
	char	*s_new;

	if (!(str = ft_strnew(fl->precision)))
		exit(1);
	s = ft_strncpy(str, s, fl->precision);
	if (!(s_new = ft_strnew(fl->width - fl->precision)))
		exit(1);
	ft_memset(s_new, fl->filler, fl->width - fl->precision);
	if (fl->minus == 0)
		s = ft_strjoin_free(s_new, s, 3);
	else
		s = ft_strjoin_free(s, s_new, 3);
	return (s);
}

static char	*str_redactor_three(char *s, t_flags *fl)
{
	char	*str;

	if (!(str = ft_strnew(fl->precision)))
		exit(1);
	if (fl->minus == 0)
		s = ft_strncpy(str, s, fl->precision);
	else
	{
		ft_memset(str, fl->filler, fl->precision);
		s = ft_strncpy(str, s, fl->precision);
	}
	return (s);
}

static char	*str_redactor_two(char *s, t_flags *fl)
{
	char	*str;
	char	*s_new;

	if (!(s_new = ft_strnew(fl->precision)))
		exit(1);
	s = ft_strncpy(s_new, s, fl->precision);
	if (!(str = ft_strnew(fl->width - fl->precision)))
		exit(1);
	ft_memset(str, fl->filler, fl->width - fl->precision);
	if (fl->minus == 0)
		s = ft_strjoin_free(str, s, 3);
	else if (fl->minus == 1)
		s = ft_strjoin_free(s, str, 3);
	return (s);
}

static char	*str_redactor_one(char *s, t_flags *fl, int len)
{
	char	*str;

	if (!(str = ft_strnew(fl->width - len)))
		exit(1);
	ft_memset(str, fl->filler, fl->width - len);
	if (fl->minus == 0)
		s = ft_strjoin_free(str, s, 3);
	else if (fl->minus == 1)
		s = ft_strjoin_free(s, str, 3);
	return (s);
}

char		*str_redactor(char *s, t_flags *fl)
{
	int		len;

	len = ft_strlen(s);
	if (len <= fl->width && fl->width != 0)
	{
		if (fl->precision > len || fl->precision == -1)
			s = str_redactor_one(s, fl, len);
		else if (fl->precision <= len || fl->precision == 0)
			s = str_redactor_two(s, fl);
	}
	else if (len > fl->width && fl->type != '%' && fl->type != 'N')
	{
		if (len > fl->precision && fl->precision >= fl->width)
			s = str_redactor_three(s, fl);
		else if (len >= fl->precision && fl->precision < fl->width \
				&& fl->precision != -1)
			s = str_redactor_four(s, fl);
	}
	else if (fl->width == 0)
		return (s);
	return (s);
}
