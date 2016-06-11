/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 02:26:18 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/11 10:13:40 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

// int				get_next_line(int fd, char **line)
// {
// 	t_gnl		*g;
//
// 	if (fd == -10)
// 		return (gnl_free());
// 	if (fd < 0 || !(line) || BUFF_SIZE < 1 || !(g = gnl_choose(fd, NULL)) ||
// 		read(fd, g->b, 0) < 0)
// 		return (-1);
// 	while (!(ft_strchr(g->s, '\n')) && (g->r = read(fd, g->b, BUFF_SIZE)) > 0)
// 	{
// 		g->t = g->s;
// 		if (!(g->b[g->r] = '\0'))
// 			g->s = ft_strjoin(g->t, g->b);
// 		ft_strdel(&g->t);
// 	}
// 	while (g->s[g->i] && g->s[g->i] != '\n' && g->s[g->i] != '\0')
// 		g->i++;
// 	if (g->r == 0 && g->i == 0)
// 		return (gnl_delete(g));
// 	*line = ft_strsub(g->s, 0, (g->i));
// 	g->t = g->s;
// 	g->s = (g->t[g->i] == '\0') ? ft_strnew(0) : ft_strsub(g->t,
// 	(g->i + 1), (ft_strlen(g->t) - g->i));
// 	return (1);
// }

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
			// || (c[m->i] == ' ' && c[m->i + 1])
			// 		 && (c[m->i + 1] == ' ' || c[m->i + 1] == '\n' || c[m->i + 1] == '\0' ||
			// return(pclear(1, d, m, "map format error"));
		}
	else
		pclear(0, d, m, "read file complet");
	return (0);
}

void	parse(t_data *d, t_map *m)
{
	ft_printf("%d %d %d\n", m->i, m->xm, m->ym);
	(m->status == 1) ? pformat(d, m, (char)NULL) : 0;
}
