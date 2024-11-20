/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:30:38 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/20 21:52:36 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/error_msg.h"
#include "../incl/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int			fd;
	t_map		*map;
	t_order_val	*orders_stack;
	t_fdf		*fdf;

	orders_stack = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(fd))
			terminate(ERR_MAP, NULL);
		map = map_init();
		if (read_map(fd, &orders_stack, map) == -1)
		{
			free_pop(&orders_stack);
			terminate(ERR_MAP_READING, fdf_init(map));
		}
		fdf = fdf_init(map);
		stack_to_arrays(&orders_stack, map);
		fdf->cam = camera_init(fdf);
		draw(fdf->map, fdf);
		set_controls(fdf);
		mlx_loop(fdf->mlx);
	}
	terminate(ERR_USAGE, NULL);
	return (0);
}
