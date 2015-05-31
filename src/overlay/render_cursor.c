/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 12:46:30 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 14:08:35 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_cursor(t_env *e)
{
	int			x;
	int			y;
	int			radius;
	int			tmp1;
	int			tmp2;

	radius = 12;
	y = -radius - 1;
	while (++y <= radius * 0.100)
	{
		x = -radius - 1;
		while (++x <= radius * -0.200)
			if (abs((tmp1 = x * x + y * y) - (tmp2 = radius * radius)) < radius)
				mlx_put_pixel_to_img(e->pplane->center_x + x,
					e->pplane->center_y + y, LPORTAL_COLOR, e->screen);
	}
	y = -radius - 1;
	while (++y <= radius * 0.100)
	{
		x = radius * 0.200;
		while (++x <= radius)
			if (abs((tmp1 = x * x + y * y) - (tmp2 = radius * radius)) < radius)
				mlx_put_pixel_to_img(e->pplane->center_x + x,
					e->pplane->center_y + y, RPORTAL_COLOR, e->screen);
	}
	y = radius * 0.4000;
	while (++y <= radius)
	{
		x = -radius - 1;
		while (++x <= radius)
			if (abs((tmp1 = x * x + y * y) - (tmp2 = radius * radius)) < radius)
				mlx_put_pixel_to_img(e->pplane->center_x + x,
					e->pplane->center_y + y, 0x00FFFFFF, e->screen);
	}
}
