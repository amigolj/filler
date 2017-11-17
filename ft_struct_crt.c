/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_crt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:33:47 by mkurchin          #+#    #+#             */
/*   Updated: 2017/06/26 14:33:48 by mkurchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_create_struct(t_st **ptr, t_fl **fl)
{
	if (*ptr == NULL)
	{
		*ptr = (t_st*)malloc(sizeof(t_st));
		*fl = (t_fl*)malloc(sizeof(t_fl));
		ft_init_struct(ptr, fl);
	}
	else if ((*fl)->fl_figsize_crt == 1 && (*fl)->fl_fig_crt == 0)
	{
		(*ptr)->map_f = (char**)malloc(sizeof(char *) * (*ptr)->f_y + 1);
		(*ptr)->map_f[(*ptr)->f_y] = NULL;
		(*fl)->fl_fig_crt = 1;
	}
	if ((*fl)->fl_map_crt == 0 && (*fl)->fl_mapsize_crt == 1)
	{
		(*ptr)->map = (char **)malloc(sizeof(char *) * (*ptr)->m_y + 1);
		(*ptr)->map[(*ptr)->m_y] = NULL;
		(*fl)->fl_map_crt = 1;
	}
}

void	ft_free_struct(t_st *ptr, t_fl *fl, char **line)
{
	int i;

	i = -1;
	if (ptr->map != NULL)
	{
		while (++i < ptr->m_y)
			free(ptr->map[i]);
		ptr->map = NULL;
	}
	i = -1;
	if (ptr->map_f != NULL)
	{
		while (++i < ptr->f_y)
			free(ptr->map_f[i]);
		ptr->map_f = NULL;
	}
	if (*line != NULL)
		free(*line);
	*line = NULL;
	free(fl);
	free(ptr);
}
