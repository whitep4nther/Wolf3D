/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_player_movement.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 04:06:43 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 05:42:44 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void					process_player_movement(double angle, int speed,
						t_player *p, t_env *e)
{
	t_segment2			move_x;
	t_segment2			move_y;
	int					walls;
	t_portal			*from;
	t_portal			*to;
	t_w_intersection	*w_inter;
	double				cosa;
	double				sina;

	cosa = cos(D2R(angle));
	sina = sin(D2R(angle));
	move_x.points[0] = p->pos;
	move_x.points[1].x = p->pos.x + speed * cosa;
	move_x.points[1].y = p->pos.y;
	move_y.points[0] = p->pos;
	move_y.points[1].x = p->pos.x;
	move_y.points[1].y = p->pos.y + speed * sina;
	walls = cast_to_sector_walls(&move_x, p->current_sector, p->walls, p->sort);
	if (walls > 0)
	{
		quicksort(p->sort, 0, walls - 1, qs_walls_cmp);
		w_inter = p->sort[0].content;
		if ((from = w_inter_in_portals(w_inter, e))
			&& is_portal_visible(angle, from))
		{
			to = the_other_portal(from, e);
			get_portal_new_pos(from, &w_inter->intersection, to, &p->pos);
			p->angle = true_angle(to->angle + p->angle - 180 - from->angle);
			return ;
		}
		p->pos.x = ((t_w_intersection*)p->sort[0].content)->intersection.x +
			2 * -cosa;
	}
	else
		p->pos.x = move_x.points[1].x;
	walls = cast_to_sector_walls(&move_y, p->current_sector, p->walls, p->sort);
	if (walls > 0)
	{
		quicksort(p->sort, 0, walls - 1, qs_walls_cmp);
		w_inter = p->sort[0].content;
		if ((from = w_inter_in_portals(w_inter, e))
			&& is_portal_visible(angle, from))
		{
			to = the_other_portal(from, e);
			get_portal_new_pos(from, &w_inter->intersection, to, &p->pos);
			p->angle = true_angle(to->angle + p->angle - 180 - from->angle);
			return ;
		}
		p->pos.y = ((t_w_intersection*)p->sort[0].content)->intersection.y +
			2 * -sina;
	}
	else
		p->pos.y = move_y.points[1].y;
	update_player_sight(p);
	(void)e;
}
