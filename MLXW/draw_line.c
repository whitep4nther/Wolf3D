/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 03:29:42 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/27 19:40:46 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw.h>

void			setup_x1_y1_x2(int x1, int y1, int x2, t_mlx *m)
{
	DL_X = x1;
	DL_X0 = x1;
	DL_Y = y1;
	DL_Y0 = y1;
	DL_X1 = x2;
}

void			setup_y2_color(int y2, int color, t_mlx *m)
{
	DL_Y1 = y2;
	LINE_COLOR = color;
}

void			draw_line(t_mlx *m)
{
	if ((DL_DX = DL_X1 - DL_X0) != 0)
		if (DL_DX > 0)
			if ((DL_DY = DL_Y1 - DL_Y0) != 0)
				if (DL_DY > 0)
					octant_1_2(m);
				else
					octant_7_8(m);
			else
				horizontal_line(m);
		else
			if ((DL_DY = DL_Y1 - DL_Y0) != 0)
				if (DL_DY > 0)
					octant_3_4(m);
				else
					octant_5_6(m);
			else
				horizontal_line(m);
	else
		if ((DL_DY = DL_Y1 - DL_Y0) > 0)
			vertical_line(m);
		else
			vertical_line(m);
}
