/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:13:12 by afrigger          #+#    #+#             */
/*   Updated: 2023/06/12 15:46:55 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*	Personnal headers	*/
# include "../mlx_macos/mlx.h"
# include "../libft/libft.h"
# include "map.h"
# include "hook.h"

/*	Official headers	*/
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define WIDTH 1024
# define HEIGHT 512
# define PI 3.1415926535
# define PI2 PI / 2
# define PI3 3 * PI2
# define DEG 0.0174533
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3
# define NBRAY 512

# define NBCARRE 8
# define CUBSIZE (HEIGHT / NBCARRE)

typedef struct s_player{
	double		px;
	double		py;
	double		pdx;
	double		pdy;
	double		pa;
	double		pa2;
	double		m;
	double		n;
	double		startx;
	double		starty;
	double		endx;
	double		endy;
	double		disT;
	double		lineH;
	double		lineO;
	int			r;
	int			spx;
	int			spy;
	int			ipx;
	int			ipx_add_xo;
	int			ipx_sub_xo;
	int			ipy;
	int			ipy_add_yo;
	int			ipy_sub_yo;
	float		last_rx;
	float		last_ra;
	float		last_ry;
	int			wall_dist;
	int			dwall_n;
	int			dwall_s;
	int			dwall_e;
	int			dwall_w;
	int			flag;
}	t_player;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			ed;
	int			sl;
	int			bpp;
	int			width;
	int			height;
}	t_img;

typedef struct s_cub{
	void		*mlx;
	void		*window;
	void		*img;
	char		*addr;
	int			ed;
	int			sl;
	int			bpp;
	t_player	player;
	int			mapx;
	int			mapy;
	t_img		wall[4]; // 0 = N // 1 = S // 2 = E // 3 = W
	int			sky;
	int			floor;
	char		**map;
	int			*intmap;
	int			**mapnum;
	int			mapsize;
	int			mapstart;
}	t_cub;

/* ----- MAIN ----- */
void	startpos(t_cub *data);
void	startangle(t_cub *data, char angle, int i, int j);
void	mapsizeint(t_cub *data);
int		countmapsize(int fd, t_cub *data);
char	**openmap(char *path, t_cub *data);
void	printerror(t_cub *data, char *str);

/* ----- DRAW ----- */
void	my_mlx_pixel_put(t_cub *data, int x, int y, int color);
void	drawsquare(int x, int y, t_cub *data, int type);
void	drawmap(t_cub *data);
void	render_square(t_cub *data, int x, int y, int i);
void	draw_line(t_cub *data, double angle);

/* ----- IMAGE ----- */
void	draw_sky(t_cub *data);
void	draw_floor(t_cub *data);
void	draw_image(t_cub *data);

/* ----- PLAYER ----- */
void	setplayer(t_cub *data);
void	draw_raycasting(t_cub *data);
float	check_horizontal_lines(t_cub *data, int flag);
void	get_intersection(t_cub *data, int dof, float xo, float yo, float *rx, float *ry);
float	check_vertical_lines(t_cub *data, int flag);
float	dist_wallhit(t_cub *data, float rx, float ry);
void	draw_line3d(t_cub *data, float rx, float ry);
void	check_angle(t_cub *data);
void	setmap(t_cub *data);
void	alloc_intmap(t_cub *data);

/* ----- HOOK ----- */
int		cub_exit(t_cub *data);
void	check_angle(t_cub *data);
void	rotate_player(int keycode, t_cub *data);
void	move_player(int keycode, t_cub *data);
int		hook(int keycode, t_cub *data);
void	check_collision(t_cub *data);

/* ----- SPECIAL OS ----- */
void	add_hook(t_cub *data);

/* ----- INIT ----- */
void	init(t_cub *data, char *av);
void	init_null(t_cub *data);
void	check_color(t_cub *data);

/* ----- TEXTURE ----- */
int		get_texture(t_cub *data, char *path, int wall);
int		get_color_from_texture(t_cub *data, int x, int y, int wall);
void	print_texture(t_cub *data, double ratiox, int x, int y, int wall);
void	select_texture(t_cub *data, float rx, float ry, int x, int y);
void	texture(t_cub *data, char *av);
void	get_color(t_cub *data, int *p, char *str);

/*------ PARSER -------*/
int	check_map(t_cub *data);
int	check_map_space(t_cub *data, int i, int j);
int	check_map_first(t_cub *data, int i, int j);
int check_map_last(t_cub *data, int i, int j);
int check_first_line(t_cub *data);
int	check_col(t_cub *data);
int	check_line(t_cub *data);
void	setmapnum(t_cub * data);

#endif
