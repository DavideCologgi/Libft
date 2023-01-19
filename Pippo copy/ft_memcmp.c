/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:19:05 by dcologgi          #+#    #+#             */
/*   Updated: 2023/01/18 14:35:57 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 0;
	ptr1 = str1;
	ptr2 = str2;
	while (i < n && *ptr1 == *ptr2)
	{
		ptr1++;
		ptr2++;
		i++;
	}
	return ((int)(*ptr1 - *ptr2));
}
