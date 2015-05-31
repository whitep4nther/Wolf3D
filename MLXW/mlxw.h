/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 23:15:10 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 15:31:28 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXW_H
# define MLXW_H

# include <mlx.h>
# include <stdlib.h>

# define KEY_ESCAPE			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_UP				126

# define DL_X0				mlx_i[0]
# define DL_Y0				mlx_i[1]
# define DL_X1				mlx_i[2]
# define DL_Y1				mlx_i[3]
# define DL_DX				mlx_i[4]
# define DL_DY				mlx_i[5]
# define DL_E				mlx_i[6]
# define DL_X				mlx_i[7]
# define DL_Y				mlx_i[8]
# define LINE_COLOR			mlx_i[9]

# define D_HACK1			if (DL_DX>0){if((DL_DY=DL_Y1-DL_Y0)!=0){
# define D_HACK2			if(DL_DY>0){octant_1_2(m);}else{octant_7_8(m);}
# define D_HACK3			}else{horizontal_line(m);}}

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
	int						mlx_i[10];
}							t_mlx;

typedef struct				s_mlx_img
{
	void					*img;
	char					*img_data;
	int						img_bpp;
	int						img_size_line;
	int						img_endian;
	int						height;
	int						width;
}							t_mlx_img;

t_mlx_img					*mlx_new_image_struct(void *mlx, int width, int height);

void						mlx_put_pixel_to_img(int x, int y, int color, t_mlx_img *img);
void						mlx_clear_image(int color, t_mlx_img *img);
void						mlx_clear_half_image(int color, t_mlx_img *img);
int							mlx_get_blended_color(unsigned char *color1,
							unsigned char *color2);

void						setup_x1_y1_x2(int x1, int y1, int x2, int mlx_i[10]);
void						setup_y2_color(int y2, int color, int mlx_i[10]);
void						draw_line_to_img(t_mlx_img *img, int mlx_i[10]);

void						vertical_line(t_mlx_img *img, int mlx_i[10]);
void						horizontal_line(t_mlx_img *img, int mlx_i[10]);
void						octant_1_2(t_mlx_img *img, int mlx_i[10]);
void						octant_2(t_mlx_img *img, int mlx_i[10]);
void						octant_3_4(t_mlx_img *img, int mlx_i[10]);
void						octant_3(t_mlx_img *img, int mlx_i[10]);
void						octant_5_6(t_mlx_img *img, int mlx_i[10]);
void						octant_6(t_mlx_img *img, int mlx_i[10]);
void						octant_7_8(t_mlx_img *img, int mlx_i[10]);
void						octant_7(t_mlx_img *img, int mlx_i[10]);

#endif
