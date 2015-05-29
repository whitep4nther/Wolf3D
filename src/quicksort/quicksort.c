/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 23:31:06 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 01:00:52 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quicksort.h>

static void		qs_swap(t_sort *tab, int a, int b)
{
    void		*tmp;

	tmp = tab[a].content;
    tab[a].content = tab[b].content;
    tab[b].content = tmp;
}

void			quicksort(t_sort *tab, int start, int end, double (*cmp)(void *, void *))
{
    int			left = start;
    int			right = end;
    t_sort		*pivot = tab + start;

    if (start >= end)
        return ;
    while (1)
    {
        while (cmp(tab[right].content, pivot->content) > 0)
			right--;
        while (cmp(tab[left].content, pivot->content) < 0)
			left++;
        if (left < right)
            qs_swap(tab, left, right);
        else
			break ;
    }
    quicksort(tab, start, right, cmp);
    quicksort(tab, right + 1, end, cmp);
}
