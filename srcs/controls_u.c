/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:34 by joafaust          #+#    #+#             */
/*   Updated: 2024/10/28 23:36:14 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/keycode_linux.h"

/*
** Zoom map
*/

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS || key == MOUSE_SCROLL_UP)
		fdf->cam->zoom++;
	else if (key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS
		|| key == MOUSE_SCROLL_DOWN)
		fdf->cam->zoom--;
	if (fdf->cam->zoom < 1)
		fdf->cam->zoom = 1;
	draw(fdf->map, fdf);
}

/*
** Move map
*/

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT)
		fdf->cam->x_offset -= 10;
	else if (key == ARROW_RIGHT)
		fdf->cam->x_offset += 10;
	else if (key == ARROW_UP)
		fdf->cam->y_offset -= 10;
	else
		fdf->cam->y_offset += 10;
	draw(fdf->map, fdf);
}

/*
** Rotate map
*/

void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		fdf->cam->alpha += 0.05;
	else if (key == NUM_PAD_8 || key == MAIN_PAD_8)
		fdf->cam->alpha -= 0.05;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		fdf->cam->beta -= 0.05;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		fdf->cam->beta += 0.05;
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1 || key == NUM_PAD_3
		|| key == MAIN_PAD_3)
		fdf->cam->gamma += 0.05;
	else if (key == NUM_PAD_7 || key == MAIN_PAD_7 || key == NUM_PAD_9
		|| key == MAIN_PAD_9)
		fdf->cam->gamma -= 0.05;
	draw(fdf->map, fdf);
}

/*
** Change z value. Make map more flatten
*/

void	compress(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_LESS)
		fdf->cam->z_div -= 0.1;
	else if (key == MAIN_PAD_MORE)
		fdf->cam->z_div += 0.1;
	if (fdf->cam->z_div < 0.1)
		fdf->cam->z_div = 0.1;
	else if (fdf->cam->z_div > 10)
		fdf->cam->z_div = 10;
	draw(fdf->map, fdf);
}

/*
** Change projection type
*/

void	change_projection(int key, t_fdf *fdf)
{
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
	if (key == MAIN_PAD_I)
		fdf->cam->projection = ISO;
	else if (key == MAIN_PAD_P)
		fdf->cam->projection = PARALLEL;
	draw(fdf->map, fdf);
}
