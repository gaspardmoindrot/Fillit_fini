/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:50:16 by gmoindro          #+#    #+#             */
/*   Updated: 2019/06/25 09:26:56 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_grid	ft_grid_i_inf(t_grid grid)
{
	grid.str = ft_put_grid(grid.str, grid, grid.a, grid.i);
	grid.list_tris[grid.a - 'A'].plc = grid.i;
	grid.a++;
	grid.i = 0;
	return (grid);
}
