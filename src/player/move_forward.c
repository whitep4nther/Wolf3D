/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 21:44:37 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/26 21:56:29 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			move_forward(t_env *e)
{
	t_player	*player;

	player = e->game->player;
	player->pos.x = player->pos.x + cos(D2R(player->angle)) * player->speed;
	player->pos.y = player->pos.y + sin(D2R(player->angle)) * player->speed;
	update_player_sight(player);
}
