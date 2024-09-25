/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:37:20 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/06/29 15:19:52 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"

/* ********************************FUNCTIONS********************************* */

char	*ft_strrchr(const char *s, char c)
{
	size_t	i;

	i = ft_strlen(s);
	if (!c)
		return ((char *)(s + i));
	while (i > 0)
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i--;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}