/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 06:21:14 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 06:29:14 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <texture.h>

void			load_texture(char *filename, t_texture *texture)
{
	texture->data = load_bmp_file(filename, &texture->file_info);
	texture->width = texture->file_info.biWidth;
	texture->height = texture->file_info.biHeight;
}
