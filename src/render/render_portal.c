/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_portal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 06:19:06 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 16:23:37 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_portal(t_portal *portal, t_w_intersection *w_inter,
				t_render *r, t_env *e)
{
	render_through_portal(portal, the_other_portal(portal, e), r, e);
	render_portal_overlay(portal, w_inter, e);
	e->g_render->current_top = r->tmp_inter->projected_y2;
}
