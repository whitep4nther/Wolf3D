/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 18:57:07 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/24 22:08:01 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_sector(t_segment2 *ray, t_game *game, t_mlx *mlx,
				t_render *render)
{
	int			walls_intersected;

	walls_intersected = cast_to_sector(ray, game->map->sectors +
		game->player->current_sector, game, render);
	printf("%d\n", walls_intersected);
	(void)mlx;
}
