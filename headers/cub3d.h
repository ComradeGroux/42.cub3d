/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:13:12 by afrigger          #+#    #+#             */
/*   Updated: 2023/05/10 15:18:07 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define	CUB3D_H

#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../mlx_macos/mlx.h"
#include "../libft/libft.h"

#define WIDTH 1024
#define HEIGHT 512
#define PI 3.1415926535
#define DEG 0.0174533
# define BLUE_COLOR 0x87CEEB
# define GREY_COLOR 0x808080

typedef struct s_player{
	double		px;
	double		py;
	double		pdx;
	double		pdy;
	double		pa;
	double		m;
	double		n;
	double		startx;
	double		starty;
	double		endx;
	double		endy;
}	t_player;

typedef struct s_cub{
	void		*mlx;
	void		*window;
	void		*img;
	char		*addr;
	int			endian;
	int			sizeline;
	int			bpp;
	t_player	player;
	int			mapx;
	int			mapy;
}	t_cub;


/* ----- MAIN ----- */
int		main(void);
void	drawmap(t_cub *data);
void	fill_all(t_cub *data);

/* ----- DRAW ----- */
void	my_mlx_pixel_put(t_cub *data, int x, int y, int color);
void	drawsquare(int x, int y, t_cub *data, int type);

/* ----- IMAGE ----- */
void	draw_sky(t_cub *data);
void	draw_floor(t_cub *data);
void	draw_image(t_cub *data);

/* ----- PLAYER ----- */
void	setplayer(t_cub *data);
void	raydraw(t_cub *data);

#endif
