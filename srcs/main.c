/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:30:38 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/10 15:53:40 by joafaust         ###   ########.fr       */
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

	errno = 0;
	orders_stack = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY) >= 0;
		if (!(fd))
			terminate(ERR_MAP);
		map = map_init();
		if (read_map(fd, &orders_stack, map) == -1)
			terminate(ERR_MAP_READING);
		fdf = fdf_init(map);
		stack_to_arrays(&orders_stack, map);
		fdf->cam = camera_init(fdf);
		draw(fdf->map, fdf);
		set_controls(fdf);
		mlx_loop(fdf->mlx);
	}
	terminate(ERR_USAGE);
	return (0);
}
