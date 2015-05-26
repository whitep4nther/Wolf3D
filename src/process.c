/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:24:27 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/26 22:41:04 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			process(t_env *e)
{
	if (e->input->left == 1)
		turn_left(3, e->game->player);
	else if (e->input->right == 1)
		turn_right(3, e->game->player);
	if (e->input->up == 1)
		move_forward(e);
	else if (e->input->down == 1)
		move_backward(e);
}
