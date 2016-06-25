/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 02:26:18 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/26 01:21:44 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		pclear(int err, t_data *d, t_map *m, char *msg)
{
	ft_strdel(&m->path);
	(m->fd > 0) ? close(m->fd) : 0;
	m->fd = 0;
	m->status = 0;
	m->seq = START_Z;
	(err == 1 && d->menu.open == 0) ? (d->menu.open = 1) : 0;
	l(1, "STOP PARSING", msg);
	return (1);
}

int		pformat(t_data *d, t_map *m)
{
	if (m->fd == 0)
		m->fd = open(m->path, O_RDONLY);
	if (m->fd < 0 || BUFF_SIZE < 1 || read(m->fd, m->read, 0) < 0)
		return(pclear(1, d, m, "cant read the map"));
	if ((read(m->fd, m->read, BUFF_SIZE)) > 0)
	{
		if (!pvalidchar(m, &m->seq, m->read, 0))
			return (pclear(1, d, m, "map format error"));
	}
	else
		pclear(0, d, m, "read file complet");
	return (0);
}

void	parse(t_data *d, t_map *m)
{
	(m->status == 1) ? pformat(d, m) : 0;
}
