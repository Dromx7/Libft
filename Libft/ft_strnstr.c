/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 10:27:10 by idomary           #+#    #+#             */
/*   Updated: 2026/10/28 15:58:21 by idomary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] && i + ft_strlen(little) <= len)
	{
		if (ft_strncmp(&big[i], little, len - i) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
