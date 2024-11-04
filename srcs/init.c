/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:51:15 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/04 14:29:45 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_msg.h"
#include "fdf.h"
#include "libft.h"
#include "mlx.h"

/*
** Initialize t_map element
*/

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	if (!(map))
		terminate(ERR_MAP_INIT);
	map->width = 0;
	map->height = 0;
	map->order_arr = NULL;
	map->colors_arr = NULL;
	map->z_min = FT_INT_MAX;
	map->z_max = FT_INT_MIN;
	map->z_range = 0;
	return (map);
}

/*
** Initialize t_fdf element
*/

t_fdf	*fdf_init(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse));
	if (!(fdf))
		terminate(ERR_FDF_INIT);
	if (!(fdf->mlx))
		terminate(ERR_FDF_INIT);
	if (!(fdf->win))
		terminate(ERR_FDF_INIT);
	if (!(fdf->img))
		terminate(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_p_pix),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	if (!(fdf->mouse))
		terminate(ERR_FDF_INIT);
	return (fdf);
}

/*
** Initialize t_camera element
*/

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)ft_memalloc(sizeof(t_camera));
	if (!(camera))
		terminate(ERR_CAMERA_INIT);
	camera->zoom = FT_MIN((WIDTH - MENU_WIDTH) / fdf->map->width / 2, HEIGHT
			/ fdf->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_div = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}
