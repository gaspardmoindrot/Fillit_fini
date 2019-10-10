/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_final.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:05:34 by gmoindro          #+#    #+#             */
/*   Updated: 2019/07/09 09:55:14 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_grid_final(t_grid grid)
{
	grid.str = ft_grid_init(grid.min_carre);
	grid.a = 'A';
	grid.i = 0;
	while (grid.ready == 0)
	{
		grid = ft_grid_end(grid);
		grid.count = 0;
		if (grid.str[0] == '%')
		{
			free(grid.str);
			grid.min_carre++;
			return (ft_grid_final(grid));
		}
	}
	free(grid.str);
	return (grid.str);
}

char	*ft_grid_init(int min_carre)
{
	char	*str;
	int		i;
	int		j;

	j = (min_carre + 1) * 3;
	i = 0;
	str = (char*)malloc((sizeof(char) * ((min_carre + 1) * min_carre)) + j);
	if (!str)
		return (NULL);
	while (i < (min_carre + 1) * min_carre)
	{
		if ((i + 1) % (min_carre + 1) == 0)
			str[i] = '\n';
		else
			str[i] = '.';
		i++;
	}
	str[i] = '\0';
	while (i < j)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_grid_clean(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = '.';
		i++;
	}
	return (str);
}

t_grid	ft_grid_end(t_grid grid)
{
	grid.count++;
	if (grid.count > 100)
		return (grid);
	while (!(ft_is_putable(grid.str, grid, grid.a, grid.i))
			&& grid.i < (((grid.min_carre + 1) * grid.min_carre)))
		grid.i++;
	if (grid.i < ((grid.min_carre + 1) * grid.min_carre)
			&& (grid.a - 64) == grid.nbr_tris)
	{
		grid.str = ft_put_grid(grid.str, grid, grid.a, grid.i);
		grid.ready = 1;
		return (grid);
	}
	else if (grid.i < ((grid.min_carre + 1) * grid.min_carre))
		return (ft_grid_end(ft_grid_i_inf(grid)));
	else if (grid.a == 'A')
	{
		grid.str[0] = '%';
		return (grid);
	}
	grid.str = ft_grid_clean(grid.str, grid.a - 1);
	grid.a--;
	grid.i = grid.list_tris[grid.a - 'A'].plc + 1;
	return (ft_grid_end(grid));
}
