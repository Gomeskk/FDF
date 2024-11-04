/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:14:36 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/04 16:24:48 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define HEIGHT 1080
# define WIDTH 1920
# define MENU_WIDTH 250

# define FT_UINT_MAX 4294967295U // Assuming unsigned int is 32 bits
# define FT_INT_MAX 2147483647   // Maximum positive value for a signed int
# define FT_INT_MIN -2147483648  // Minimum value for a signed int

static inline int	FT_MIN(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

static inline int	FT_MAX(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

typedef enum s_bool
{
	false,
	true
}						t_bool;

typedef enum s_projection
{
	ISO,
	PARALLEL
}						t_projection;

typedef struct s_order_val
{
	int					z;
	int					color;
	struct s_order_val	*next;
}						t_order_val;

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct s_camera
{
	t_projection		projection;
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_div;
	int					x_offset;
	int					y_offset;
}						t_camera;

typedef struct s_map
{
	int					width;
	int					height;
	int					*order_arr;
	int					*colors_arr;
	int					z_min;
	int					z_max;
	int					z_range;
}						t_map;

typedef struct s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_p_pix;
	int					size_line;
	int					endian;
	t_camera			*cam;
	t_map				*map;
	t_mouse				*mouse;
}						t_fdf;
int						read_map(const int fd, t_order_val **orders_stack,
							t_map *map);

void					push(t_order_val **orders_stack, t_order_val *new);

t_order_val				*pop(t_order_val **orders_stack);

t_map					*map_init(void);

t_fdf					*fdf_init(t_map *map);

t_camera				*camera_init(t_fdf *fdf);

void					stack_to_arrays(t_order_val **orders_stack, t_map *map);

void					draw(t_map *map, t_fdf *fdf);

int						get_def_color(int z, t_map *map);

int						get_li(int start, int end, double percentage);

int						get_color(t_point current, t_point start, t_point end,
							t_point delta);

t_point					project(t_point p, t_fdf *fdf);

void					print_menu(t_fdf *fdf);

int						ft_close(void *param);

void					setup_controls(t_fdf *fdf);

int						key_press(int key, void *param);

int						mouse_press(int button, int x, int y, void *param);

int						mouse_release(int button, int x, int y, void *param);

int						mouse_move(int x, int y, void *param);

void					zoom(int key, t_fdf *fdf);

void					move(int key, t_fdf *fdf);

void					rotate(int key, t_fdf *fdf);

void					compress(int key, t_fdf *fdf);

void					change_projection(int key, t_fdf *fdf);

t_bool					ft_isnumber(char *str, int base);

int						ft_atoi_base(const char *str, int base);

double					percent(int start, int end, int current);

void					terminate(char *s);

int						get_index(int x, int y, int width);

t_point					n_point(int x, int y, t_map *map);

#endif