/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 06:08:04 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 06:10:29 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "bmp.h"

void	image_to_bmp(void)
{
	int			fd;

	fd = open("screenshot.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 0 ||
		write_bmpheader(fd) ||
		write_bmpinfo(fd) ||
		write_bmppixels(fd))
		exit(freemem_struct(WRITE_BMP, 0));
	errno = 0;
	ft_putstr("Bmp creation comleted\n");
	close(fd);
	exit(freemem_struct(NULL, 0));
}

int		write_bmpheader(int fd)
{
	t_bmpheader	header;

	ft_bzero(&header, sizeof(t_bmpheader));
	header.type = 0x4D42;
	header.size = BMP_HEADER_SIZE + BMP_INFO_SIZE +
				g_scene.res.width * g_scene.res.height * 4;
	header.offset = BMP_HEADER_SIZE + BMP_INFO_SIZE;
	if (write(fd, &header.type, 2) == -1 ||
			write(fd, &header.size, 4) == -1 ||
			write(fd, &header.reserved, 4) == -1 ||
			write(fd, &header.offset, 4) == -1)
		return (1);
	return (0);
}

int		write_bmpinfo(int fd)
{
	t_bmpinfo	info;

	ft_bzero(&info, sizeof(t_bmpinfo));
	info.size = BMP_INFO_SIZE;
	info.width = g_scene.res.width;
	info.height = g_scene.res.height;
	info.planes = 1;
	info.bits_per_pixel = 32;
	info.compression = BI_RGB;
	info.size_image = g_scene.res.width * g_scene.res.height * 4;
	if (write(fd, &info.size, 4) == -1 ||
		write(fd, &info.width, 4) == -1 ||
		write(fd, &info.height, 4) == -1 ||
		write(fd, &info.planes, 2) == -1 ||
		write(fd, &info.bits_per_pixel, 2) == -1 ||
		write(fd, &info.compression, 4) == -1 ||
		write(fd, &info.size_image, 4) == -1 ||
		write(fd, &info.bits_per_meter_x, 4) == -1 ||
		write(fd, &info.bits_per_meter_y, 4) == -1 ||
		write(fd, &info.color_used, 4) == -1 ||
		write(fd, &info.color_important, 4) == -1)
		return (1);
	return (0);
}

int		write_bmppixels(int fd)
{
	unsigned char	*buf;
	int				i;

	buf = (unsigned char *)g_mlx.pix_addr;
	i = g_scene.res.height;
	while (--i >= 0)
		write(fd, &buf[i * g_scene.res.width * 4], g_scene.res.width * 4);
	return (0);
}
