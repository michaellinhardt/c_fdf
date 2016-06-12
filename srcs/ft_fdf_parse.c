/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 02:26:18 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/12 07:39:04 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		pclear(int err, t_data *d, t_map *m, char *msg)
{
	ft_strdel(&m->path);
	(m->fd > 0) ? close(m->fd) : 0;
	m->fd = 0;
	m->status = 0;
	(err == 1 && d->menu.open == 0) ? (d->menu.open = 1) : 0;
	l(1, "STOP PARSING", msg);
	return (1);
}

int		pformat(t_data *d, t_map *m, char c)
{
	m->fd = (m->fd == 0) ? open(m->path, O_RDONLY) : m->fd;
	if (m->fd < 0 || BUFF_SIZE < 1 || read(m->fd, m->read, 0) < 0)
		return(pclear(1, d, m, "cant read the map"));
	if ((m->i = -1) && (read(m->fd, m->read, BUFF_SIZE)) > 0)
		while ((c = m->read[++m->i]))
		{
			// if (!ft_isdigit(c[m->i]) && c[m->i] != ' ' && c[m->i] != '-'
			// && c[m->i] != '\n' && c[m->i] != '\0')
			// || (c[m->i] == ' ' && c[m->i + 1]) && (c[m->i + 1] == ' ' || c[m->i + 1] == '\n' || c[m->i + 1] == '\0')
				return(pclear(1, d, m, "map format error"));
		}
	else
		pclear(0, d, m, "read file complet");
	return (0);
}

void	parse(t_data *d, t_map *m)
{
	(m->status == 1) ? pformat(d, m, (char)NULL) : 0;
}
