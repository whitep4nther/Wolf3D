/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 22:41:52 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/26 22:00:32 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

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

void			render(t_env *e)
{
	mlx_clear_window(e->mlx->mlx, e->mlx->win);
	draw_all_walls(e);
	draw_ray(&e->game->player->sight, 0x00FF00, e);
	render_sector(&e->game->player->sight, e->game->map->sectors, e);
}
