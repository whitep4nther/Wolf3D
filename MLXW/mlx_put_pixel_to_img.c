/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel_to_img.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 19:57:31 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/28 02:32:08 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw.h>

void			mlx_put_pixel_to_img(int x, int y, int color,
				t_mlx_img *img)
{
	int			index;
	char		*ccolor;

	if (y < 0 || y >= img->height || x < 0 || x >= img->width)
		return ;
	index = img->img_size_line * y + (x * img->img_bpp / 8);
	ccolor = (char*)&color;
	img->img_data[index] = ccolor[3];
	img->img_data[index + 1] = ccolor[2];
	img->img_data[index + 2] = ccolor[1];
	img->img_data[index + 3] = ccolor[0];
}
