/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 22:40:52 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/27 21:07:50 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				loop_hook(t_env *e)
{
	ft_putendl("lol");
	printf("roh\n");
	//process(e);
	printf("hey\n");
	//render(e);
	(void)e;
	return (0);
}
