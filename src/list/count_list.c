/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 03:57:02 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/24 03:59:26 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int			count_list(t_list *list)
{
	int		len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}
