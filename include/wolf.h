/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 01:25:04 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/25 23:58:01 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

//
# include <stdio.h>

# include <get_next_line.h>
# include <libft.h>
# include <space3d.h>
# include <mlxw.h>

# include <fcntl.h>

# define WIN_WIDTH		1400
# define WIN_HEIGHT		1000

# define PLAYER_FOV		60
# define PLAYER_HEIGHT	32

typedef struct			s_player
{
	t_point2			pos;
	double				angle;
	int					height;
	int					fov;
	int					current_sector;
}						t_player;

typedef struct			s_wall
{
	t_segment2			seg;
	int					height;
	int					is_portal;
	int					sectors_id[2];
}						t_wall;

typedef struct			s_sector
{
	t_point3			reference;
	double				z1;
	double				z2;
	int					*walls;
	int					nb_walls;
}						t_sector;

typedef struct			s_map
{
	t_wall				*walls;
	t_sector			*sectors;
	int					nb_walls;
	int					nb_sectors;
}						t_map;

typedef struct			s_input
{
}						t_input;

typedef struct			s_game
{
	t_player			*player;
	t_input				*input;
	t_map				*map;
}						t_game;

typedef struct			s_pplane
{
	int					width;
	int					height;
	int					center_x;
	int					center_y;
	double				distance_to_pp;
	double				angle_btw_rays;
}						t_pplane;

typedef struct			s_w_intersection
{
	int					wall;
	double				distance;
}						t_w_intersection;

typedef struct			s_render
{
	t_w_intersection	w_intersection[1024];
}						t_render;

typedef struct			s_env
{
	t_mlx				*mlx;
	t_pplane			*pplane;
	t_game				*game;
	t_render			*render;
}						t_env;

t_env					*init_env(void);

t_map					*load_map(char *map);

void					render(t_env *e);
void					render_sector(t_segment2 *ray, t_sector *sector,
						t_env *env);
int						cast_to_sector(t_segment2 *ray, t_sector *sector,
						t_env *e);

int						key_hook(int keycode, t_env *e);
int						loop_hook(t_env *e);

#endif
