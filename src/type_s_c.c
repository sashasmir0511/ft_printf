/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:14:42 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/03 14:14:44 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			putstr_for_null_char(char *s)
{
	size_t i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
		{
			if (s[i] == '@')
			{
				s[i] = (0000);
			}
			ft_putchar(s[i]);
			i++;
		}
	return (i);
}

static char	*type_s(t_flags *fl, va_list *ap)
{
	char	*str;
	int		i;

	if (fl->l_mod != 1)
		str = (char *)va_arg(*ap, char *);
	else
		str = (char *)va_arg(*ap, wchar_t *);
	if (!str)
		str = "(null)";
	str = str_redactor(ft_strdup(str), fl);
	if (fl->type == 'S')
	{
		i = 0;
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
	return (str);
}

static char	*ft_stradd(char *str, char ch)
{
	int		len;
	char	*new;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		if (!(new = (char*)ft_strnew(len + 1)))
			return (NULL);
		ft_strcat(new, str);
		ft_strdel(&str);
	}
	else
		new = ft_strnew(1);
	new[len] = ch;
	new[len + 1] = '\0';
	return (new);
}

static char	*type_c(t_flags *fl, va_list *ap)
{
	char	v_arg;
	char	*str;

	v_arg = (char)va_arg(*ap, int);
	if (v_arg)
	{
		str = str_redactor(ft_stradd(NULL, v_arg), fl);
	}
	else
	{
		fl->type = 'N';
		str = str_redactor(ft_strdup("@"), fl);
	}
	return (str);
}

char		*type_s_c(t_flags *fl, va_list *ap)
{
	char	*str;

	str = NULL;
	if (fl->l_mod == 0 || fl->l_mod == 1)
	{
		if (fl->type == 's' || fl->type == 'S')
			str = type_s(fl, ap);
		if (fl->type == 'c')
			str = type_c(fl, ap);
	}
	else
		str = ft_strdup("(null)");
	return (str);
}
