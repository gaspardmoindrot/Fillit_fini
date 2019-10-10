/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:12:42 by gmoindro          #+#    #+#             */
/*   Updated: 2019/07/09 09:45:52 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_putable(char *str, t_grid grid, char a, int i)
{
	if (str[i] != '.')
		return (0);
	if (str[i + ((grid.min_carre + 1) * (grid.list_tris[a - 'A'].coord[1].y
				- grid.list_tris[a - 'A'].coord[0].y))
				+ (grid.list_tris[a - 'A'].coord[1].x
				- grid.list_tris[a - 'A'].coord[0].x)] != '.')
		return (0);
	if (str[i + ((grid.min_carre + 1) * (grid.list_tris[a - 'A'].coord[2].y
				- grid.list_tris[a - 'A'].coord[0].y))
				+ (grid.list_tris[a - 'A'].coord[2].x
				- grid.list_tris[a - 'A'].coord[0].x)] != '.')
		return (0);
	if (str[i + ((grid.min_carre + 1) * (grid.list_tris[a - 'A'].coord[3].y
				- grid.list_tris[a - 'A'].coord[0].y))
				+ (grid.list_tris[a - 'A'].coord[3].x
				- grid.list_tris[a - 'A'].coord[0].x)] != '.')
		return (0);
	return (1);
}

char	*ft_put_grid(char *str, t_grid grid, char a, int i)
{
	int		j;

	j = 0;
	str[i] = a;
	str[i + ((grid.min_carre + 1) * (grid.list_tris[a - 'A'].coord[1].y
				- grid.list_tris[a - 'A'].coord[0].y))
				+ (grid.list_tris[a - 'A'].coord[1].x
				- grid.list_tris[a - 'A'].coord[0].x)] = a;
	str[i + ((grid.min_carre + 1) * (grid.list_tris[a - 'A'].coord[2].y
				- grid.list_tris[a - 'A'].coord[0].y))
				+ (grid.list_tris[a - 'A'].coord[2].x
				- grid.list_tris[a - 'A'].coord[0].x)] = a;
	str[i + ((grid.min_carre + 1) * (grid.list_tris[a - 'A'].coord[3].y
				- grid.list_tris[a - 'A'].coord[0].y))
				+ (grid.list_tris[a - 'A'].coord[3].x
				- grid.list_tris[a - 'A'].coord[0].x)] = a;
	return (str);
}
