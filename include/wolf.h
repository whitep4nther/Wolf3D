/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 01:25:04 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 03:27:42 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

//
# include <stdio.h>

# include <fcntl.h>
# include <math.h>
# include <X.h>

# include <space3d.h>
# include <mlxw.h>
# include <get_next_line.h>
# include <libft.h>

# include <quicksort.h>

# define WIN_WIDTH		1400
# define WIN_HEIGHT		1000

# define MMAP_BCKGD		0x33333300
# define MMAP_WIDTH		300
# define MMAP_HEIGHT	200
# define MMAP_OPACITY	0x99
# define MMAP_RATIO		0.1
# define MMAP_PLAYER_COLOR 0xef323200
# define MMAP_WALL_COLOR 0xffffff00
# define MMAP_RAY_COLOR	0xFF0000C8

# define PLAYER_FOV		60
# define PLAYER_HEIGHT	32
# define PLAYER_SIGHT	1000
# define PLAYER_BASE_SPEED 5

# define PORTAL_WIDTH	64

# define DO_CALCULATION	1
# define NO_CALCULATION	0

typedef struct			s_wall
{
	int					id;
	t_segment2			seg;
	double				angle;
	double				cos;
	double				sin;
	int					height;
	int					is_portal;
	int					sectors_id[2];
	int					column_rendered;
	char				depth_rendered;
}						t_wall;

typedef struct			s_sector
{
	int					id;
	t_point3			reference;
	double				z1;
	double				z2;
	t_wall				**walls;
	int					nb_walls;
}						t_sector;

typedef struct			s_portal
{
	t_wall				*wall;
	t_sector			*sector;
	t_point2			pos;
	double				angle;
	double				cos;
	double				sin;
}						t_portal;

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
	t_wall				*wall;
	double				distance;
	double				cos_distance;
	t_point2			intersection;
	double				coef;
	int					projected_y1;
	int					projected_y2;
	int					projected_height;
}						t_w_intersection;

typedef struct			s_render
{
	t_segment2			ray;
	double				ray_angle;
	double				reference_angle;
	double				cos_ray_ref;
	double				base_distance;
	char				depth;
	t_point2			reference_pos;
	t_w_intersection	w_intersection[512];
	t_sort				sort[512];
	t_w_intersection	*tmp_inter;
	t_wall				*tmp_wall;
	t_sector			*tmp_sector;
}						t_render;

typedef struct			s_player
{
	t_point2			pos;
	t_segment2			sight;
	double				angle;
	int					speed;
	int					height;
	int					fov;
	t_sector			*current_sector;
	t_w_intersection	walls[101];
	t_sort				sort[101];
}						t_player;

typedef struct			s_game
{
	t_player			*player;
	t_map				*map;
	t_portal			*lportal;
	t_portal			*rportal;
}						t_game;

typedef struct			s_g_render
{
	int					column;
	int					current_top;
}						t_g_render;

typedef struct			s_env
{
	t_mlx				*mlx;
	t_mlx_img			*screen;
	t_mlx_img			*minimap;
	t_pplane			*pplane;
	t_game				*game;
	t_input				*input;
	t_g_render			*g_render;
	int					ints[10];
}						t_env;

//LOL
void					draw_wall(t_wall *wall, int color, t_env *e);
//
t_env					*init_env(void);
void					init_render_struct(double ray_angle, double ref_angle,
						t_point2 *ref_pos, t_render *r);
void					set_render_struct_ray_angle(double ray_angle,
						t_render *r);

t_map					*load_map(char *map);

void					process(t_env *e);

void					set_ray(double angle, t_segment2 *ray);

void					render_minimap(t_env *e);
void					render_minimap_ray(t_segment2 *ray, t_env *e);

int						cast_to_sector_walls(t_segment2 *ray, t_sector *sector,
						t_w_intersection *w, t_sort *s);
void					process_walls_intersections(int nb_walls, t_sector *sector,
						t_render *r, t_env *e);

void					render(t_env *e);
void					render_wall(t_w_intersection *intersection, t_env *e);
void					render_sector(t_sector *sector, t_render *r, t_env *env);
t_sector				*next_sector(t_wall *wall, t_sector *c_sector,
						t_sector *sectors);
void					render_step_up(t_sector *from, t_sector *to,
						t_w_intersection *w_inter, t_env *e);
void					render_floor(int from, t_sector *sector, t_env *e);
void					render_through_portal(t_portal *from, t_portal *to,
						t_render *r, t_env *e);

double					get_z_in_sector(t_sector *sector, double x, double y);

int						point_in_portal(t_portal *portal, t_point2 *p);
t_portal				*the_other_portal(t_portal *from, t_env *e);
void					get_portal_new_pos(t_portal *from, t_point2 *inter,
						t_portal *to, t_point2 *new_pos);

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

double					qs_walls_cmp(void *w1, void *w2);

#endif
