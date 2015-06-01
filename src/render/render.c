/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 22:41:52 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 09:15:46 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_slice(int y1, int y2, int color, t_render *r)
{
	if (y2 <= r->current_top)
		return ;
	if (y1 < r->current_top)
		y1 = r->current_top;
	if (y2 > r->max_y)
		y2 = r->max_y;
	setup_x1_y1_x2(r->e->column, y1, r->e->column, r->e->mlx->mlx_i);
	setup_y2_color(y2, color, r->e->mlx->mlx_i);
	draw_line_to_img(r->e->screen, r->e->mlx->mlx_i);
	r->current_top = y2;
}

/*static void		render_sky(t_env *e)
{
	setup_x1_y1_x2(e->g_render->column, e->g_render->current_top, e->g_render->column,
		e->mlx->mlx_i);
	setup_y2_color(e->screen->height, 0x00F2F2EF, e->mlx->mlx_i);
	draw_line_to_img(e->screen, e->mlx->mlx_i);
}*/
/*
void			render(t_env *e)
{
	int			i;
	int			j;
	t_texture	*txt;

	txt = e->game->map->textures;
		j = -1;
	while (++j < txt->height)
	{
	i = -1;
		while (++i < txt->width)
		{
			int index = ((j * (txt->width)) + i) * 3;
			int color = *(int*)(txt->data + index);
			color = (color & 0xFFFFFF);
			printf("0x%08.8x, index %d\n", color, index);
			mlx_put_pixel_to_img(i, j, color, e->screen);
		}
	}
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->screen->img, 0, 0);
}*/


void			render(t_env *e)
{
	t_render	r;

	//mlx_clear_image(0x00F2F2EF, e->screen);
	mlx_clear_image(MMAP_BCKGD + MMAP_OPACITY, e->minimap);
	e->column = -1;
	init_render_struct(true_angle(e->game->player->angle + PLAYER_FOV / 2),
		e->game->player->angle, &e->game->player->pos, &r);
	r.base_distance = 0;
	r.depth = 0;
	r.min_y = 0;
	r.max_y = e->screen->height - 1;
	r.e = e;
	while (++e->column < WIN_WIDTH)
	{
		r.current_top = 0;
		render_sector(e->game->map->sectors, &r, e);
		/*if (e->g_render->current_top < e->pplane->center_y + e->game->player->z_shift)
			render_floor(e->pplane->center_y + e->game->player->z_shift, e->game->map->sectors, e);*/
		/*if (e->g_render->current_top < e->screen->height - 1)
			render_sky(e);*/
		render_minimap_seg(&r.ray, MMAP_RAY_COLOR + MMAP_OPACITY, e);
		set_render_struct_ray_angle(true_angle(r.ray_angle - e->pplane->angle_btw_rays),
			PLAYER_SIGHT, &r);
	}
	render_cursor(e);
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
