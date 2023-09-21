/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:03:14 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 21:26:20 by dogpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_game *game)
{
	printf(GREEN);
	printf("EXIT CUB3D\n");
	printf(RESET);
	free_datas(game, 0);
	exit(FAIL);
}

void	exit_program(char *message)
{
	print_error(message);
	exit(FAIL);
}

void	print_error(char *message)
{
	printf(RED);
	printf("Error\n");
	printf(RESET);
	if (message)
	{
		printf(BLACK);
		printf("%s\n", message);
		printf(RESET);
	}
}
