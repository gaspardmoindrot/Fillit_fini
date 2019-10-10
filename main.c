/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:46:17 by gmoindro          #+#    #+#             */
/*   Updated: 2019/07/09 09:25:59 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_grid	grid;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			ft_putstr("error\n");
		else if (ft_open_file(fd) != 0)
		{
			close(fd);
			fd = open(argv[1], O_RDONLY);
			grid = ft_comp_grid(fd);
			grid.ready = 0;
			grid.count = 0;
			ft_putstr(ft_grid_final(grid));
			close(fd);
			return (0);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit input_file\n");
	return (0);
}
