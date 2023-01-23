/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 10:46:56 by dcologgi          #+#    #+#             */
/*   Updated: 2023/01/23 16:24:26 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	dlen;
	size_t	slen;

	if (size == 0 && (!dest || !src))
		return (0);
	s = 0;
	d = ft_strlen(dest);
	dlen = d;
	slen = ft_strlen(src);
	if (size <= dlen)
		return (slen + size);
	while (src[s] != '\0' && d + 1 < size)
	{
		dest[d] = src[s];
		s++;
		d++;
	}
	dest[d] = '\0';
	return (dlen + slen);
}
