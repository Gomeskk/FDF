/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:20:20 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/14 21:44:06 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

/*
** Close window with 'X'
*/

int	ft_close(void *param)
{
	(void)param;
	exit(0);
}

int	loop_draw(t_fdf *fdf)
{
	draw(fdf->map, fdf);
	return (0);
}

/*
** Connect functions-controllers to window
*/

void	set_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, (1L << 0), key_press, fdf);
	mlx_hook(fdf->win, 17, 0, ft_close, fdf);
	mlx_hook(fdf->win, 4, (1L << 2), mouse_press, fdf);
	mlx_hook(fdf->win, 5, (1L << 3), mouse_release, fdf);
	mlx_hook(fdf->win, 6, (1L << 6), mouse_move, fdf);
	mlx_loop_hook(fdf->mlx, loop_draw, fdf);
}
