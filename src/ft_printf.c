/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:06:14 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/02 17:14:12 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			constructor(t_flags *fl)
{
	fl->width = 0;
	fl->precision = -1;
	fl->step = 0;
	fl->h_mod = 0;
	fl->l_mod = 0;
	fl->ld_mod = 0;
	fl->plus = 0;
	fl->minus = 0;
	fl->zero = 0;
	fl->space = 0;
	fl->hash = 0;
	fl->filler = ' ';
}

static void			for_norm1(int *total, t_flags *fl, va_list *ap)
{
	char *str;

	str = output_parameter(fl, ap);
	if (str != NULL)
	{
		if (fl->type != 'N')
		{
			ft_putstr(str);
			*total += ft_strlen(str);
		}
		else
			*total += putstr_for_null_char(str);
		ft_strdel(&str);
	}
}

static const char	*for_norm3(const char *format, int *fl_color)
{
	if (*format == '{')
	{
		*fl_color = color(format);
		format += *fl_color;
	}
	return (format);
}

static int			for_norm2(const char *format, va_list *ap, t_flags *fl,\
int *fl_color)
{
	int total;

	total = 0;
	while (*format)
	{
		format = for_norm3(format, fl_color);
		if (*format != '%')
		{
			ft_putchar(*format++);
			total++;
			continue;
		}
		constructor(fl);
		format++;
		if (analysis(format, fl))
		{
			format += fl->step;
			continue;
		}
		for_norm1(&total, fl, ap);
		format += fl->step + 1;
	}
	if (*fl_color)
		color_end("normal");
	return (total);
}

int					ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags	*fl;
	int		total;
	int		fl_color;

	fl_color = 0;
	total = 0;
	if (!(fl = (t_flags *)malloc(sizeof(t_flags))))
		return (total);
	va_start(ap, format);
	total = for_norm2(format, &ap, fl, &fl_color);
	va_end(ap);
	free(fl);
	return (total);
}
