/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 02:26:18 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/29 08:00:27 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include <limits.h>

int		pclear(int err, t_data *d, t_map *m, char *msg)
{
	l(1, m->path, msg);
	ft_strdel(&m->path);
	(m->fd > 0) ? close(m->fd) : 0;
	m->fd = 0;
	m->x = 0;
	m->status = (err == 1) ? 0 : -1;
	m->seq = START_Z;
	(err == 1 && d->menu.open == 0) ? (d->menu.open = 1) : 0;
	return (1);
}

int		pformat(t_data *d, t_map *m)
{
	m->fd = open(m->path, O_RDONLY);
	l(1, m->path, "is loading");
	m->x = 0;
	m->xm = 0;
	m->ym = 0;
	if (m->fd < 0 || BUFF_SIZE < 1 || read(m->fd, m->read, 0) < 0)
		return(pclear(1, d, m, "! cant read the map"));
	if (!pformatcheck(m, &m->seq, m->read, 0))
		return (pclear(1, d, m, "! map format error"));
	l(1, m->path, "read once -> format ok");
	m->status = 2;
	return (0);
}

void	parse(t_data *d, t_map *m)
{
	(m->status == 1 && !(m->seq = START_Z)) ? pformat(d, m) : 0;
	exit (0);
}
