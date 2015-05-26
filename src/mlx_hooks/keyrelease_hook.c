/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:05:55 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/26 22:06:10 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				keyrelease_hook(int keycode, t_env *e)
{
	if (keycode == KEY_LEFT)
		e->input->left = 0;
	else if (keycode == KEY_RIGHT)
		e->input->right = 0;
	else if (keycode == KEY_UP)
		e->input->up = 0;
	else if (keycode == KEY_DOWN)
		e->input->down = 0;
	return (0);
	(void)e;
}
