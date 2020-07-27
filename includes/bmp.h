#ifndef BMP_H
# define BMP_H

#define BMP_HEADER_SIZE 14
#define BMP_INFO_SIZE 40
#define BI_RGB 0

typedef struct	s_bmpheader
{
	short		type;
	int			size;
	int			reserved;
	int			offset;
}				t_bmpheader;

typedef struct	s_bmpinfo
{
	int			size;
	int			width;
	int			height;
	short		planes;
	short		bits_per_pixel;
	int			compression;
	int			size_image;
	int			bits_per_meter_x;
	int			bits_per_meter_y;
	int			color_used;
	int			color_important;

}				t_bmpinfo;

void	image_to_bmp(void);
int		write_bmpheader(int fd);
int		write_bmpinfo(int fd);
int		write_bmppixels(int fd);

#endif
