/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:00:40 by jkoupy            #+#    #+#             */
/*   Updated: 2024/05/16 21:35:25 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		write(1, "Error: wrong number of arguments\n", 34);
		return (1);
	}
	if (!check_args(argc, argv))
		return (1);
	if (!init_data(&data, argc, argv))
		return (1);
	philosophers(&data);
	free_data(&data);
	return (0);
}
