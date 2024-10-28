/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:31 by joafaust          #+#    #+#             */
/*   Updated: 2024/10/28 14:17:15 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include <math.h>

/*
** creates a new image
*/

void		ft_create_image(t_image *img)
{
	img->image ? mlx_destroy_image(img->mlx, img->image) : 0;
	img->w ? mlx_clear_window(img->mlx, img->w) : 0;
	img->image = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->data_address = mlx_get_data_addr(img->image, &(img->bpp),
			&(img->line_size), &(img->endian));
}
