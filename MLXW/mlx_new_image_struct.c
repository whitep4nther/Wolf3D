/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_image_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 01:41:32 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/28 01:44:23 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw.h>

t_mlx_img		*mlx_new_image_struct(void *mlx, int width, int height)
{
	t_mlx_img	*n;

	n = (t_mlx_img*)malloc(sizeof(t_mlx_img));
	n->img = mlx_new_image(mlx, width, height);
	n->img_data = mlx_get_data_addr(n->img, &n->img_bpp, &n->img_size_line,
		&n->img_endian);
	n->width = width;
	n->height = height;
	return (n);
}
