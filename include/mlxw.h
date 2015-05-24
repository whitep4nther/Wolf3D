/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 03:00:15 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/24 05:44:21 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXW_H
# define MLXW_H

# include <stdlib.h>
# include <mlx.h>

# define KEY_ESCAPE		53

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
}					t_mlx;

#endif
