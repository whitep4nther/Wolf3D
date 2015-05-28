/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 02:27:39 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/28 00:37:24 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
/*
int				test(int keycode, void *param)
{
	if (keycode == KEY_ESCAPE)
		exit(0);
	(void)param;
	return(0);
}*/

int				main(int ac, char **av)
{
	t_env		*env;
	/*void		*mlx;
	void		*win;*/

	env = init_env();
	env->game->map = load_map("maps/map.w");
	/*mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "lol");
	mlx_key_hook(win, test, mlx);*/
	mlx_loop(env->mlx->mlx);
	(void)ac;
	(void)av;
	return (0);
}
