/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:41 by marvin            #+#    #+#             */
/*   Updated: 2023/01/21 11:25:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **ptr, int n)
{
	while (n > 0)
	{
		n--;
		free(ptr[n]);
	}
	free(ptr);
	return (0);
}

static int	ft_wcount(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_putword(char *word, const char *s, int i, int wlen)
{
	int	j;

	j = 0;
	while (wlen > 0)
	{
		word[j] = s[i - wlen];
		j++;
		wlen--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(const char *s, char c, char **s2, int wnumber)
{
	int	i;
	int	word;
	int	wlen;

	i = 0;
	word = 0;
	wlen = 0;
	while (word < wnumber)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			wlen++;
			i++;
		}
		s2[word] = (char *)malloc(sizeof(char) * (wlen + 1));
		if (!s2)
			return (free_array(s2, word));
		ft_putword(s2[word], s, i, wlen);
		wlen = 0;
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(const char *s, char c)
{
	char			**s2;
	unsigned int	nwords;

	if (!s)
		return (0);
	nwords = ft_wcount(s, c);
	s2 = (char **)malloc(sizeof(char *) * (nwords + 1));
	if (!s2)
		return (0);
	s2 = ft_split_words(s, c, s2, nwords);
	return (s2);
}
