/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 07:01:17 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/20 20:01:53 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
# define RT_V1_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# include "libft.h"
# include "get_next_line.h"
# include "libcolor.h"

# define WID 800
# define HEI 600

# define RAYON 5

# define CDTP 10

# define P_WID (WID / 100)
# define P_HEI (HEI / 100)

# define SPH 0
# define PLA 1
# define CYL 2
# define CON 3

typedef struct		s_pnt
{
	double			x;
	double			y;
	double			z;
}					t_pnt;

typedef struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef struct		s_ray
{
	t_pnt			o;
	t_vec			v;
	double			dist;
}					t_ray;

typedef struct		s_cam
{
	t_pnt			o;
	t_vec			vx;
	t_vec			vy;
	t_vec			vz;
}					t_cam;

typedef struct		s_obj
{
	char			type;
	t_pnt			o;
	t_vec			v;
	double			size;
	double			d;
	t_color			col;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_img
{
	void			*ptr;
	int				wid;
	int				hei;
	char			*data;
	int				bpp;
	int				sl;
	int				ed;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_color			col;
	char			debug;
	char			*file;
	int				fd;
	t_cam			cam;
	t_ray			ray;
	t_obj			*obj;
	t_obj			*cur;
	int				i;
	int				(*ft_ptr[2])(struct s_env *, t_obj);
	double			dist;
}					t_env;

t_env				*rt_v1_init(char *file);
void				rt_v1_exit(t_env **env, char *str);
void				rt_v1_get_info(t_env *env);
int					parse(t_env *env);
int					obj_add(t_obj **obj);
void				obj_destroy(t_obj **obj);
void				rt_mlx_init(t_env *env);
void				pnt_translate(t_pnt	*pnt, t_vec vec, double coef);
void				render_loop(t_env *env);
int					sphere_colision(t_env *env, t_obj sph);
int					plane_colision(t_env *env, t_obj sph);
void				check_colision(t_env *env);
void				img_pixel_put(t_img *img, int x, int y, t_color col);
void				init_sph(t_env *env, const char *line);
void				init_pla(t_env *env, const char *line);

#endif
