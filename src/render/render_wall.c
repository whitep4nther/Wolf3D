/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 19:10:37 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/28 00:53:19 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_wall(t_w_intersection *intersection, t_env *e)
{
	t_wall		*wall;
	int			height;
	int			y1;
	double		coef;

	coef = e->pplane->distance_to_pp / intersection->cos_distance;
	wall = &e->game->map->walls[intersection->wall];
	height = wall->height * coef;
	y1 = e->pplane->center_y - PLAYER_HEIGHT * coef;
	setup_x1_y1_x2(e->render->column, y1, e->render->column, e->mlx->mlx_i);
	setup_y2_color(y1 + height, 0xdddddd00, e->mlx->mlx_i);
	draw_line_to_img(e->screen, e->mlx->mlx_i);
}
