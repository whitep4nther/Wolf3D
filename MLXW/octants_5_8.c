/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octants_5_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 19:37:48 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 07:06:53 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw.h>

void			vertical_line(t_mlx_img *img, int mlx_i[10])
{
	int			tmp;

	if (DL_Y > DL_Y1)
	{
		tmp = DL_Y;
		DL_Y = DL_Y1;
		DL_Y1 = tmp;
	}
	while (DL_Y < DL_Y1)
	{
		mlx_put_pixel_to_img(DL_X, DL_Y, LINE_COLOR, img);
		DL_Y++;
	}
}

void			octant_5_6(t_mlx_img *img, int mlx_i[10])
{
	if (DL_DX <= DL_DY)
	{
		DL_E = DL_DX;
		DL_DX = DL_E * 2;
		DL_DY = DL_DY * 2;
		while (1)
		{
			mlx_put_pixel_to_img(DL_X, DL_Y, LINE_COLOR, img);
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
		octant_6(img, mlx_i);
}

void			octant_6( t_mlx_img *img, int mlx_i[10])
{
	DL_E = DL_DY;
	DL_DY = DL_E * 2;
	DL_DX = DL_DX * 2;
	while (1)
	{
		mlx_put_pixel_to_img(DL_X, DL_Y, LINE_COLOR, img);
		if (--DL_Y == DL_Y1)
			break ;
		if ((DL_E = DL_E - DL_DX) >= 0)
		{
			DL_X--;
			DL_E += DL_DY;
		}
	}
}

void			octant_7_8(t_mlx_img *img, int mlx_i[10])
{
	if (DL_DX >= -DL_DY)
	{
		DL_E = DL_DX;
		DL_DX = DL_E * 2;
		DL_DY = DL_DY * 2;
		while (1)
		{
			mlx_put_pixel_to_img(DL_X, DL_Y, LINE_COLOR, img);
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
		octant_7(img, mlx_i);
}

void			octant_7(t_mlx_img *img, int mlx_i[10])
{
	DL_E = DL_DY;
	DL_DY = DL_E * 2;
	DL_DX = DL_DX * 2;
	while (1)
	{
		mlx_put_pixel_to_img(DL_X, DL_Y, LINE_COLOR, img);
		if (--DL_Y == DL_Y1)
			break ;
		if ((DL_E = DL_E + DL_DX) > 0)
		{
			DL_X++;
			DL_E += DL_DY;
		}
	}
}
