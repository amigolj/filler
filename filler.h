/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 19:20:18 by mkurchin          #+#    #+#             */
/*   Updated: 2017/06/23 19:20:31 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# define X 0
# define Y 1

typedef struct	s_st {

	int		m_x;
	int		m_y;
	int		f_x;
	int		f_y;
	int		pos_x;
	int		pos_y;
	int		pos_e_x;
	int		pos_e_y;
	int		indx_map_f;
	int		player;
	int		end_map;
	char	**map_f;
	char	**map;
}				t_st;

typedef struct	s_fl {

	int		fl_my_pos;
	int		fl_e;
	int		fl_fig_crt;
	int		fl_figsize_crt;
	int		fl_mapsize_crt;
	int		fl_map_crt;
	int		cnt_line;
	int		fl_fin_scan_m;
	int		bgn_map;
	int		fl_before_cnt;
}				t_fl;

void			ft_create_struct(t_st **ptr, t_fl **fl);
void			ft_map_sv(char **line, t_st *ptr, t_fl *fl);
void			ft_free_struct(t_st *ptr, t_fl *fl, char **line);
void			ft_init_struct(t_st **ptr, t_fl **fl);
void			ft_wrt_pos(t_st *ptr, int y, int x, int *fl);
int				is_edge(t_st *ptr);
int				wht_dist(int y, int x, int e_y, int e_x);
void			ft_srch_put(t_st *ptr);
void			ft_sv_size_map_fig(char **line, int *y, int *x, t_fl *fl);
void			ft_sv_figure(char **line, t_st *ptr, t_fl *fl);
void			ft_output_pos(t_st *ptr);

#endif
