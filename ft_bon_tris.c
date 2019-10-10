/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bon_tris.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:23:39 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/06/25 12:28:59 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_bon_tris(int i, int j, int k, int l)
{
	if (j == i + 5 && k == j + 5 && l == k + 5)
		return (1);
	if (j == i + 1 && k == j + 1 && l == k + 1)
		return (1);
	if (j == i + 1 && k == j + 3 && l == k + 1)
		return (1);
	if (j == i + 5 && k == j + 1 && l == k + 5)
		return (1);
	if (j == i + 1 && k == j + 5 && l == k + 1)
		return (1);
	if (j == i + 4 && k == j + 1 && l == k + 4)
		return (1);
	if (j == i + 1 && k == j + 4 && l == k + 1)
		return (1);
	if (j == i + 5 && k == j + 5 && l == k + 1)
		return (1);
	if (j == i + 3 && k == j + 1 && l == k + 1)
		return (1);
	if (ft_bon_tris2(i, j, k, l) == 1)
		return (1);
	return (0);
}

int		ft_bon_tris2(int i, int j, int k, int l)
{
	if (j == i + 1 && k == j + 5 && l == k + 5)
		return (1);
	if (j == i + 1 && k == j + 1 && l == k + 3)
		return (1);
	if (j == i + 5 && k == j + 4 && l == k + 1)
		return (1);
	if (j == i + 1 && k == j + 1 && l == k + 5)
		return (1);
	if (j == i + 1 && k == j + 4 && l == k + 5)
		return (1);
	if (j == i + 5 && k == j + 1 && l == k + 1)
		return (1);
	if (j == i + 4 && k == j + 1 && l == k + 1)
		return (1);
	if (j == i + 4 && k == j + 1 && l == k + 5)
		return (1);
	if (j == i + 1 && k == j + 1 && l == k + 4)
		return (1);
	if (j == i + 5 && k == j + 1 && l == k + 4)
		return (1);
	return (0);
}
