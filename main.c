/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 21:24:22 by mkurchin          #+#    #+#             */
/*   Updated: 2017/06/23 21:24:24 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_is_line(char **line)
{
	*line += 4;
	if (**line == '.' || **line == 'O' || **line == 'X'
	|| **line == 'o' || **line == 'x')
		return (1);
	*line -= 4;
	return (0);
}

int		ft_hndl_step(char **line, t_st *ptr, t_fl *fl)
{
	if (**line == 'P' && fl->fl_mapsize_crt == 1 && fl->fl_figsize_crt == 0)
	{
		ft_sv_size_map_fig(line, &(ptr->f_y), &(ptr->f_x), fl);
		fl->fl_figsize_crt = 1;
	}
	else if (fl->fl_mapsize_crt == 1 &&
	fl->fl_figsize_crt == 0 && ft_is_line(line))
		ft_map_sv(line, ptr, fl);
	else if (fl->fl_figsize_crt == 1 && (**line == '.' || **line == '*'))
	{
		ft_sv_figure(line, ptr, fl);
		if (fl->fl_fin_scan_m == 1)
		{
			ft_srch_put(ptr);
			return (0);
		}
	}
	return (1);
}

void	ft_wht_is_player_map(char **line, t_st *ptr, t_fl *fl)
{
	char *p;

	if (**line == '$' && (p = ft_strchr(*line, 'p')) && ptr->player == 0)
	{
		p++;
		ptr->player = (*p == '1') ? 1 : 2;
	}
	else if (**line == 'P' && fl->fl_mapsize_crt == 0)
	{
		ft_sv_size_map_fig(line, &(ptr->m_y), &(ptr->m_x), fl);
	}
	else if (**line == ' ')
		fl->bgn_map = 1;
}

void	ft_read_page(int fd, t_st *ptr, t_fl *fl)
{
	char	*line;
	int		tmp;

	while (get_next_line(fd, &line) > 0)
	{
		if (ptr->player == 0 || fl->fl_mapsize_crt == 0 || fl->bgn_map == 0)
		{
			ft_wht_is_player_map(&line, ptr, fl);
			free(line);
			continue;
		}
		if (fl->bgn_map == 1)
			if (!(ft_hndl_step(&line, ptr, fl)))
			{
				tmp = ptr->player;
				ft_free_struct(ptr, fl, &line);
				ptr = NULL;
				fl = NULL;
				ft_create_struct(&ptr, &fl);
				ptr->player = tmp;
				fl->cnt_line = -1;
			}
		fl->cnt_line++;
	}
	ft_free_struct(ptr, fl, &line);
}

int		main(void)
{
	int		fd;
	t_st	*ptr;
	t_fl	*fl;

	ptr = NULL;
	fl = NULL;
	fd = 0;
	ft_create_struct(&ptr, &fl);
	ft_read_page(fd, ptr, fl);
	return (0);
}
