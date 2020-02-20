/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_longlong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:30:28 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/03 14:30:30 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_longlong(long long nbr)
{
	if (nbr < 0)
		return (ft_strjoin_free("-", ft_itoa_unsigned(-nbr), 2));
	else
		return (ft_itoa_unsigned(nbr));
}
