/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:05:55 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 10:14:47 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				keyrelease_hook(int keycode, t_env *e)
{
	if (keycode == KEY_A)
	{
		e->input->a = 0;
		if (e->input->d == 2)
			e->input->d = 1;
	}
	if (keycode == KEY_D)
	{
		e->input->d = 0;
		if (e->input->a == 2)
			e->input->a = 1;
	}
	if (keycode == KEY_W)
	{
		e->input->w = 0;
		if (e->input->s == 2)
			e->input->s = 1;
	}
	if (keycode == KEY_S)
	{
		e->input->s = 0;
		if (e->input->w == 2)
			e->input->w = 1;
	}
	return (0);
	(void)e;
}
