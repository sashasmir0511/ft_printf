/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_redactor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:19:46 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/04 14:19:48 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*precision_redactor(char *s, char *minus, t_flags *fl)
{
	int		len;
	char	*dot;
	char	*str;

	dot = ft_strchr(s, '.');
	if (fl->type != 'f' || !dot)
		len = (minus) ? ft_strlen(s) - 1 : ft_strlen(s);
	else
		len = ft_strlen(dot) - 1;
	if (fl->precision > len)
	{
		if (!(str = ft_strnew(fl->precision - len)))
			exit(1);
		ft_memset(str, '0', fl->precision - len);
		str = (fl->type != 'f') ? ft_strjoin_free(str, s, 3)\
		: ft_strjoin_free(s, str, 3);
		if (minus)
			ft_swap(ft_strchr(str, '-'), str);
		return (str);
	}
	return (s);
}

static char	*width_redactor_two(char *arg, t_flags *fl, int len)
{
	char	*str;

	if (!(arg = ft_strjoin(" ", arg)))
		exit(1);
	if (!(str = ft_strnew(fl->width - len - 1)))
		exit(1);
	ft_memset(str, fl->filler, fl->width - len - 1);
	arg = ft_strjoin_free(arg, str, 3);
	return (arg);
}

static char	*width_redactor_one(char *arg, t_flags *fl, int len, char *dash)
{
	char	*str;

	if (!(str = ft_strnew(fl->width - len)))
		exit(1);
	ft_memset(str, fl->filler, fl->width - len);
	if (fl->type == 'd' && fl->space && fl->filler == '0' && !dash)
		str[0] = ' ';
	arg = (fl->minus) ? ft_strjoin_free(arg, str, 3) :\
		ft_strjoin_free(str, arg, 3);
	return (arg);
}

static char	*width_redactor(char *arg, t_flags *fl, int len)
{
	char	*str;
	char	*dash;

	dash = ft_strchr(arg, '-');
	if (len < fl->width)
	{
		if (fl->space && fl->minus && !dash)
			arg = width_redactor_two(arg, fl, len);
		else
			arg = width_redactor_one(arg, fl, len, dash);
		dash = ft_strchr(arg, '-');
		if (dash && fl->filler == '0')
			ft_swap(arg, dash);
		if (fl->hash && fl->filler == '0' && (str = ft_strchr(arg, 'x')))
			ft_swap(str, arg + 1);
		if (!dash && fl->plus && fl->filler == '0' &&\
		(fl->type == 'd' || fl->type == 'f'))
			ft_swap(ft_strchr(arg, '0'), ft_strchr(arg, '+'));
	}
	else if (fl->space && (fl->type == 'd' || fl->type == 'f') && !dash)
		arg = ft_strjoin_free(" ", arg, 2);
	return (arg);
}

char		*digit_redactor(char *s, t_flags *fl)
{
	char	*minus;

	minus = ft_strchr(s, '-');
	s = precision_redactor(s, minus, fl);
	if (fl->hash || fl->type == 'p')
		s = hashtag_redactor(fl->type, s, fl->precision);
	if (!fl->precision && !ft_strcmp(s, "0") && \
	(fl->type == 'x' || fl->type == 'o' || fl->type == 'd' || fl->type == 'u') \
	&& !(fl->hash && fl->type == 'o'))
		s[0] = '\0';
	if (!minus && fl->plus && (fl->type == 'd' || fl->type == 'f'))
		s = ft_strjoin_free("+", s, 2);
	fl->filler = (fl->precision != -1 && fl->type != 'f') ? ' ' : fl->filler;
	s = width_redactor(s, fl, ft_strlen(s));
	return (s);
}
