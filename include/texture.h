/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 06:23:50 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 06:29:29 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include <bmp.h>

typedef struct			s_texture
{
	t_bitmapinfoheader	file_info;
	unsigned char		*data;
	int					width;
	int					height;
}						t_texture;

void					load_texture(char *filename, t_texture *texture);

#endif
