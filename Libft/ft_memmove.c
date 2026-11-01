/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 17:59:33 by idomary           #+#    #+#             */
/*   Updated: 2026/10/28 12:01:09 by idomary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	while (n > 0)
	{
		((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
		n--;
	}
	return (dest);
}
