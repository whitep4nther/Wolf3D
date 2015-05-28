/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 01:25:04 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/28 02:42:48 by ihermell         ###   ########.fr       */
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
# include <X.h>

# include <fcntl.h>
# include <math.h>

# define WIN_WIDTH		1400
# define WIN_HEIGHT		1000

# define MMAP_BCKGD		0x33333300
# define MMAP_WIDTH		300
# define MMAP_HEIGHT	200
# define MMAP_OPACITY	0x99
# define MMAP_RATIO		0.2
# define MMAP_PLAYER_COLOR 0xef323200
# define MMAP_WALL_COLOR 0xffffff00
# define MMAP_RAY_COLOR	0xFF0000C8

# define PLAYER_FOV		60
# define PLAYER_HEIGHT	32
# define PLAYER_SIGHT	1000
# define PLAYER_BASE_SPEED 5

typedef struct			s_player
{
	t_point2			pos;
	t_segment2			sight;
	double				angle;
	int					speed;
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
	char				left;
	char				right;
	char				up;
	char				down;
}						t_input;

typedef struct			s_game
{
	t_player			*player;
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
	double				cos_distance;
	t_point2			intersection;
}						t_w_intersection;

typedef struct			s_render
{
	int					column;
	double				current_angle;
	t_w_intersection	w_intersection[1024];
}						t_render;

typedef struct			s_env
{
	t_mlx				*mlx;
	t_mlx_img			*screen;
	t_mlx_img			*minimap;
	t_pplane			*pplane;
	t_game				*game;
	t_input				*input;
	t_render			*render;
	int					ints[10];
}						t_env;

//LOL
void					draw_wall(t_wall *wall, int color, t_env *e);
//
//
t_env					*init_env(void);

t_map					*load_map(char *map);

void					process(t_env *e);

void					render_minimap(t_env *e);
void					render_minimap_ray(t_segment2 *ray, t_env *e);

void					render(t_env *e);
void					render_wall(t_w_intersection *intersection, t_env *e);
void					render_sector(t_segment2 *ray, t_sector *sector,
						t_env *env);
int						cast_to_sector(t_segment2 *ray, t_sector *sector,
						t_env *e);

double					get_z_in_sector(`

void					update_player_sight(t_player *player);
void					set_player_angle(double angle, t_player *player);
void					turn_left(double angle, t_player *player);
void					turn_right(double angle, t_player *player);
void					move_forward(t_env *e);
void					move_backward(t_env *e);

int						keypress_hook(int keycode, t_env *e);
int						keyrelease_hook(int keycode, t_env *e);
int						mouse_hook(int button, int x, int y, t_env *e);
int						expose_hook(t_env *e);
int						loop_hook(t_env *e);

#endif
