/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:59:19 by jayi              #+#    #+#             */
/*   Updated: 2022/02/05 14:55:53 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"
#include "color.h"

int	get_mix_color(int dst_color, int src_color, double rate)
{
	t_color	dst;
	t_color	src;

	if (rate < 0 || rate > 1)
		return (0);
	dst.color = dst_color;
	src.color = src_color;
	dst.bit.r = dst.bit.r * rate + src.bit.r * (1 - rate);
	dst.bit.g = dst.bit.g * rate + src.bit.g * (1 - rate);
	dst.bit.b = dst.bit.b * rate + src.bit.b * (1 - rate);
	return (dst.color);
}

void	draw_square(t_game_model *g, int x, int y, int width, int color)
{
	int	count_x;
	int	count_y;

	count_x = width;
	count_y = width;
	while (count_x > 0)
	{
		count_y = width;
		while (count_y > 0)
		{
			g->sc_data_2d[y + count_y][x + count_x] = \
			get_mix_color(g->sc_data_2d[y + count_y][x + count_x], color, 0.5);
			--count_y;
		}
		--count_x;
	}
}

void	draw_minimap(t_game_model *g, int start_x, int start_y)
{
	const int	width = 15;
	int			map_x;
	int			map_y;
	int			gap_x;
	int			gap_y;

	map_x = g->pl.pos.x;
	map_y = g->pl.pos.y;
	gap_x = -100;
	gap_y = -100;
	while (gap_x <= 100)
	{
		if (map_x + gap_x >= 0 && map_x + gap_x < g->map_x)
		{
			gap_y = -100;
			while (gap_y <= 100)
			{
				if (map_y + gap_y >= 0 && map_y + gap_y < g->map_y)
				{
					if (g->map_data[map_x + gap_x][map_y + gap_y] == 1)
						draw_square(g, start_x + (map_x + gap_x) * width, \
						start_y + (map_y + gap_y) * width, width, 0xffffff);
					if (g->map_data[map_x + gap_x][map_y + gap_y] == 0)
						draw_square(g, start_x + (map_x + gap_x) * width, \
						start_y + (map_y + gap_y) * width, width, 0x000000);
				}
				++gap_y;
			}
		}
		++gap_x;
	}
	draw_square(g, map_x * width, map_y * width, width, 0xff0000);
}
