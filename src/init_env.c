/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 02:31:34 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/27 21:13:30 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static t_mlx	*init_mlx(void)
{
	t_mlx		*m;

	m = (t_mlx*)malloc(sizeof(t_mlx));
	m->mlx = mlx_init();
	if (!m->mlx)
		exit(0);
	m->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, "Wolfie3D");
	m->img = mlx_new_image(m->mlx, WIN_WIDTH, WIN_HEIGHT);
	m->img_data = mlx_get_data_addr(m->img, &m->img_bpp, &m->img_size_line,
		&m->img_endian);
	return (m);
}

static t_game	*init_game(void)
{
	t_game		*game;

	game = (t_game*)malloc(sizeof(t_game));
	game->map = NULL;
	game->player = (t_player*)malloc(sizeof(t_player));
	fill_point2(100, 400, &game->player->pos);
	game->player->angle = 60;
	game->player->fov = PLAYER_FOV;
	game->player->height = PLAYER_HEIGHT;
	game->player->current_sector = 0;
	game->player->speed = PLAYER_BASE_SPEED;
	update_player_sight(game->player);
	return (game);
}

static t_pplane	*init_pplane(void)
{
	t_pplane	*p;

	p = (t_pplane*)malloc(sizeof(t_pplane));
	p->width = WIN_WIDTH;
	p->height = WIN_HEIGHT;
	p->center_x = WIN_WIDTH / 2;
	p->center_y = WIN_HEIGHT / 2;
	p->distance_to_pp = (p->width / 2) / tan(D2R(PLAYER_FOV / 2));
	p->angle_btw_rays = PLAYER_FOV / p->width;
	return (p);
}

t_env			*init_env(void)
{
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->game = init_game();
	env->mlx = init_mlx();
	env->pplane = init_pplane();
	env->render = (t_render*)malloc(sizeof(t_render));
	env->input = (t_input*)malloc(sizeof(t_input));
	ft_bzero(env->input, sizeof(t_input));
	mlx_hook(env->mlx->win, KeyPress, KeyPressMask, keypress_hook, env);
	mlx_hook(env->mlx->win, KeyRelease, KeyReleaseMask, keyrelease_hook, env);
	mlx_mouse_hook(env->mlx->win, mouse_hook, env);
	return (env);
}
