/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octants_5_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 03:50:31 by ihermell          #+#    #+#             */
/*   Updated: 2015/01/21 19:07:34 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxdraw.h"

void			vertical_line(t_mlxpoint *p0, t_mlxpoint *p1,
				int *i, t_mlx *e)
{
	DL_Y = p0->y;
	while (DL_Y < p1->y)
	{
		mlx_put_pxl_to_img(p0->x, DL_Y,
		LINE_COLOR, e);
		DL_Y++;
	}
}

void			octant_5_6(int *i, t_mlx *e)
{
	if (DL_DX <= DL_DY)
	{
		DL_E = DL_DX;
		DL_DX = DL_E * 2;
		DL_DY = DL_DY * 2;
		while (1)
		{
			mlx_put_pxl_to_img(DL_X, DL_Y, LINE_COLOR, e);
			if (--DL_X == DL_X1)
				break ;
			if ((DL_E = DL_E - DL_DY) >= 0)
			{
				DL_Y--;
				DL_E = DL_E + DL_DX;
			}
		}
	}
	else
		octant_6(i, e);
}

void			octant_6(int *i, t_mlx *e)
{
	DL_E = DL_DY;
	DL_DY = DL_E * 2;
	DL_DX = DL_DX * 2;
	while (1)
	{
		mlx_put_pxl_to_img(DL_X, DL_Y, LINE_COLOR, e);
		if (--DL_Y == DL_Y1)
			break ;
		if ((DL_E = DL_E - DL_DX) >= 0)
		{
			DL_X--;
			DL_E += DL_DY;
		}
	}
}

void			octant_7_8(int *i, t_mlx *e)
{
	if (DL_DX >= -DL_DY)
	{
		DL_E = DL_DX;
		DL_DX = DL_E * 2;
		DL_DY = DL_DY * 2;
		while (1)
		{
			mlx_put_pxl_to_img(DL_X, DL_Y, LINE_COLOR, e);
			if (++DL_X == DL_X1)
				break ;
			if ((DL_E = DL_E + DL_DY) < 0)
			{
				DL_Y--;
				DL_E = DL_E + DL_DX;
			}
		}
	}
	else
		octant_7(i, e);
}

void			octant_7(int *i, t_mlx *e)
{
	DL_E = DL_DY;
	DL_DY = DL_E * 2;
	DL_DX = DL_DX * 2;
	while (1)
	{
		mlx_put_pxl_to_img(DL_X, DL_Y, LINE_COLOR, e);
		if (--DL_Y == DL_Y1)
			break ;
		if ((DL_E = DL_E + DL_DX) > 0)
		{
			DL_X++;
			DL_E += DL_DY;
		}
	}
}
