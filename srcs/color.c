/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:42:13 by jayi              #+#    #+#             */
/*   Updated: 2022/02/05 14:48:26 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "utility.h"
#include "define.h"

int	get_transparent_color(int color1, int color2)
{
	t_color	color_1;
	t_color	color_2;

	color_1.color = color1;
	color_2.color = color2;
	color_1.bit.r = color_1.bit.r / 2 + color_2.bit.r / 2;
	color_1.bit.g = color_1.bit.g / 2 + color_2.bit.g / 2;
	color_1.bit.b = color_1.bit.b / 2 + color_2.bit.b / 2;
	return (color_1.color);
}

int	get_transparent_red_color(int color1, int color2)
{
	t_color	color_1;
	t_color	color_2;

	color_1.color = color1;
	color_2.color = color2;
	color_1.bit.r = 255;
	color_1.bit.g = color_1.bit.g / 2 + color_2.bit.g / 2;
	color_1.bit.b = color_1.bit.b / 2 + color_2.bit.b / 2;
	return (color_1.color);
}
