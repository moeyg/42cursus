/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dogpark <dogpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:03:14 by dogpark           #+#    #+#             */
/*   Updated: 2023/09/21 19:30:36 by dogpark          ###   ########.fr       */
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
	printf("ERROR: ");
	printf(RESET);
	if (message)
	{
		printf("%s\n", message);
	}
}
