/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 02:26:18 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/11 18:55:15 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		pclear(int err, t_data *d, t_map *m, char *msg)
{
	l(1, (m->path + ft_strlen(MAP_DIR) - 2), msg);
	ft_strdel(&m->path);
	(m->fd > 0) ? close(m->fd) : 0;
	m->fd = 0;
	m->x = 0;
	m->status = (err == 1) ? 0 : -1;
	(err == 1) ? (fmap(d, -1, 0)) : 0;
	(err == 1 && d->menu.open == 0) ? (d->menu.open = 1) : 0;
	return (1);
}

// int		sizex;
// int		sizey;
// int		winx;
// int		winy;
//
// winx = (DRAW_X2 - DRAW_X1 - BORDERX);
// winy = (DRAW_Y2 - DRAW_Y1 - BORDERY);
// sizex = winx / m->xm;
// sizey = winy / m->ym;
// // ft_printf("xm: %d\nym: %d\n", m->xm, m->ym);
// // ft_printf("winx: %d\nwint: %d\nsizex: %d\nsizey: %d\n", winx, winy, sizex, sizey);
// if (sizex * m->ym > winy)
// 	m->size = sizey;
// else if (sizey * m->xm > winx)
// 	m->size = sizex;
// else
// 	m->size = (sizex >= sizey) ? sizex : sizey;
// if (!m->size)
// 	m->size = 3;

void	pinit(t_map *m, int areax, int areay, char *s)
{
	int		sizex;
	int		sizey;

	s = m->path + ft_strlen(MAP_DIR) - ((m->path[0] == '.') ? 0 : 2);
	l(1, s, "calc bloc size");
	areax = WIN_X - BORDERX * 2;
	areay = WIN_Y - BORDERY * 2;
	sizex = areax / m->xm;
	sizey = areay / (m->ym + 1);
	if (sizex * m->ym > areay)
		m->size = sizey;
	else if (sizey * m->xm > areax)
		m->size = sizex;
	else
		m->size = (sizex >= sizey) ? sizex : sizey;
	if (!m->size)
		m->size = 3;
	m->posx = BORDERX + ((areax - m->size * m->xm) / 2);
	m->posy = BORDERY + ((areay - m->size * (m->ym - 1)) / 2);
}

int		pbuild(t_data *d, t_map *m)
{
	char	*s;

	close(m->fd);
	m->fd = open(m->path, O_RDONLY);
	s = m->path + ft_strlen(MAP_DIR) - ((m->path[0] == '.') ? 0 : 2);
	l(1, s, "build int array");
	if (m->fd < 0 || BUFF_SIZE < 1 || read(m->fd, m->read, 0) < 0)
		return(pclear(1, d, m, "! cant read the map"));
	if (!pbuildarray(m, (char *)NULL))
		return (pclear(1, d, m, "! build int array error"));
	close(m->fd);
	m->status = -1;
	pinit(m, 0, 0, (char *)NULL);
	loop(1);
	return (0);
}

int		pformat(t_data *d, t_map *m)
{
	char	*s;

	if (!ft_strstr(m->path, ".fdf"))
		return(pclear(1, d, m, "! invalid map name"));
	m->fd = open(m->path, O_RDONLY);
	s = m->path + ft_strlen(MAP_DIR) - ((m->path[0] == '.') ? 0 : 2);
	l(1, s, "format verification");
	if (m->fd < 0 || BUFF_SIZE < 1 || read(m->fd, m->read, 0) < 0)
		return(pclear(1, d, m, "! cant read the map"));
	if (!pformatcheck(m, (char *)NULL))
		return (pclear(1, d, m, "! map format error"));
	m->status = 2;
	return (0);
}

void	parse(t_data *d, t_map *m)
{
	(m->status == 1) ? pformat(d, m) : 0;
	(m->status == 2) ? pbuild(d, m) : 0;
}
