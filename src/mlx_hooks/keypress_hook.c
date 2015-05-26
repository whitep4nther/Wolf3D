/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:03:29 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/26 22:06:30 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				keypress_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_LEFT)
	{
		e->input->left = 1;
		e->input->right = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		e->input->left = 0;
		e->input->right = 1;
	}
	else if (keycode == KEY_UP)
	{
		e->input->up = 1;
		e->input->down = 0;
	}
	else if (keycode == KEY_DOWN)
	{
		e->input->up = 0;
		e->input->down = 1;
	}
	return (0);
	(void)e;
}
