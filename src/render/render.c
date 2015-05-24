/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 21:29:26 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/24 22:08:36 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render(t_env *env)
{
	t_segment2	ray;

	ray = fill_segment2(50, 150, 600, 150);
	render_sector(&ray, env->game, env->mlx, env->render);
}
