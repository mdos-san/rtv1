#include "rt_v1.h"

void	img_clear(t_img *img, t_col col)
{
	int	y;
	int	x;

	y = 0;
	while (y < img->hei)
	{
		x = 0;
		while (x < img->wid)
		{
			img_put_pixel(img, x, y, col);
			++x;
		}
		++y;
	}

}
