/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 03:49:36 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/24 03:52:48 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void			push_back_list(t_list *push, t_list **list)
{
	t_list		*tmp;

	tmp = *list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = push;
	else
		*list = push;
	push->next = NULL;
}
