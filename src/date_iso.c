/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:10:54 by fjessi            #+#    #+#             */
/*   Updated: 2020/02/03 17:10:55 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*data_iso(va_list *ap)
{
	int		data;
	char	*dd;
	char	*mm;
	char	*yy;

	data = va_arg(*ap, int);
	dd = ft_itoa(data % 100);
	data /= 100;
	mm = ft_itoa(data % 100);
	data /= 100;
	yy = ft_itoa(data);
	if (!(yy = ft_strjoin(yy, "-")))
		return (NULL);
	if (!(yy = ft_strjoin(yy, mm)))
		return (NULL);
	if (!(yy = ft_strjoin(yy, "-")))
		return (NULL);
	if (!(yy = ft_strjoin(yy, dd)))
		return (NULL);
	return (yy);
}
