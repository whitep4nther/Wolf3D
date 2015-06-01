/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 18:57:07 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 06:30:27 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		render_sky(t_render *r)
{
	setup_x1_y1_x2(r->e->column, r->current_top, r->e->column,
		r->e->mlx->mlx_i);
	setup_y2_color(r->max_y, 0x00F2F2EF, r->e->mlx->mlx_i);
	draw_line_to_img(r->e->screen, r->e->mlx->mlx_i);
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
		if (r->tmp_wall->column_rendered == r->e->column
			&& r->tmp_wall->depth_rendered == r->depth)
			continue ;
		r->tmp_wall->column_rendered = r->e->column;
		r->tmp_wall->depth_rendered = r->depth;
		render_floor(r->tmp_inter->projected_y1, sector, r, e);
		if ((portal = w_inter_in_portals(r->tmp_inter, e))
			&& is_portal_visible(r->ray_angle, portal)
			&& r->current_top < r->tmp_inter->projected_y2)
			render_portal(portal, r->tmp_inter, r, e);
		else if (r->tmp_wall->is_portal == 0)
			render_wall(r->tmp_inter, r);
		else
		{
			r->tmp_sector = next_sector(r->tmp_wall, sector, e->game->map->sectors);
			render_step_up(sector, r->tmp_sector, r->tmp_inter, r, e);
			return (render_sector(r->tmp_sector, r, e));
		}
	}
	if (r->current_top < e->pplane->center_y + e->game->player->z_shift)
		render_floor(e->pplane->center_y + e->game->player->z_shift, e->game->map->sectors, r, e);
	if (r->current_top < r->max_y)
		render_sky(r);
}
