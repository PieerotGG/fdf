/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:22:29 by pguthaus          #+#    #+#             */
/*   Updated: 2019/04/01 20:14:22 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_mlx/window.h"
#include <stdio.h>

static t_fdf_state		*fdf_state(t_fdf *fdf)
{
	t_fdf_state			*state;

	(void)fdf;
	if (!(state = (t_fdf_state *)malloc(sizeof(t_fdf_state))))
		return (NULL);
	state->camera = mlx_init_camera(ft_init3_vec3_d(0, 0, 0));
	state->last = POS(-42, -42);
	state->motion_focus = FALSE;
	return (state);
}

t_ret					fdf_window_init(t_fdf *fdf, t_window *dest)
{
	if (!(fdf->state->fdf = fdf_state(fdf)))
		return (RET_ERROR_500);
	dest->body = fdf_layout(fdf);
	dest->should_render_every_frame = FALSE;
	return (RET_OK);
}
