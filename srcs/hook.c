/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:23:28 by afrigger          #+#    #+#             */
/*   Updated: 2023/03/16 13:00:34 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/hook.h"

int		cub_exit(t_cub *data)
{
	if (data->window && data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx && data->img)
		mlx_destroy_image(data->mlx, data->img);
	exit (0);
}

void	move_player(int keycode ,t_cub *data)
{
	if (keycode == 13)
		data->player.py -= 5;
	if (keycode == 0)
		data->player.px -= 5;
	if (keycode == 1)
		data->player.py += 5;
	if (keycode == 2)
		data->player.px += 5;
	drawmap(data);
	setplayer(data);
}

int	hook(int keycode, t_cub *data)
{
	if (keycode == 53)
		cub_exit(data);
	else if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		move_player(keycode, data);
	return 0;
}