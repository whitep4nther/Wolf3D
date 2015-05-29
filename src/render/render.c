/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 22:41:52 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 08:28:54 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
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

void			render(t_env *e)
{
	t_render	*r;
	t_segment2	ray;

	mlx_clear_image(0xf2f2ef00, e->screen);
	mlx_clear_image(MMAP_BCKGD + MMAP_OPACITY, e->minimap);
	r = e->render;
	r->column = -1;
	ray.points[0].x = e->game->player->pos.x;
	ray.points[0].y = e->game->player->pos.y;
	e->render->current_angle = true_angle(e->game->player->angle + PLAYER_FOV / 2);
	while (++r->column < WIN_WIDTH)
	{
		set_ray(e->render->current_angle, &ray);
		r->current_top = 0;
		render_sector(&ray, e->game->map->sectors, 0, e);
			if (e->render->current_top < e->pplane->center_y)
			render_floor(e->pplane->center_y, e->game->map->sectors, e);
		render_minimap_ray(&ray, e);
		e->render->current_angle = true_angle(e->render->current_angle -
			e->pplane->angle_btw_rays);
	}
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->screen->img, 0, 0);
	render_minimap(e);
	//draw_all_walls(e);
	//draw_ray(&e->game->player->sight, 0x00FF00, e);
	//render_sector(&e->game->player->sight, e->game->map->sectors, e);
}
