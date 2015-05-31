/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 02:27:39 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 07:33:05 by ihermell         ###   ########.fr       */
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
// 3 to 2
	env = init_env();
	env->game->map = load_map("maps/map.w");
	env->game->lportal->wall = &env->game->map->walls[2];
	env->game->lportal->sector = env->game->map->sectors;
	env->game->lportal->pos.x = 171.554160;
	env->game->lportal->pos.y = 863.278600;
	set_portal_angle(243.434949, env->game->lportal);
	env->game->rportal->wall = &env->game->map->walls[1];
	env->game->rportal->sector = env->game->map->sectors;
	env->game->rportal->pos.x = 400;
	env->game->rportal->pos.y = 550;
	set_portal_angle(180, env->game->rportal);
	env->game->player->current_sector = env->game->map->sectors;
	/*mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "lol");
	mlx_key_hook(win, test, mlx);*/
	mlx_loop(env->mlx->mlx);
	(void)ac;
	(void)av;
	return (0);
}
