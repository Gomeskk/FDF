/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:37 by joafaust          #+#    #+#             */
/*   Updated: 2024/10/29 00:54:50 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_msg.h"
#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

/*
** Convert stack with t_order_val elements (contains z value and color value)
** to array with z values and array with color values.
*/

void	stack_to_arrays(t_order_val **order_stack, t_map *map)
{
	t_order_val	*order;
	ssize_t		i;
	size_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	if (!(map->order_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_CONV_TO_ARR);
	if (!(map->colors_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_CONV_TO_ARR);
	i = map->width * map->height - 1;
	while ((order = pop(order_stack)) && i >= 0)
	{
		map->order_arr[i] = order->z;
		map->colors_arr[i] = order->color;
		if (order->z > map->z_max)
			map->z_max = order->z;
		if (order->z < map->z_min)
			map->z_min = order->z;
		i--;
		free(order);
	}
	map->z_range = map->z_max - map->z_min;
}
