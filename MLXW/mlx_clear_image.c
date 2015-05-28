/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 20:24:07 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/28 00:36:53 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw.h>
#include <stdio.h>
void			mlx_clear_image(int color, t_mlx_img *img)
{
	int			i;
	int			j;	

	i = -1;
	while (++i < img->width)
	{
		j = -1;
		while (++j < img->height)
			mlx_put_pixel_to_img(i, j, color, img);
	}
}
