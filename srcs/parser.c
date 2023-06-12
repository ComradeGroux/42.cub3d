/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:43:18 by vgroux            #+#    #+#             */
/*   Updated: 2023/06/12 11:58:28 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	check_map(t_cub *data)
{
	int i;
	int j;

	i = 1;
	j = 0;
	// if (check_map_longline(data) != 0)
	// 	return (123);
	while (data->map[i])
	{
		if (check_first_line(data) != 0)
			return (123);
		if (ft_isspace(data->map[i][j]) == 1)
			if (check_map_space(data, i, j) != 0)
				return (123);
		if (check_map_first(data, i, j) != 0)
			return (123);
		if (check_map_last(data, i ,j) != 0)
			return (123);
		i++;
		j = 0;
	}
	return (0);
}

int	check_map_space(t_cub *data, int i, int j)
{	
	while (ft_isspace(data->map[i][j]) == 1)
	{
		printf("space\n");
		if (data->map[i - 1][j] == '0' || data->map[i + 1][j] == '0')
			return(123);
		if ((data->map[i][j + 1] == '0' && data->map[i][j] != '1') || (data->map[i][j - 1] == '0' && j != 0))
			return (123);
		j++;
	}
	j = ft_strlen(data->map[i]);
	while (ft_isspace(data->map[i][j]) == 1)
	{
		printf("space\n");
		if (data->map[i - 1][j] == '0' || data->map[i + 1][j] == '0')
			return(123);
		if ((data->map[i][j + 1] == '0' && data->map[i][j] != '1') || (data->map[i][j - 1] == '0' && j != 0))
			return (123);
		j--;
	}
	return(0);
}

int	check_map_first(t_cub *data, int i, int j)
{printf("first\n");
	while(ft_isspace(data->map[i][j] == 1))
		j++;
	if (data->map[i][j] == '0')
		return (123);
	return (0);
}

int check_map_last(t_cub *data, int i, int j)
{printf("last\n");
	j = ft_strlen(data->map[i]) - 1;
	//printf("%c\n", data->map[i][j]);
	while (data->map[i][j] != '1')
	{
		if (data->map[i - 1])
			if (data->map[i - 1][j] == '0')
				return (123);
		if (data->map[i + 1])
			if (data->map[i + 1][j] == '0')
			return (123);
		j--;
	}
	if (data->map[i][j] == '0')
		return (123);
	return (0);
}

int check_first_line(t_cub *data)
{printf("firstline\n");
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_isspace(data->map[i][j]))
		j++;
	while (data->map[i][j])
	{
		if (data->map[i][j] == '0')
			return (123);
		j++;
	}
	return (0);
}

int	check_map_longline(t_cub *data)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{printf("%d | %d | %d\n", i, j, k);
			if (ft_strlen(data->map[i - 1]) < ft_strlen(data->map[i]) && ft_strlen(data->map[i + 1]) < ft_strlen(data->map[i]))
			{printf("long1\n");
				if (data->map[i][j] == '0')
					return (123);
			}
			else if (data->map[i][j] == '0' && ft_strlen(data->map[i - 1]) < ft_strlen(data->map[i]))
			{printf("long2\n");
				k = i;
				j = ft_strlen(data->map[k]);
				while (k != 0 && data->map[k][j] != '1')
				{
					j = ft_strlen(data->map[k]);
					while (j != (int)ft_strlen(data->map[k - 1]))
					{
						if (data->map[k][j] == '0')
							return (123);
						j--;
					}
					k--;
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int    check_col(t_cub *data)
	{
	int    i;
	int    j;

	i = 0;
	j = 0;
	while (i < data->mapx - 1)
	{
		j = 0;
		while (j < data->mapy - 1 && !data->map[i][j])
			j++;
		if (!data->map[i][j] || data->map[i][j] != '1')
			return (0);
		j = data->mapy - 1;
		while (j > 0 && !data->map[i][j])
			j--;
		if (!data->map[i][j] || data->map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
	}

int    check_line(t_cub *data)
{
	int    i;
	int    j;

	i = 0;
	j = 0;
	while (i < data->mapy)
	{
		j = 0;
		while (j < data->mapx - 1 && !data->map[i][j])
			j++;
		if (data->map[i][j] != '1')
			return (0);
		j = data->mapx - 1;
		while (j > 0 && !data->map[i][j])
			j--;
		if (data->map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}