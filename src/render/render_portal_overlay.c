/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_portal_overlay.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 06:08:54 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 16:24:31 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		render_portal_overlay(t_portal *portal, t_w_intersection *w_inter,
			t_env *e)
{
	int		color;
	int		actual_color;
	int		tmp;
	int		index;
	int		y1;
	int		y2;

	if (portal == e->game->lportal)
		color = LPORTAL_COLOR + 0xAA000000;
	else
		color = RPORTAL_COLOR + 0xAA000000;
	y1 = w_inter->projected_y1 - 1;
	y2 = w_inter->projected_y2;
	if (y2 <= e->g_render->current_top)
	{printf("het\n");
		return ;}
	if (y1 < 0)
		y1 = 0;
	if (y2 >= e->screen->height)
		y2 = e->screen->height - 1;
	index = e->screen->img_size_line * (e->screen->height - y1 - 2) +
		e->g_render->column * (e->screen->img_bpp >> 3);
	while (++y1 <= y2)
	{
		tmp = *((int*)(e->screen->img_data + index));
		actual_color = mlx_get_blended_color((unsigned char*)&color,
			(unsigned char*)(e->screen->img_data + index));
		//actual_color = color;
		mlx_put_pixel_to_img(e->g_render->column, y1, actual_color, e->screen);
		index -= e->screen->img_size_line;
	}
}
