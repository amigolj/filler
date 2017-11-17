/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:02:20 by mkurchin          #+#    #+#             */
/*   Updated: 2017/06/26 15:02:21 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_init_struct(t_st **ptr, t_fl **fl)
{
	(*ptr)->m_y = 0;
	(*ptr)->m_x = 0;
	(*ptr)->f_x = 0;
	(*ptr)->f_y = 0;
	(*ptr)->pos_x = -1;
	(*ptr)->pos_y = -1;
	(*ptr)->pos_e_x = 0;
	(*ptr)->pos_e_y = 0;
	(*ptr)->player = 0;
	(*ptr)->end_map = 0;
	(*ptr)->indx_map_f = 0;
	(*ptr)->map = NULL;
	(*ptr)->map_f = NULL;
	(*fl)->fl_my_pos = 0;
	(*fl)->fl_e = 0;
	(*fl)->fl_fig_crt = 0;
	(*fl)->cnt_line = 0;
	(*fl)->fl_fin_scan_m = 0;
	(*fl)->fl_mapsize_crt = 0;
	(*fl)->fl_figsize_crt = 0;
	(*fl)->fl_map_crt = 0;
	(*fl)->bgn_map = 0;
	(*fl)->fl_before_cnt = 1;
}
