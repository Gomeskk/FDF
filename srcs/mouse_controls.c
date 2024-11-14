/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:26:03 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/14 20:11:27 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../incl/keycode_linux.h"

/*
** Mouse Press Handler
**
** Handles mouse button presses. If the scroll wheel is used,
** the `zoom` function is called. If the left mouse button
** is pressed, the `is_pressed` flag is set to true.
*/

int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = true;
	return (0);
}

/*
** Mouse Release Handler
**
** Handles mouse button releases. Sets the `is_pressed` flag
** to false.
*/

int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = false;
	return (0);
}

/*
** Mouse Move Handler
**
** Handles mouse movement. If the left mouse button is pressed,
** the camera's `beta` and `alpha` angles are updated based on
** the mouse movement, and the scene is redrawn.
*/

int	mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->cam->beta += (x - fdf->mouse->previous_x) * 0.002;
		fdf->cam->alpha += (y - fdf->mouse->previous_y) * 0.002;
	}
	return (0);
}
