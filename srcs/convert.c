/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:37 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/18 15:51:10 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIBFT/libft.h"
#include "../incl/error_msg.h"
#include "../incl/fdf.h"
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
	map->order_arr = (int *)ft_memalloc(arr_size);
	map->colors_arr = (int *)ft_memalloc(arr_size);
	if (!(map->order_arr) || !(map->colors_arr))
		terminate(ERR_CONV_TO_ARR, NULL);
	i = map->width * map->height - 1;
	order = pop(order_stack);
	while (order && i >= 0)
	{
		map->order_arr[i] = order->z;
		map->colors_arr[i] = order->color;
		if (order->z > map->z_max)
			map->z_max = order->z;
		if (order->z < map->z_min)
			map->z_min = order->z;
		i--;
		free(order);
		order = pop(order_stack);
	}
	map->z_range = map->z_max - map->z_min;
}
