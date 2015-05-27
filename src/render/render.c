/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 22:41:52 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/27 20:38:44 by ihermell         ###   ########.fr       */
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
static void		set_ray(double angle, t_segment2 *ray)
{
	ray->points[1].x = ray->points[0].x + cos(D2R(angle)) * PLAYER_SIGHT;
	ray->points[1].y = ray->points[0].y + sin(D2R(angle)) * PLAYER_SIGHT;
}

void			render(t_env *e)
{
	t_render	*r;
	t_segment2	ray;
	int			current_angle;

	printf("hey\n");
	r = e->render;
	r->column = 0;
	ray.points[0].x = e->game->player->pos.x;
	ray.points[0].y = e->game->player->pos.y;
	current_angle = true_angle(e->game->player->angle + PLAYER_FOV / 2);
	while (r->column < WIN_WIDTH)
	{
		set_ray(current_angle, &ray);
		render_sector(&ray, e->game->map->sectors, e);
		current_angle += e->pplane->angle_btw_rays;
		r->column++;
	}
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->mlx->img, 0, 0);
	mlx_clear_image(0x202020, e->mlx);
	//draw_all_walls(e);
	//draw_ray(&e->game->player->sight, 0x00FF00, e);
	//render_sector(&e->game->player->sight, e->game->map->sectors, e);
}
