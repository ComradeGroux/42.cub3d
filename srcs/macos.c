/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:18:40 by vgroux            #+#    #+#             */
/*   Updated: 2023/05/17 16:19:02 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_hook(t_cub *data)
{
	mlx_hook(data->window, 2, 0, &hook, data);
	mlx_hook(data->window, 17, 0, &cub_exit, data);
	mlx_loop(data->mlx);
}
