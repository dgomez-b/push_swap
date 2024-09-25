/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:37:20 by dgomez-b          #+#    #+#             */
/*   Updated: 2023/06/29 15:19:40 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ********************************LIBRARIES********************************* */

#include "./libft.h"

/* ********************************FUNCTIONS********************************* */

char	*ft_strchr(const char *s, char c)
{
	size_t	i;

	if (!c)
		return ((char *)(s + ft_strlen(s)));
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (0);
}
