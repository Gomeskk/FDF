/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:05:58 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/14 14:17:12 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIBFT/libft.h"
#include "../incl/error_msg.h"
#include "../incl/fdf.h"
#include <stdlib.h>

/*
** Free array that was returned by ft_split()
*/

static void	free_strsplit_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_strdel(char **as)
{
	if (as && *as)
	{
		free(*as);
		*as = NULL;
	}
}
/**
 * ft_strdel
	- Frees a dynamically allocated string and sets its pointer to NULL.
 * @as: A double pointer to the string that needs to be freed.
 *
 * This function checks if the pointer to the string (as) and the string itself
 * are not NULL. If they are valid, it frees the memory allocated for the string
 * and sets the pointer to NULL to avoid dangling pointers and potential
 * memory access errors in future use.
 */

/*
** Create t_coord_val element with information about z and color value
*/

static t_order_val	*new_coord(char *s)
{
	t_order_val	*coord;
	char		**parts;

	coord = (t_order_val *)ft_memalloc(sizeof(t_order_val));
	parts = ft_split(s, ',');
	if (!(coord))
		terminate(ERR_MAP_READING);
	if (!(parts))
		terminate("1");
	if (!ft_isnumber(parts[0], 10))
		terminate("2");
	if (parts[1] && !ft_isnumber(parts[1], 16))
		terminate("3");
	coord->z = ft_atoi(parts[0]);
	if (parts[1])
		coord->color = ft_atoi_base(parts[1], 16);
	else
		coord->color = -1;
	coord->next = NULL;
	free_strsplit_arr(parts);
	return (coord);
}

/*
** Get coordinate values from line, create t_coord_val elements
** and them add to stack
*/

static void	parse_line(char **coords_line, t_order_val **coords_stack,
		t_map *map)
{
	int	width;

	width = 0;
	while (*coords_line)
	{
		push(coords_stack, new_coord(*(coords_line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		terminate(ERR_MAP);
}

/*
** Read map from file line by line
*/

int	read_map(const int fd, t_order_val **coords_stack, t_map *map)
{
	char	*line;
	char	*result;
	char	**coords_line;

	result = get_next_line(fd, &line);
	while (result != NULL)
	{
		coords_line = ft_split(line, ' ');
		if (!(coords_line))
			terminate(ERR_MAP_READING);
		parse_line(coords_line, coords_stack, map);
		free_strsplit_arr(coords_line);
		ft_strdel(&line);
		map->height++;
		result = get_next_line(fd, &line);
	}
	if (!(*coords_stack))
		terminate(ERR_MAP);
	return (0);
}
