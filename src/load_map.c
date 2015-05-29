/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 03:44:04 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 01:20:59 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static t_list	*free_and_advance(t_list *file)
{
	t_list		*tmp;

	tmp = file->next;
	free(file->content);
	free(file);
	return (tmp);
}
/*
static void		print_map(t_map *map)
{
	int			i;
	int			j;

	i = -1;
	printf("=== PRINTING MAP ===\n");
	printf("NB sectors : %d\n", map->nb_sectors);
	printf("NB walls : %d\n", map->nb_walls);
	printf("\n");
	while (++i < map->nb_sectors)
	{
		printf("Sector %d\n", i);
		printf("-- reference: x %lf, y %lf, x %lf\n", map->sectors[i].reference.x, map->sectors[i].reference.y, map->sectors[i].reference.z);
		printf("-- z1 %lf, z2 %lf\n", map->sectors[i].z1, map->sectors[i].z2);
		printf("----- WALLS LIST (%d)\n", map->sectors[i].nb_walls);
		j = -1;
		while (++j < map->sectors[i].nb_walls)
			printf("%d, \n", map->sectors[i].walls[j]);
		printf("\n");
	}
	i = -1;
	printf("\n");
	while (++i < map->nb_walls)
	{
		printf("Wall %d\n", i);
		printf("-- seg x1 %lf, y1 %lf, x2 %lf, y2 %lf\n",map->walls[i].seg.points[0].x, map->walls[i].seg.points[0].y, map->walls[i].seg.points[1].x, map->walls[i].seg.points[1].y);
		printf("-- height %d\n", map->walls[i].height);
		printf("-- is_portal %d\n", map->walls[i].is_portal);
		printf("-- sectors_id %d and %d\n", map->walls[i].sectors_id[0], map->walls[i].sectors_id[1]);
		printf("\n");
	}
}
*/
static t_list	*load_walls(t_list *file, t_map *map, int nb)
{
	int			i;
	char		**split;

	i = -1;
	while (++i < nb)
	{
		map->walls[i].id = i;
		map->walls[i].column_rendered = -1;
		split = ft_strsplit(file->content, ' ');
		map->walls[i].seg = fill_segment2(ft_atoi(split[0]),
			ft_atoi(split[1]), ft_atoi(split[2]), ft_atoi(split[3]));
		file = free_and_advance(file);
		ft_free_str_tab(split);
		map->walls[i].height = ft_atoi(file->content);
		file = free_and_advance(file);
		map->walls[i].is_portal = ft_atoi(file->content);
		file = free_and_advance(file);
		split = ft_strsplit(file->content, ' ');
		map->walls[i].sectors_id[0] = ft_atoi(split[0]);
		map->walls[i].sectors_id[1] = ft_atoi(split[1]);
		file = free_and_advance(file);
		ft_free_str_tab(split);
	}
	return (file);
}

static t_list	*load_sectors(t_list *file, t_map *map, int nb)
{
	int			i;
	int			j;
	int			tmp;
	char		**split;

	i = -1;
	while (++i < nb)
	{
		map->sectors[i].id = i;
		split = ft_strsplit(file->content, ' ');
		map->sectors[i].reference.x = ft_atoi(split[0]);
		map->sectors[i].reference.y = ft_atoi(split[1]);
		map->sectors[i].reference.z = ft_atoi(split[2]);
		file = free_and_advance(file);
		ft_free_str_tab(split);
		split = ft_strsplit(file->content, ' ');
		map->sectors[i].z1 = ft_atoi(split[0]) / 1000.0;
		map->sectors[i].z2 = ft_atoi(split[1]) / 1000.0;
		file = free_and_advance(file);
		ft_free_str_tab(split);
		split = ft_strsplit(file->content, ' ');
		tmp = ft_len_str_tab(split);
		map->sectors[i].nb_walls = tmp;
		map->sectors[i].walls = (int*)malloc(sizeof(int) * tmp);
		j = -1;
		while (++j < tmp)
			map->sectors[i].walls[j] = ft_atoi(split[j]);
		file = free_and_advance(file);
		ft_free_str_tab(split);
	}
	return (file);
}

static void		parse_map(t_list *file, t_map *map)
{
	map->nb_sectors = ft_atoi(file->content);
	file = free_and_advance(file);
	map->nb_walls = ft_atoi(file->content);
	file = free_and_advance(file);
	map->sectors = (t_sector*)malloc(sizeof(t_sector) * map->nb_sectors);
	map->walls = (t_wall*)malloc(sizeof(t_wall) * map->nb_walls);
	file = load_sectors(file, map, map->nb_sectors);
	file = load_walls(file, map, map->nb_walls);
	(void)map;
}

t_map			*load_map(char *path)
{
	int			fd;
	char		*line;
	t_list		*file;
	t_map		*map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": map can't be opened", 2);
		exit(0);
	}
	file = NULL;
	while (get_next_line(fd, &line) > 0)
		ft_push_back_list(ft_new_list(line), &file);
	map = (t_map*)malloc(sizeof(t_map));
	parse_map(file, map);
	return (map);
}
