/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 03:46:36 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/24 03:49:18 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list			*new_list(void *content)
{
	t_list		*list;

	list = (t_list*)malloc(sizeof(t_list));
	list->content = content;
	list->next = NULL;
	return (list);
}
