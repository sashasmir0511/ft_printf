/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaired <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:27:40 by lhaired           #+#    #+#             */
/*   Updated: 2020/02/03 14:27:42 by lhaired          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	indx 0 - nothing will be freed;
**	indx 1 - s1 will be freed;
**	indx 2 - s2 will be freed;
**	indx 3 - evrething will be freed;
** index needs for freeshing one of this elements
*/

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int indx)
{
	char	*new;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = ft_strnew(len)))
		return (NULL);
	ft_strcat(new, s1);
	ft_strcat(new, s2);
	if (indx == 1 || indx == 3)
		free(s1);
	if (indx == 2 || indx == 3)
		free(s2);
	return (new);
}
