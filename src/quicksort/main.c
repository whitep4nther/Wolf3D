/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 00:11:56 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 00:33:03 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quicksort.h>
#include <stdio.h>

int			cmp(void *n1, void *n2)
{
	return (*((int *)n1) - *((int *)n2));
}

int			main(int ac, char **av)
{
	int		tab[10] = {5, 3, -2, 45, 6, 123, 456, 344, 23, -8};
	t_sort	to_sort[10];

	int i =-1;
	while (++i < 10)
		to_sort[i].content = tab + i;
	i = -1;
	while (++i < 10)
	{
		printf("%d\n", *((int *)(to_sort[i].content)));
	}
	printf("==========\n");
	quicksort(to_sort, 0, 9, cmp);
	i = -1;
	while (++i < 10)
	{
		printf("%d\n", *((int *)(to_sort[i].content)));
	}
	return (0);
}
