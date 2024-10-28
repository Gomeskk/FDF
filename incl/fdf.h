/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:14:36 by joafaust          #+#    #+#             */
/*   Updated: 2024/10/28 12:20:26 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../LIBFT/libft.h"
# include "../minilibx-linux/mlx.h"
# include "colors.h"
# include "keycode_linux.h"
# include <fcntl.h>
# include <stdbool.h>

# define TITLE "FDF"
# define PI 3.14159265359
# define HELP_COLOR WHITE
# define HEIGHT 1400
# define WIDTH 2000
# define FRAME_WIDTH 200
# define MAX_UNIT_SIZE 20

/*
** macros used for still inputs
*/

# define KEYPRESS 2
# define KEYRELEASE 3
/* # define KEYPRESSMASK (1L << 0) tenho depois de tirar isto de comment
# define KEYRELEASEMASK (1L << 1) */

/*
** more awesome colors
*/

# define PINK 0xcc00cc
# define BLACK 0x000000
# define MARINE_BLUE 0x000099
# define CRIMSON_RED 0x990033
# define NICE_BLUE 0x6666ff
# define DARK_TEAL 0x33cccc
# define GREY 0xd3d3d3
# define BROWN 0x996633
# define TRANSPARENT 0x77000000

/*
** a is alpha(transparency) r = red g = green b = blue
** argb stores inside .x the color used to draw the pixel
** and in y the required incrementation
*/

#endif