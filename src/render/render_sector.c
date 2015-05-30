/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 18:57:07 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 03:23:57 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static t_portal		*check_portals(t_render *r, t_env *e)
{
	if (e->game->lportal->wall
		&& r->tmp_wall->id == e->game->lportal->wall->id
		&& point_in_portal(e->game->lportal, &r->tmp_inter->intersection))
		return (e->game->lportal);
	if (e->game->rportal->wall
		&& r->tmp_wall->id == e->game->rportal->wall->id
		&& point_in_portal(e->game->rportal, &r->tmp_inter->intersection))
		return (e->game->rportal);
	return (NULL);
}

void			render_sector(t_sector *sector, t_render *r, t_env *e)
{
	int			walls_intersected;
	int			i;
	t_portal	*portal;
	
	walls_intersected = cast_to_sector_walls(&r->ray, sector,
		r->w_intersection, r->sort);
	process_walls_intersections(walls_intersected, sector, r, e);
	quicksort(r->sort, 0, walls_intersected - 1, qs_walls_cmp);
	i = -1;
	while (++i < walls_intersected)
	{
		r->tmp_inter = r->sort[i].content;
		r->tmp_wall = r->tmp_inter->wall;
		if (r->tmp_wall->column_rendered == e->g_render->column
			&& r->tmp_wall->depth_rendered == r->depth)
			continue ;
		r->tmp_wall->column_rendered = e->g_render->column;
		r->tmp_wall->depth_rendered = r->depth;
		render_floor(r->tmp_inter->projected_y1, sector, e);
		if ((portal = check_portals(r, e)))
			render_through_portal(portal, the_other_portal(portal, e), r, e);
		else if (r->tmp_wall->is_portal == 0)
			render_wall(r->tmp_inter, e);
		else
		{
			r->tmp_sector = next_sector(r->tmp_wall, sector, e->game->map->sectors);
			render_step_up(sector, r->tmp_sector, r->tmp_inter, e);
			return (render_sector(r->tmp_sector, r, e));
		}
	}
}
