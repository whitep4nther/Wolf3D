/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_portal_overlay.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 06:08:54 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 07:07:49 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void		render_portal_overlay(t_portal *portal, t_w_intersection *w_inter,
			t_env *e)
{
	int		color;

	if (portal == e->game->lportal)
		color = LPORTAL_COLOR;
	else
		color = RPORTAL_COLOR;
	mlx_put_pixel_to_img(e->g_render->column, w_inter->projected_y2, color,
		e->screen);
}
