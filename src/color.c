/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:39:56 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/04 11:39:58 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define AQUAMARINE "\033[0;36m"
#define GRAY "\033[0;37m"

#define BOLD_BLACK "\033[1;30m"
#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_PURPLE "\033[1;35m"
#define BOLD_AQUAMARINE "\033[1;36m"
#define BOLD_GRAY "\033[1;37m"

#define INVERSE "\033[7m"
#define NORMAL "\033[0m"

static int	ft_putstr_int(char const *s)
{
	size_t	i;

	i = 0;
	if (s != NULL)
		while (s[i] != '\0')
			ft_putchar(s[i++]);
	return (i);
}

static int	color_bold(char *color)
{
	int		i;

	i = 0;
	if (!(ft_strcmp("bold_black", color)))
		i = ft_putstr_int(BOLD_BLACK);
	else if (!(ft_strcmp("bold_red", color)))
		i = ft_putstr_int(BOLD_RED);
	else if (!(ft_strcmp("bold_green", color)))
		i = ft_putstr_int(BOLD_GREEN);
	else if (!(ft_strcmp("bold_yellow", color)))
		i = ft_putstr_int(BOLD_YELLOW);
	else if (!(ft_strcmp("bold_blue", color)))
		i = ft_putstr_int(BOLD_BLUE);
	else if (!(ft_strcmp("bold_purple", color)))
		i = ft_putstr_int(BOLD_PURPLE);
	else if (!(ft_strcmp("bold_aquamarine", color)))
		i = ft_putstr_int(BOLD_AQUAMARINE);
	else if (!(ft_strcmp("bold_gray", color)))
		i = ft_putstr_int(BOLD_GRAY);
	else if (!(ft_strcmp("normal", color)))
		i = ft_putstr_int(NORMAL);
	return (i);
}

static int	color_sign(char *color)
{
	int		i;

	i = 0;
	if (!(ft_strcmp("black", color)))
		i = ft_putstr_int(BLACK);
	else if (!(ft_strcmp("red", color)))
		i = ft_putstr_int(RED);
	else if (!(ft_strcmp("green", color)))
		i = ft_putstr_int(GREEN);
	else if (!(ft_strcmp("yellow", color)))
		i = ft_putstr_int(YELLOW);
	else if (!(ft_strcmp("blue", color)))
		i = ft_putstr_int(BLUE);
	else if (!(ft_strcmp("purple", color)))
		i = ft_putstr_int(PURPLE);
	else if (!(ft_strcmp("aquamarine", color)))
		i = ft_putstr_int(AQUAMARINE);
	else if (!(ft_strcmp("gray", color)))
		i = ft_putstr_int(GRAY);
	else if (!(ft_strcmp("inverse", color)))
		i = ft_putstr_int(INVERSE);
	else
		i = color_bold(color);
	return (i);
}

int			color(const char *str)
{
	char	*color;
	char	*end;
	int		i;

	if (!(end = ft_strchr(str++, '}')))
		return (0);
	if (!(color = ft_strsub(str, 0, end - str)))
		return (0);
	i = color_sign(color);
	return (i) ? ft_strlen(color) + 2 : 0;
}

int			color_end(char *color)
{
	int		i;

	i = color_sign(color);
	return (i) ? ft_strlen(color) + 2 : 0;
}
