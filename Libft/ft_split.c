/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:51:51 by idomary           #+#    #+#             */
/*   Updated: 2026/10/29 14:24:11 by idomary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			words++;
		}
	}
	return (words);
}

static char	**free_all(char **s, size_t i)
{
	while (i > 0)
	{
		free(s[i - 1]);
		i--;
	}
	free(s);
	return (NULL);
}

static char	*get_word(char const *s, size_t *i, char c)
{
	char	*ptr;
	size_t	j;
	size_t	a;

	while (s[(*i)] && s[(*i)] == c)
		(*i)++;
	a = (*i);
	while (s[(*i)] && s[(*i)] != c)
		(*i)++;
	ptr = malloc((*i) - a + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	while (a < (*i))
	{
		ptr[j] = s[a];
		j++;
		a++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word;
	char	**ptr;
	size_t	counter;

	if (!s)
		return (NULL);
	word = 0;
	counter = count_words(s, c);
	ptr = malloc((counter + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (counter > 0)
	{
		ptr[word] = get_word(s, &i, c);
		if (!ptr[word])
			return (free_all(ptr, word));
		word++;
		counter--;
	}
	ptr[word] = NULL;
	return (ptr);
}
