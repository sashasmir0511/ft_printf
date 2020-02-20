/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:10:17 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/03 14:10:20 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlennbr(size_t nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (size + 1);
}

char			*ft_itoa_unsigned(size_t n)
{
	size_t	i;
	size_t	size;
	size_t	nbr;
	char	*str;

	nbr = n;
	size = ft_getlennbr(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = size - 1;
	while (nbr >= 10)
	{
		str[i--] = (char)(nbr % 10 + 48);
		nbr /= 10;
	}
	str[i] = (char)(nbr % 10 + 48);
	str[size] = '\0';
	return (str);
}
