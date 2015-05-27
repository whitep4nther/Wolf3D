/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 23:15:10 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/27 20:05:07 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXW_H
# define MLXW_H

# include <mlx.h>
# include <stdlib.h>

# define WIN_WIDTH			1400
# define WIN_HEIGHT			1000

# define KEY_ESCAPE			53
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_UP				126

# define DL_X0				m->i[0]
# define DL_Y0				m->i[1]
# define DL_X1				m->i[2]
# define DL_Y1				m->i[3]
# define DL_DX				m->i[4]
# define DL_DY				m->i[5]
# define DL_E				m->i[6]
# define DL_X				m->i[7]
# define DL_Y				m->i[8]
# define LINE_COLOR			m->i[9]

# define D_HACK1			if (DL_DX>0){if((DL_DY=DL_Y1-DL_Y0)!=0){
# define D_HACK2			if(DL_DY>0){octant_1_2(m);}else{octant_7_8(m);}
# define D_HACK3			}else{horizontal_line(m);}}

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*img_data;
	int						img_bpp;
	int						img_size_line;
	int						img_endian;
	int						i[10];
}							t_mlx;

void						mlx_put_pixel_to_img(int x, int y, int color, t_mlx *m);

void						setup_x1_y1_x2(int x1, int y1, int x2, t_mlx *m);
void						setup_y2_color(int y2, int color, t_mlx *m);
void						draw_line(t_mlx *m);

void						vertical_line(t_mlx *m);
void						horizontal_line(t_mlx *m);
void						octant_1_2(t_mlx *m);
void						octant_2(t_mlx *m);
void						octant_3_4(t_mlx *m);
void						octant_3(t_mlx *m);
void						octant_5_6(t_mlx *m);
void						octant_6(t_mlx *m);
void						octant_7_8(t_mlx *m);
void						octant_7(t_mlx *m);

#endif
