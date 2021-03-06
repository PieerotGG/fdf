/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:08:21 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/09 18:29:55 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "map.h"
# include "ft_args.h"
# include "ft_mlx/window.h"
# include "ft_math/matrix.h"
# include "ft_mlx/camera.h"
# include "ft_mlx/camera.h"
# include "dirwin.h"
# include <sys/types.h>
# include <dirent.h>
# include "config.h"
# include <unistd.h>
# include "ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# define RET_OK 0
# define RET_ERROR_PARSE -1
# define RET_ERROR_INIT -2
# define RET_ERROR_ARGS -3
# define RET_ERROR_USAGE -4
# define RET_ERROR_500 500
# define DIRMODE_FLAG "-d"
# define THEMES_DIR "themes"
# define THEMES_EXT "theme"

typedef int			t_ret;

typedef enum		e_mapmode
{
					SINGLE,
					FOLDER,
					UNDEFINED,
}					t_mapmode;

typedef struct		s_theme
{
	t_color			canvas_color;
	t_color			ui_background;
	t_color			line_color;
	t_color			text_color;
}					t_theme;

typedef struct		s_themes
{
	size_t			len;
	t_theme			themes[];
}					t_themes;

typedef struct		s_fdf_state
{
	t_camera		*camera;
	t_matrix44_d	mat_pofin;
	t_point2d		last;
	t_bool			motion_focus;
	t_theme			theme;
	size_t			selected_theme;
}					t_fdf_state;

typedef struct		s_state
{
	t_dirwin_state	*dirwin;
	t_fdf_state		*fdf;
	t_config_state	*config;
}					t_state;

typedef struct		s_fdf
{
	t_map			*map;
	t_params		*params;
	t_mapmode		mapmode;
	DIR				*dir;
	int				fd;
	void			*mlx_ptr;
	t_window		*window;
	t_window		*dirwin;
	t_themes		*themes;
	t_state			*state;
	size_t			window_count;
}					t_fdf;

t_ret				parse(t_fdf *fdf);

void				assert(t_ret ret, const char *msg);

t_ret				fdf_selection_window(t_fdf *fdf, t_window *dest);

int					fdf_selection_window_render(t_window *win, void *s);

char				**fdf_selection_get_files(t_fdf *fdf);

t_ret				fdf_window_init(t_fdf *fdf, t_window *dest);

int					fdf_window_render(t_window *win, void *s);

t_container			*fdf_layout(t_fdf *fdf);

t_container			*dirwin_layout(t_fdf *fdf);

t_image_carry		*fdf_image(t_canvas *canvas, void *s, t_image_carry *carry);

void				fdf_press_w(void *s);

void				fdf_press_a(void *s);

void				fdf_press_s(void *s);

void				fdf_press_d(void *s);

void				fdf_press_t(void *s);

void				fdf_press_arrow_left(void *s);

void				fdf_press_arrow_up(void *s);

void				fdf_press_arrow_right(void *s);

void				fdf_press_arrow_down(void *s);

void				fdf_motion(int x, int y, void *s);

void				fdf_click(t_mouse_btn btn, int id, void *s);

void				add_hooks(t_canvas *canvas, void *s);

t_ret				load_themes(t_fdf *fdf);

t_ret				fdf_init_config(t_fdf *fdf);

t_container			*fdf_config_layout(t_fdf *fdf);

void				fdf_next_theme(t_fdf *fdf);

void				fdf_prev_theme(t_fdf *fdf);

#endif
