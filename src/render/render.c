/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 22:41:52 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/25 23:56:33 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render(t_env *e)
{
	t_segment2	ray;

	ray = fill_segment2(50, 150, 800, 150);
	render_sector(&ray, e->game->map->sectors, e);
}
