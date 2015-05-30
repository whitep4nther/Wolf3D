/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 21:53:02 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 05:33:05 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			set_player_angle(double angle, t_player *player)
{
	player->angle = true_angle(angle);
	player->angle_cos = cos(D2R(player->angle));
	player->angle_sin = sin(D2R(player->angle));
	update_player_sight(player);
}
