/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:30:07 by dcologgi          #+#    #+#             */
/*   Updated: 2023/01/19 11:59:01 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;
	size_t	i;

	if (!s)
		return (NULL);
	sublen = len - start;
	sub = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!sub)
		return (NULL);
	i = start;
	while (i < len && *(s + i) != '\0')
	{
		sub[i] = *(s + i);
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
