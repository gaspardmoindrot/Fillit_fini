/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 12:46:48 by gmoindro          #+#    #+#             */
/*   Updated: 2019/06/25 12:27:09 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_open_file(int fd)
{
	int		end;

	end = ft_read_file(fd);
	if (end == 0)
		return (0);
	return (1);
}

int		ft_read_file(int fd)
{
	int		read_now;
	int		read_before;
	char	*buff;
	int		i;

	i = 0;
	buff = ft_strnew(21);
	while ((read_now = read(fd, buff, 21)) > 0)
	{
		read_before = read_now;
		if (ft_check_tris(buff) == 0)
			return (0);
		i++;
	}
	if (i > 26)
		return (0);
	if (read_before != 20 || read_now != 0)
		return (0);
	return (1);
}

int		ft_check_tris(char *str)
{
	int		i;
	int		point;
	int		ash;
	int		saut;

	saut = 0;
	point = 0;
	ash = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '#')
			ash++;
		if (str[i] == '.')
			point++;
		if (str[i] == '\n')
			saut++;
		if (str[i] == '\n' && ((i + 1) % 5 != 0) && i != 20)
			return (0);
	}
	if (ash != 4 || point != 12 || (saut != 4 && saut != 5)
			|| str[i - 1] != '\n' || (ft_coord(str, 0, 0, 0) == 0))
		return (0);
	return (1);
}

int		ft_coord(char *str, int j, int k, int l)
{
	int		end;
	int		i;

	i = 0;
	while (str[i] != '#')
		i++;
	j = i + 1;
	while (str[j] != '#')
		j++;
	k = j + 1;
	while (str[k] != '#')
		k++;
	l = k + 1;
	while (str[l] != '#')
		l++;
	end = ft_bon_tris(i, j, k, l);
	if (end == 0)
		return (0);
	return (1);
}
