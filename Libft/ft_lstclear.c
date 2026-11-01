/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idomary <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 19:22:51 by idomary           #+#    #+#             */
/*   Updated: 2026/10/29 12:34:59 by idomary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst || !del || !(*lst))
		return ;
	while ((*lst) != NULL)
	{
		ptr = (*lst);
		(*lst) = (*lst)->next;
		del(ptr->content);
		free(ptr);
	}
}
