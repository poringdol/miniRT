/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:12:54 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 07:20:18 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** outputBlue = (inputRed * .272) + (inputGreen *.534) + (inputBlue * .131)
** outputGreen = (inputRed * .349) + (inputGreen *.686) + (inputBlue * .168)
** outputRed = (inputRed * .393) + (inputGreen *.769) + (inputBlue * .189)
*/

int	sepia(void)
{
	int				i;
	unsigned int	tmp;
	t_rgb			rgb;

	i = 0;
	while (i < g_scene.res.height * g_scene.res.width * 4)
	{
		rgb.red = g_mlx.pix_addr[i];
		rgb.green = g_mlx.pix_addr[i + 1];
		rgb.blue = g_mlx.pix_addr[i + 2];
		tmp = (double)rgb.red * 0.272 + (double)rgb.green * 0.534 +
				(double)rgb.blue * 0.131;
		g_mlx.pix_addr[i] = tmp < 255 ? tmp : 255;
		tmp = (double)rgb.red * 0.349 + (double)rgb.green * 0.686 +
				(double)rgb.blue * 0.168;
		g_mlx.pix_addr[i + 1] = tmp < 255 ? tmp : 255;
		tmp = (double)rgb.red * 0.393 + (double)rgb.green * 0.769 +
				(double)rgb.blue * 0.189;
		g_mlx.pix_addr[i + 2] = tmp < 255 ? tmp : 255;
		i += 4;
	}
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_mlx.img, 0, 0);
	return (0);
}
/*
**	image_to_bmp();
*/
