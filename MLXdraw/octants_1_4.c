/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 03:35:08 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/25 23:36:38 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxdraw.h"

void			horizontal_line(t_mlx *e)
{
	int			tmp;

	if (DL_X > DL_X1)
	{
		tmp = DL_X;
		DL_X = DL_X1;
		DL_X1 = tmp;
	}
	while (DL_X < DL_X1)
	{
		mlx_pixel_put(DL_X, DL_Y, LINE_COLOR, e);
		DL_X++;
	}
}

void			octant_1_2(int *i, t_mlx *e)
{
	if (DL_DX >= DL_DY)
	{
		DL_E = DL_DX;
		DL_DX = DL_E * 2;
		DL_DY = DL_DY * 2;
		while (1)
		{
			mlx_put_pxl_to_img(DL_X, DL_Y, LINE_COLOR, e);
			if (++DL_X == DL_X1)
				break ;
			if ((DL_E = DL_E - DL_DY) < 0)
			{
				DL_Y++;
				DL_E = DL_E + DL_DX;
			}
		}
	}
	else
		octant_2(i, e);
}

void			octant_2(int *i, t_mlx *e)
{
	DL_E = DL_DY;
	DL_DY = DL_E * 2;
	DL_DX = DL_DX * 2;
	while (1)
	{
		mlx_put_pxl_to_img(DL_X, DL_Y, LINE_COLOR, e);
		if (++DL_Y == DL_Y1)
			break ;
		if ((DL_E = DL_E - DL_DX) < 0)
		{
			DL_X++;
			DL_E = DL_E + DL_DY;
		}
	}
}

void			octant_3_4(int *i, t_mlx *e)
{
	if (-DL_DX >= DL_DY)
	{
		DL_E = DL_DX;
		DL_DX = DL_E * 2;
		DL_DY = DL_DY * 2;
		while (1)
		{
			mlx_put_pxl_to_img(DL_X, DL_Y, LINE_COLOR, e);
			if (--DL_X == DL_X1)
				break ;
			if ((DL_E = DL_E + DL_DY) >= 0)
			{
				DL_Y++;
				DL_E = DL_E + DL_DX;
			}
		}
	}
	else
		octant_3(i, e);
}

void			octant_3(int *i, t_mlx *e)
{
	DL_E = DL_DY;
	DL_DY = DL_E * 2;
	DL_DX = DL_DX * 2;
	while (1)
	{
		mlx_put_pxl_to_img(DL_X, DL_Y, LINE_COLOR, e);
		if (++DL_Y == DL_Y1)
			break ;
		if ((DL_E = DL_E + DL_DX) <= 0)
		{
			DL_X--;
			DL_E = DL_E + DL_DY;
		}
	}
}
