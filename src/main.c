/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 02:27:39 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/24 05:20:31 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				main(int ac, char **av)
{
	t_env		*env;

	env = init_env();
	env->game->map = load_map("maps/map.w");
	mlx_loop(env->mlx->mlx);
	(void)ac;
	(void)av;
	return (0);
}
