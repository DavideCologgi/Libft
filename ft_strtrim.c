/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:28:36 by dcologgi          #+#    #+#             */
/*   Updated: 2023/01/23 12:13:20 by dcologgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_is_present(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	size;
	char	*trim;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_set_is_present(((char)*s1), set) == 1)
			s1++;
		else
			break ;
	}
	size = ft_strlen(s1);
	while (size != 0)
	{
		if (ft_set_is_present(s1[size - 1], set) == 1)
			size--;
		else
			break ;
	}
	trim = (char *)malloc(sizeof(char) * size + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, (char *)s1, size + 1);
	return (trim);
}
