/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:03:54 by gmoindro          #+#    #+#             */
/*   Updated: 2019/06/25 12:22:05 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tris
{
	char			name;
	int				plc;
	t_coord			coord[4];
}					t_tris;

typedef struct		s_grid
{
	int				nbr_tris;
	int				min_carre;
	char			*str;
	char			a;
	int				i;
	int				ready;
	int				count;
	t_tris			list_tris[26];
}					t_grid;

t_grid				ft_comp_grid(int fd);
t_tris				ft_list_tris(char *buff, int i);
t_coord				ft_list_coord(int i);
int					ft_racine_carre(int i);
char				*ft_grid_final(t_grid grid);
char				*ft_grid_init(int min_carre);
char				*ft_grid_clean(char *str, char c);
t_grid				ft_grid_end(t_grid grid);
char				*ft_put_grid(char *str, t_grid grid, char a, int i);
int					ft_is_putable(char *str, t_grid grid, char a, int i);
int					ft_main(int argc, char **argv);
int					ft_open_file(int fd);
int					ft_read_file(int fd);
int					ft_check_tris(char *str);
int					ft_coord(char *str, int j, int k, int l);
int					ft_bon_tris(int i, int j, int k, int l);
int					ft_bon_tris2(int i, int j, int k, int l);
t_grid				ft_grid_i_inf(t_grid grid);

#endif
