/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_blended_color.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 14:58:57 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 08:48:47 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlxw.h>

int			mlx_get_blended_color(unsigned char *color1, unsigned char *color2)
{
	int		f;
	char	*cf;
	float alpha;

	alpha = abs(255 - color1[3]) / 255.0;
	f = 0;
	cf = (char*)&f;
	//printf("alpha %f\n", alpha);
	cf[0] = color1[0] * alpha + color2[0] * (1.0 - alpha);
	cf[1] = color1[1] * alpha + color2[1] * (1.0 - alpha);
	cf[2] = color1[2] * alpha + color2[2] * (1.0 - alpha);
	cf[3] = color2[3];
	return (f);
}
