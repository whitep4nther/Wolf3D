/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_clear_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 20:24:07 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/27 20:29:25 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw.h>

void			mlx_clear_image(int color, t_mlx *m)
{
	int			i;
	int			j;	

	i = -1;
	j = -1;
	while (++i < WIN_WIDTH)
		while (++j < WIN_HEIGHT)
			mlx_put_pixel_to_img(i, j, color, m);
}
