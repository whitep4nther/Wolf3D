/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 23:32:04 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 00:55:44 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

# define MAX_LEVELS		1000

typedef struct			s_sort
{
	void				*content;
}						t_sort;

void					quicksort(t_sort *tab, int start, int end,
						double (*cmp)(void *, void *));

#endif
