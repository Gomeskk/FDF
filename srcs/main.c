/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:30:38 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/21 15:38:56 by joafaust         ###   ########.fr       */
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
	t_fdf		*fdf;
	t_order_val	*orders_stack;

	if (argc != 2)
		terminate(ERR_USAGE, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		terminate(ERR_MAP, NULL);
	map = map_init();
	orders_stack = NULL;
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
	return (0);
}
