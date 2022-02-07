/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:16:35 by jayi              #+#    #+#             */
/*   Updated: 2022/02/07 19:11:55 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "define.h"
#include "vector.h"
#include "sprite.h"

static void	draw_sprite_color(t_game_model *g, t_sprite_value *v, t_sprite *sp)
{
	v->y = v->draw_s_y;
	while (v->y < v->draw_e_y)
	{
		v->d = ((v->y - v->v_m_sc) * 2 - g->sc_size.y + v->sp_h) << 7;
		v->tex_y = ((v->d * TEX_HEIGHT) / v->sp_h) >> 8;
		v->color = g->textures[sp->t_id][TEX_WIDTH * v->tex_y + v->tex_x];
		if ((v->color & 0x00FFFFFF) != 0)
		{
			v->v_y = v->y + g->pl.pos.z;
			if (v->v_y > 0 && v->v_y < g->sc_size.y)
				g->sc_data_2d[v->v_y][v->st] = v->color;
		}
		++v->y;
	}
}

static void	calc_sprite_color(t_game_model *g,
								t_sprite_value *v, t_sprite *sp)
{
	v->st = v->draw_s_x;
	while (v->st < v->draw_e_x)
	{
		v->tex_x = (int)((v->st - (-v->sp_w / 2 + v->sp_s_x)) * \
		TEX_WIDTH / v->sp_w);
		if (v->tr_y > 0 && v->st > 0 && \
		v->st < g->sc_size.x && v->tr_y < g->z_buf[v->st])
		{
			draw_sprite_color(g, v, sp);
		}
		++v->st;
	}
}

static void	init_sprite(t_game_model *g, t_sprite_value *v, t_sprite *sp)
{
	v->sp_x = sp->pos.x - g->pl.pos.x;
	v->sp_y = sp->pos.y - g->pl.pos.y;
	v->inv_det = 1.0 / (g->cam.x * g->pl.dir.y - g->pl.dir.x * g->cam.y);
	v->tr_x = v->inv_det * (g->pl.dir.y * v->sp_x - g->pl.dir.x * v->sp_y);
	v->tr_y = v->inv_det * (-g->cam.y * v->sp_x + g->cam.x * v->sp_y);
	v->sp_s_x = (int)((g->sc_size.x / 2) * (1 + v->tr_x / v->tr_y));
	v->v_m_sc = (int)(sp->v_move / v->tr_y);
	v->sp_h = (int)fabs((g->sc_size.y / v->tr_y) / sp->v_div);
}

static void	calc_sprite_size(t_game_model *g, t_sprite_value *v, t_sprite *sp)
{
	v->draw_s_y = -v->sp_h / 2 + g->sc_size.y / 2 + v->v_m_sc;
	if (v->draw_s_y < 0)
		v->draw_s_y = 0;
	v->draw_e_y = v->sp_h / 2 + g->sc_size.y / 2 + v->v_m_sc;
	if (v->draw_e_y >= g->sc_size.y)
		v->draw_e_y = g->sc_size.y - 1;
	v->sp_w = (int)fabs((g->sc_size.y / v->tr_y) / sp->u_div);
	v->draw_s_x = -v->sp_w / 2 + v->sp_s_x;
	if (v->draw_s_x < 0)
		v->draw_s_x = 0;
	v->draw_e_x = v->sp_w / 2 + v->sp_s_x;
	if (v->draw_e_x >= g->sc_size.x)
		v->draw_e_x = g->sc_size.x - 1;
}

void	draw_sprite(t_game_model *g)
{
	t_node			*cur;
	t_sprite		*sp;
	t_sprite_value	v;

	cur = g->sprites;
	calc_dist(g);
	sort_sprite(g);
	while (cur != NULL)
	{
		sp = cur->value;
		init_sprite(g, &v, sp);
		calc_sprite_size(g, &v, sp);
		calc_sprite_color(g, &v, sp);
		cur = cur->next;
	}
}
