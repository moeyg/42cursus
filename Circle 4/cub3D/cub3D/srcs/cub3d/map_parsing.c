/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:04:03 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 17:37:00 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(char *map)
{
	int	map_info;

	map_info = parse_direction(map);
	if (map_info)
	{
		return (map_info);
	}
	map_info = parse_background(map);
	if (map_info)
	{
		return (map_info);
	}
	map_info = parse_map_component(map);
	{
		return (map_info);
	}
}

int	parse_direction(char *direction)
{
	if (!ft_strncmp(direction, NORTH, 3))
	{
		return (NO);
	}
	else if (!ft_strncmp(direction, SOUTH, 3))
	{
		return (SO);
	}
	else if (!ft_strncmp(direction, WEST, 3))
	{
		return (WE);
	}
	else if (!ft_strncmp(direction, EAST, 3))
	{
		return (EA);
	}
	else
		return (FALSE);
}

int	parse_background(char *background)
{
	if (!ft_strncmp(background, FLOOR, 2))
	{
		return (F);
	}
	else if (!ft_strncmp(background, CEILING, 2))
	{
		return (C);
	}
	else
		return (FALSE);
}

int	parse_map_component(char *components)
{
	int	i;

	i = -1;
	while (components[++i])
	{
		if (!valid_components(MAP_COMPONENT, components[i]))
		{
			return (FALSE);
		}
	}
	return (MAP);
}
