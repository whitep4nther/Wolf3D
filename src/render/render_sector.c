/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 18:57:07 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/25 23:06:15 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_sector(t_segment2 *ray, t_sector *sector, t_env *e)
{
	int			walls_intersected;
	int			i;
	t_wall		*wall;
	t_render	*r;

	walls_intersected = cast_to_sector(ray, sector, e);
	i = -1;
	r = e->render;
	while (++i < walls_intersected)
	{
		wall = &e->game->map->walls[r->w_intersection[i].wall];
		printf("Wall: X1 %.2lf, y1 %.2lf, x2 %.2lf, y2 %.2lf\n", wall->seg.points[0].x, wall->seg.points[i].y, wall->seg.points[1].x, wall->seg.points[1].y);
	}
	printf("%d\n", walls_intersected);
}
