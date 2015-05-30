/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 21:41:53 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 04:35:56 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		turn_left(double angle, t_player *player)
{
	set_player_angle(player->angle + angle, player);
}
