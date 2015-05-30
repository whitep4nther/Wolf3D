/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 00:53:43 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 07:29:33 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		render_minimap_player(t_env *e)
{
	setup_x1_y1_x2(MMAP_WIDTH / 2 - 2, MMAP_HEIGHT / 2 - 1, MMAP_WIDTH / 2 + 2, e->mlx->mlx_i);
	setup_y2_color(MMAP_HEIGHT / 2 - 1, MMAP_PLAYER_COLOR, e->mlx->mlx_i);
	draw_line_to_img(e->minimap, e->mlx->mlx_i);
	setup_x1_y1_x2(MMAP_WIDTH / 2 - 2, MMAP_HEIGHT / 2, MMAP_WIDTH / 2 + 2, e->mlx->mlx_i);
	setup_y2_color(MMAP_HEIGHT / 2, MMAP_PLAYER_COLOR, e->mlx->mlx_i);
	draw_line_to_img(e->minimap, e->mlx->mlx_i);
	setup_x1_y1_x2(MMAP_WIDTH / 2 - 2, MMAP_HEIGHT / 2 + 1, MMAP_WIDTH / 2 + 2, e->mlx->mlx_i);
	setup_y2_color(MMAP_HEIGHT / 2 + 1, MMAP_PLAYER_COLOR, e->mlx->mlx_i);
	draw_line_to_img(e->minimap, e->mlx->mlx_i);
}

static void		render_minimap_walls(t_env *e)
{
	int			i;
	t_wall		*wall;
	t_map		*map;
	t_player	*p;

	i = -1;
	map = e->game->map;
	p = e->game->player;
	while (++i < map->nb_walls)
	{
		wall = &map->walls[i];
		e->ints[0] = (wall->seg.points[0].x - p->pos.x) * MMAP_RATIO + MMAP_WIDTH / 2;
		e->ints[1] = (wall->seg.points[0].y - p->pos.y) * MMAP_RATIO + MMAP_HEIGHT / 2;
		e->ints[2] = (wall->seg.points[1].x - p->pos.x) * MMAP_RATIO + MMAP_WIDTH / 2;
		e->ints[3] = (wall->seg.points[1].y - p->pos.y) * MMAP_RATIO + MMAP_HEIGHT / 2;
		setup_x1_y1_x2(e->ints[0], e->ints[1], e->ints[2], e->mlx->mlx_i);
		setup_y2_color(e->ints[3], MMAP_WALL_COLOR, e->mlx->mlx_i);
		draw_line_to_img(e->minimap, e->mlx->mlx_i);
	}
}

void			render_minimap_seg(t_segment2 *seg, int color, t_env *e)
{
	t_player	*p;

	p = e->game->player;
	e->ints[0] = floor((seg->points[0].x - p->pos.x) * MMAP_RATIO + MMAP_WIDTH / 2);
	e->ints[1] = floor((seg->points[0].y - p->pos.y) * MMAP_RATIO + MMAP_HEIGHT / 2);
	e->ints[2] = floor((seg->points[1].x - p->pos.x) * MMAP_RATIO + MMAP_WIDTH / 2);
	e->ints[3] = floor((seg->points[1].y - p->pos.y) * MMAP_RATIO + MMAP_HEIGHT / 2);
	setup_x1_y1_x2(e->ints[0], e->ints[1], e->ints[2], e->mlx->mlx_i);
	setup_y2_color(e->ints[3], color, e->mlx->mlx_i);
	draw_line_to_img(e->minimap, e->mlx->mlx_i);
}

void			render_minimap(t_env *e)
{
	render_minimap_player(e);
	render_minimap_walls(e);
	render_minimap_portal(e->game->lportal, e);
	render_minimap_portal(e->game->rportal, e);
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->minimap->img,
		50, 50);
}
