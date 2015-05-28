/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 00:05:25 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/28 01:14:53 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw.h>

void			setup_x1_y1_x2(int x1, int y1, int x2, int mlx_i[10])
{
	DL_X = x1;
	DL_X0 = x1;
	DL_Y = y1;
	DL_Y0 = y1;
	DL_X1 = x2;
}

void			setup_y2_color(int y2, int color, int mlx_i[10])
{
	DL_Y1 = y2;
	LINE_COLOR = color;
}

void			draw_line_to_img(t_mlx_img *img, int mlx_i[10])
{
	if ((DL_DX = DL_X1 - DL_X0) != 0)
		if (DL_DX > 0)
			if ((DL_DY = DL_Y1 - DL_Y0) != 0)
				if (DL_DY > 0)
					octant_1_2(img, mlx_i);
				else
					octant_7_8(img, mlx_i);
			else
				horizontal_line(img, mlx_i);
		else
			if ((DL_DY = DL_Y1 - DL_Y0) != 0)
				if (DL_DY > 0)
					octant_3_4(img, mlx_i);
				else
					octant_5_6(img, mlx_i);
			else
				horizontal_line(img, mlx_i);
	else
		if ((DL_DY = DL_Y1 - DL_Y0) > 0)
			vertical_line(img, mlx_i);
		else
			vertical_line(img, mlx_i);
}
