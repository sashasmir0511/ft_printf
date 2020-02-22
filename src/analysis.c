/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:37:31 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/02 17:10:43 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(const char *ch)
{
	if (*ch == ' ' || *ch == '#' || *ch == '+'\
	|| *ch == '-' || *ch == '0')
		return (1);
	return (0);
}

static int	is_type_flag(const char *ch)
{
	if (*ch == 'd' || *ch == 'i' || *ch == 'u' || *ch == 'o' || *ch == 'x'\
	|| *ch == 'X' || *ch == 'f' || *ch == 'c' || *ch == 'b' || *ch == 'k'\
	|| *ch == 's' || *ch == '%' || *ch == 'p' || *ch == 'S' || *ch == 'C')
		return (1);
	return (0);
}

static void	analysis_flag(const char *s, t_flags *fl)
{
	while (is_flag(&s[fl->step]))
	{
		if (s[fl->step] == '-')
			fl->minus = 1;
		if (s[fl->step] == '+')
			fl->plus = 1;
		if (s[fl->step] == '0')
			fl->zero = 1;
		if (s[fl->step] == ' ')
			fl->space = 1;
		if (s[fl->step] == '#')
			fl->hash = 1;
		fl->step++;
	}
	if (fl->minus)
		fl->zero = 0;
	if (fl->plus)
		fl->space = 0;
	fl->filler = (fl->zero) ? '0' : ' ';
}

static int	analysis_modifier_flag(const char *s, t_flags *fl)
{
	while (s[fl->step] == 'h')
	{
		fl->h_mod++;
		fl->step++;
		if (fl->h_mod >= 3)
			return (1);
	}
	while (s[fl->step] == 'l' && fl->h_mod == 0)
	{
		fl->l_mod++;
		fl->step++;
		if (fl->l_mod >= 3)
			return (1);
	}
	if (s[fl->step] == 'L' && fl->h_mod == 0 && fl->l_mod == 0)
	{
		fl->ld_mod++;
		fl->step++;
		if (fl->ld_mod >= 2)
			return (1);
	}
	return (0);
}

int			analysis(const char *s, t_flags *fl)
{
	analysis_flag(s, fl);
	if (s[fl->step] >= '1' && s[fl->step] <= '9')
	{
		fl->width = ft_atoi(&s[fl->step]);
		while (s[fl->step] >= '0' && s[fl->step] <= '9')
			fl->step++;
	}
	if (s[fl->step] == '.')
	{
		fl->step++;
		fl->precision = ft_atoi(&s[fl->step]);
		while (s[fl->step] >= '0' && s[fl->step] <= '9')
			fl->step++;
	}
	if (analysis_modifier_flag(s, fl))
		return (1);
	if (s[fl->step] == '$')
		return (1);
	if (!(is_type_flag(&s[fl->step])))
		return (1);
	fl->type = s[fl->step];
	fl->type = (fl->type == 'i') ? 'd' : fl->type;
	fl->type = (fl->type == 'C') ? 'c' : fl->type;
	return (0);
}
