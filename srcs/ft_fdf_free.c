/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:32 by mlinhard          #+#    #+#             */
/*   Updated: 2016/11/20 21:49:33 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		fascii(int ico, char *type, char *data)
{
	wchar_t		uni;
	char		msg[4096];
	char		bar[100];

	uni = (ico == 1) ? L'✅' : L'❕';
	(ico == 1) ?
	ft_memcpy(msg, "free\0", 8) : ft_memcpy(msg, "-\0", 14);
	ft_memcpy(bar, ((ico == 1) ? LINE_GREEN : LINE_GREY), 13);
	ft_printf(" %C %s %12s %s %-23s %s %-28s %s\e[93m\n", uni, bar, type
		, bar, data, bar, msg, bar);
	return (1);
}

int		flmenu(t_data *d, int log)
{
	t_lmenu	*lst;
	t_lmenu	*del;

	if (log == 1)
		fascii(((d->menu.lst) ? 1 : 0), "t_lmenu *", "d->menu.lst");
	if (!d->menu.lst)
		return (1);
	lst = d->menu.lst;
	while (lst)
	{
		del = lst;
		lst = lst->p;
		ft_memdel((void **)&del);
	}
	d->menu.lst = NULL;
	return (1);
}

int		fmap(t_data *d, int i, int log)
{
	if (log == 1)
	{
		fascii(((d->map.map) ? 1 : 0), "int **", "d->map.map");
		fascii(((d->map.col) ? 1 : 0), "int **", "d->map.col");
		fascii(((d->map.path) ? 1 : 0), "char *", "d->map.path");
	}
	if (d->map.map)
		while (++i < d->map.ym)
			ft_memdel((void **)&d->map.map[i]);
	if (d->map.map)
		ft_memdel((void **)&d->map.map);
	i = -1;
	if (d->map.col)
		while (++i < d->map.ym)
			ft_memdel((void **)&d->map.col[i]);
	if (d->map.col)
		ft_memdel((void **)&d->map.col);
	ft_strdel(&d->map.path);
	return (1);
}

void	fdatabox(t_data *d)
{
	pascii(ASC_FREEDATA);
	flmenu(d, 1);
	fmap(d, -1, 1);
	get_next_line(-10, NULL);
	fdestroyimg(d);
}
