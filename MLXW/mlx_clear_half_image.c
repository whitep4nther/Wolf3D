/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear_half_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 14:51:34 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 14:52:24 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw.h>

void			mlx_clear_half_image(int color, t_mlx_img *img)
{
	int			i;
	int			j;	

	i = -1;
	while (++i < img->width)
	{
		j = img->height - 1;
		while (--j > img->height / 2)
			mlx_put_pixel_to_img(i, j, color, img);
	}
}
