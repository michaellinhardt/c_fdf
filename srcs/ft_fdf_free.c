/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:32 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 02:48:09 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		flmenu(t_data *d)
{
	t_lmenu	*lst;
	t_lmenu	*del;

	if (!d->menu.lst)
		return (1);
	lst = d->menu.lst;
	while (lst)
	{
		ft_printf("free: %s\n", lst->path);
		del = lst;
		lst = lst->p;
		ft_memdel((void **)&del);
	}
	d->menu.lst = NULL;
	return (1);
}

void	fdatabox(t_data *d)
{
	return ;
	d->img.sl += 0;
}
