/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_sight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 21:23:13 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/26 21:47:51 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			update_player_sight(t_player *player)
{
	player->sight.points[0].x = player->pos.x;
	player->sight.points[0].y = player->pos.y;
	player->sight.points[1].x = player->pos.x + cos(D2R(player->angle)) * PLAYER_SIGHT;
	player->sight.points[1].y = player->pos.y + sin(D2R(player->angle)) * PLAYER_SIGHT;
}
