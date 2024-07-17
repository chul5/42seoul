/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coh <coh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:45:05 by coh               #+#    #+#             */
/*   Updated: 2022/07/18 15:34:51 by coh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*cur;

	head = 0;
	while (lst)
	{
		cur = ft_lstnew(f(lst->content));
		if (!cur)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, cur);
		lst = lst->next;
	}
	return (head);
}
