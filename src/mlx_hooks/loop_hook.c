/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 22:40:52 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 12:44:47 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

clock_t last = 0;

int				loop_hook(t_env *e)
{
	clock_t	timerz = clock();
	if (last)
	{
	double s = 1 / ((double)(timerz - last) / (double)CLOCKS_PER_SEC);
	if (s < 55)
	printf("%d fps\n", (int)s);
	}
	last = timerz;
	process(e);
	render(e);
	(void)e;
	return (0);
}
