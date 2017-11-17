/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:40:49 by mkurchin          #+#    #+#             */
/*   Updated: 2017/06/26 13:40:50 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_is_good_pos(t_st *ptr, int m_y, int m_x, char plr)
{
	int	mm_x;
	int	f_y;
	int	f_x;
	int	fl;

	f_y = -1;
	fl = 0;
	if (m_y + ptr->f_y > ptr->m_y || m_x + ptr->f_x > ptr->m_x)
		return (0);
	while (++f_y < ptr->f_y)
	{
		f_x = -1;
		mm_x = m_x;
		while (++f_x < ptr->f_x)
		{
			if (ptr->map_f[f_y][f_x] == '*' &&
			ptr->map[m_y + f_y][mm_x + f_x] == plr)
				fl++;
			else if (ptr->map_f[f_y][f_x] == '*' &&
			ptr->map[m_y + f_y][mm_x + f_x] != '.')
				return (0);
		}
	}
	return ((fl == 1) ? 1 : 0);
}

int		scan_free(t_st *ptr, int y, int x)
{
	int cnt;

	cnt = 0;
	if ((x + 2) < ptr->m_x && ptr->map[y][x + 1] == '.' &&
	ptr->map[y][x + 2] == '.')
		cnt++;
	if ((x - 2) >= 0 && ptr->map[y][x - 1] == '.' && ptr->map[y][x - 2] == '.')
		cnt++;
	if ((y + 2) < ptr->m_y && ptr->map[y + 1][x] == '.' &&
	ptr->map[y + 2][x] == '.')
		cnt++;
	if ((y - 2) >= 0 && ptr->map[y - 1][x] == '.' && ptr->map[y - 2][x] == '.')
		cnt++;
	if (cnt >= 2)
		return (1);
	return (0);
}

int		wht_dist(int y, int x, int e_y, int e_x)
{
	int dist;
	int sum_y;
	int sum_x;

	sum_x = e_x - x;
	sum_x *= sum_x;
	sum_y = e_y - y;
	sum_y *= sum_y;
	dist = sum_y + sum_x;
	return ((dist < 0) ? dist *= -1 : dist);
}

int		is_edge(t_st *ptr)
{
	int		y;
	int		x;
	char	plr;

	plr = (ptr->player == 1) ? 'X' : 'O';
	y = 0;
	while (y < ptr->m_y)
	{
		x = 0;
		while (x < ptr->m_x)
		{
			if (ptr->map[y][x] == plr && scan_free(ptr, y, x))
			{
				ptr->pos_e_x = x;
				ptr->pos_e_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_srch_put(t_st *ptr)
{
	int		y;
	int		x;
	int		fl;
	char	plr;

	plr = (ptr->player == 1) ? 'O' : 'X';
	fl = 0;
	y = 0;
	while (y < ptr->m_y)
	{
		x = 0;
		while (x < ptr->m_x)
		{
			if (ft_is_good_pos(ptr, y, x, plr))
				ft_wrt_pos(ptr, y, x, &fl);
			x++;
		}
		y++;
	}
	ft_output_pos(ptr);
}
