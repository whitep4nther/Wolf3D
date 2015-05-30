/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 22:41:52 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 06:21:18 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render(t_env *e)
{
	t_render	r;

	mlx_clear_image(0xf2f2ef00, e->screen);
	mlx_clear_image(MMAP_BCKGD + MMAP_OPACITY, e->minimap);
	e->g_render->column = -1;
	init_render_struct(true_angle(e->game->player->angle + PLAYER_FOV / 2),
		e->game->player->angle, &e->game->player->pos, &r);
	r.base_distance = 0;
	r.depth = 0;
	while (++e->g_render->column < WIN_WIDTH)
	{
		e->g_render->current_top = 0;
		render_sector(e->game->map->sectors, &r, e);
		if (e->g_render->current_top < e->pplane->center_y)
			render_floor(e->pplane->center_y, e->game->map->sectors, e);
		render_minimap_ray(&r.ray, e);
		set_render_struct_ray_angle(true_angle(r.ray_angle - e->pplane->angle_btw_rays),
			PLAYER_SIGHT, &r);
	}
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->screen->img, 0, 0);
	render_minimap(e);
	//draw_all_walls(e);
	//draw_ray(&e->game->player->sight, 0x00FF00, e);
	//render_sector(&e->game->player->sight, e->game->map->sectors, e);
}

/*
void			draw_ray(t_segment2 *ray, int color, t_env *e)
{
	setup_x1_y1_x2(ray->points[0].x, WIN_HEIGHT - ray->points[0].y, ray->points[1].x,
		e->mlx);
	setup_y2_color(WIN_HEIGHT - ray->points[1].y, color, e->mlx);
	draw_line(e->mlx);
}

void			draw_wall(t_wall *wall, int color, t_env *e)
{
	setup_x1_y1_x2(wall->seg.points[0].x, WIN_HEIGHT - wall->seg.points[0].y, wall->seg.points[1].x, e->mlx);
	setup_y2_color(WIN_HEIGHT - wall->seg.points[1].y, color, e->mlx);
	draw_line(e->mlx);
}

void			draw_all_walls(t_env *e)
{
	t_map		*map;

	map = e->game->map;
	int i = -1;
	while (++i < map->nb_walls)
		draw_wall(&map->walls[i], 0xFFC549, e);
}
*/
/*
static void		reset_render(t_render *render)
{
}*/
