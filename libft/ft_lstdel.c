/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgenesis <pgenesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:14:39 by pgenesis          #+#    #+#             */
/*   Updated: 2020/07/26 12:07:49 by pgenesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if ((!alst) || (!del) || (!*alst))
		return ;
	(*del)((*alst)->content, (*alst)->content_size);
	tmp = (*alst)->next;
	if (tmp != NULL)
		ft_lstdelone(&tmp, del);
	free(*alst);
	*alst = NULL;
}
