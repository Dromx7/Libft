/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:22:45 by idomary           #+#    #+#             */
/*   Updated: 2026/10/28 17:46:50 by idomary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	d;
	char	*ptr;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	d = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (d > 0 && ft_strrchr(set, s1[d - 1]))
		d--;
	if (i > d)
		d = i;
	ptr = malloc(d - i + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[i], d - i + 1);
	return (ptr);
}
