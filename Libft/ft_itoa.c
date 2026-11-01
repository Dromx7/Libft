/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 19:39:00 by idomary           #+#    #+#             */
/*   Updated: 2026/10/28 22:15:11 by idomary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	len(long i)
{
	long	x;
	int		j;

	x = 1;
	j = 1;
	if (i < 0)
	{
		j++;
		i *= -1;
	}
	while (x * 10 <= i)
	{
		x *= 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	long	i;
	int		j;
	char	*ptr;

	i = n;
	j = len(i);
	ptr = malloc(j + 1);
	if (!ptr)
		return (NULL);
	ptr[j] = 0;
	if (i < 0)
	{
		i *= -1;
		ptr[0] = '-';
	}
	if (i == 0)
		ptr[0] = '0';
	while (i > 0)
	{
		ptr[j - 1] = (i % 10) + '0';
		j--;
		i /= 10;
	}
	return (ptr);
}
