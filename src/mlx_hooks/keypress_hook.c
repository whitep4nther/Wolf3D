/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:03:29 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 12:42:41 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				keypress_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_W)
	{
		e->input->w = 1;
		if (e->input->s)
			e->input->s = 2;
	}
	else if (keycode == KEY_S)
	{
		e->input->s = 1;
		if (e->input->w)
			e->input->w = 2;
	}
	else if (keycode == KEY_A)
	{
		e->input->a = 1;
		if (e->input->d)
			e->input->d = 2;
	}
	else if (keycode == KEY_D)
	{
		e->input->d = 1;
		if (e->input->a)
			e->input->a = 2;
	}
	return (0);
	(void)e;
}
