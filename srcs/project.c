/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:34:42 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/10 15:48:57 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "math.h"

/*
** Rotate coordinate by x axis
*/

static void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

/*
** Rotate coordinate by y axis
*/

static void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

/*
** Rotate coordinate by z axis
*/

static void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

/*
** Convert coordinate to iso projection
*/

static void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

/*
** Project coordinate to 2D plane
*/

t_point	project(t_point p, t_fdf *fdf)
{
	p.x *= fdf->cam->zoom;
	p.y *= fdf->cam->zoom;
	p.z *= fdf->cam->zoom / fdf->cam->z_div;
	p.x -= (fdf->map->width * fdf->cam->zoom) / 2;
	p.y -= (fdf->map->height * fdf->cam->zoom) / 2;
	rotate_x(&p.y, &p.z, fdf->cam->alpha);
	rotate_y(&p.x, &p.z, fdf->cam->beta);
	rotate_z(&p.x, &p.y, fdf->cam->gamma);
	if (fdf->cam->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += (WIDTH - MENU_WIDTH) / 2 + fdf->cam->x_offset + MENU_WIDTH;
	p.y += (HEIGHT + fdf->map->height * fdf->cam->zoom) / 2
		+ fdf->cam->y_offset;
	return (p);
}
