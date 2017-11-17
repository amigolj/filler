/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sv_cord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:33:20 by mkurchin          #+#    #+#             */
/*   Updated: 2017/06/26 14:33:21 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_sv_figure(char **line, t_st *ptr, t_fl *fl)
{
	int indx;

	indx = ptr->indx_map_f;
	if (fl->fl_fig_crt == 0)
		ft_create_struct(&ptr, &fl);
	ptr->map_f[indx] = ft_strdup(*line);
	ptr->indx_map_f++;
	if (ptr->indx_map_f == (ptr->f_y))
		fl->fl_fin_scan_m = 1;
}

void	ft_map_sv(char **line, t_st *ptr, t_fl *fl)
{
	int indx;

	if (fl->fl_map_crt == 0 && fl->fl_mapsize_crt == 1)
		ft_create_struct(&ptr, &fl);
	indx = fl->cnt_line;
	ptr->map[indx] = ft_strdup(*line);
}

void	ft_sv_size_map_fig(char **line, int *y, int *x, t_fl *fl)
{
	char *line2;

	line2 = *line;
	while ((ft_isalpha(*line2)))
		line2++;
	*y = ft_atoi(line2);
	(line2)++;
	line2 = ft_strchr(line2, ' ');
	*x = ft_atoi(line2);
	fl->fl_mapsize_crt = 1;
}

void	ft_output_pos(t_st *ptr)
{
	ft_putnbr(ptr->pos_y);
	write(1, " ", 1);
	ft_putnbr(ptr->pos_x);
	write(1, "\n", 1);
}

void	ft_wrt_pos(t_st *ptr, int y, int x, int *fl)
{
	if ((is_edge(ptr) &&
	wht_dist(ptr->pos_y, ptr->pos_x, ptr->pos_e_y, ptr->pos_e_x) >
	wht_dist(y, x, ptr->pos_e_y, ptr->pos_e_x)) || *fl == 0)
	{
		ptr->pos_y = y;
		ptr->pos_x = x;
		*fl = 1;
	}
}
