/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 19:49:53 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 06:07:10 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				mouse_hook(int button, int x, int y, t_env *e)
{
	printf("%d\n", button);
	(void)button;
	(void)x;
	(void)y;
	(void)e;
	return (0);
}
