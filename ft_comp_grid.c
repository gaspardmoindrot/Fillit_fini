/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:01:51 by gmoindro          #+#    #+#             */
/*   Updated: 2019/06/25 09:25:23 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_grid		ft_comp_grid(int fd)
{
	t_grid	grid;
	char	buff[22];
	int		r;
	int		i;

	i = 0;
	while ((r = read(fd, buff, 21)) > 0)
	{
		buff[r] = '\0';
		grid.list_tris[i] = ft_list_tris(buff, i);
		i++;
	}
	grid.nbr_tris = i;
	grid.min_carre = ft_racine_carre(i * 4);
	return (grid);
}

t_tris		ft_list_tris(char *buff, int i)
{
	t_tris	tris;
	int		j;
	int		k;

	k = 0;
	j = 0;
	tris.name = i + 'A';
	while (buff[k])
	{
		if (buff[k] == '#')
		{
			tris.coord[j] = ft_list_coord(k);
			j++;
		}
		k++;
	}
	return (tris);
}

t_coord		ft_list_coord(int i)
{
	t_coord	coord;

	coord.x = i % 5;
	coord.y = i / 5;
	return (coord);
}

int			ft_racine_carre(int i)
{
	int		racine;

	racine = 1;
	while ((racine * racine) < i)
	{
		racine++;
	}
	return (racine);
}
