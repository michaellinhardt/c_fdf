/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 02:26:18 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/29 10:02:19 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		pclear(int err, t_data *d, t_map *m, char *msg)
{
	char	*s;

	s = m->path + ft_strlen(MAP_DIR) - 2;
	l(1, s, msg);
	ft_strdel(&m->path);
	(m->fd > 0) ? close(m->fd) : 0;
	m->fd = 0;
	m->x = 0;
	m->status = (err == 1) ? 0 : -1;
	m->seq = START_Z;
	(err == 1 && d->menu.open == 0) ? (d->menu.open = 1) : 0;
	return (1);
}

void	preadandbuild(t_map *m, char c, long int verif, char *zptr)
{
	verif += 0;

	m->i = -1;
	while (m->read[++m->i]
	|| ((read(m->fd, m->read, BUFF_SIZE)) > 0 && !(m->i = 0)
	&& (zptr = m->read)))
	{
		ft_printf("%c\n", *zptr);
		if (((c = m->read[m->i]) == ' ' || c == '\n') && m->seq == READ_Z
		&& (m->seq = START_Z))
		{
			while ((int)*zptr != (int)m->read[m->i])
			{
				ft_putstr(*zptr);
				*zptr++;
			}
			// m->map[m->y][m->x] = ft_atoi(*zptr + (*m->read[m->i] - *zptr));
			(c == '\n') ? m->i-- : 0;
			continue ;
		}
		if (c == ' ' && !(m->seq = START_Z))
			continue ;
		if (c == '\n' && !(m->seq = START_Z) && ++m->y)
			continue ;
		if ((c == '-' || ft_isdigit(c))
			&& m->seq == START_Z && (m->seq = READ_Z))
			*zptr = m->read[m->i + (0 * ++m->x)];
			// *zptr = *(m->read[m->i + (0 * ++m->x)]);
		else if (m->seq == READ_Z && c == ',' && (m->seq = READ_COLOR_0))
			continue ;

	}
	exit (0);
}

int		pbuildarray(t_data *d, t_map *m)
{
	m->y = -1;
	if (!(m->map = (int **)malloc(sizeof(int *) * m->ym)))
		exit1(1, d, "Cant malloc.");
	while (++m->y < m->ym)
		if (!(m->map[m->y] = (int *)malloc(sizeof(int) * m->xm)))
			exit1(1, d, "Cant malloc.");
	close(m->fd);
	m->fd = open(m->path, O_RDONLY);
	m->x = -1;
	m->y = 0;
	preadandbuild(m, (char)NULL, 0, (char *)NULL);
	return (0);
}

int		pformat(t_data *d, t_map *m)
{
	char	*s;

	if (!ft_strstr(m->path, ".fdf"))
		return(pclear(1, d, m, "! invalid map name"));
	m->fd = open(m->path, O_RDONLY);
	s = m->path + ft_strlen(MAP_DIR) - 2;
	l(1, s, "parsing & building int array");
	m->x = 0;
	m->xm = 0;
	m->ym = 0;
	if (m->fd < 0 || BUFF_SIZE < 1 || read(m->fd, m->read, 0) < 0)
		return(pclear(1, d, m, "! cant read the map"));
	if (!pformatcheck(m, &m->seq, m->read, 0))
		return (pclear(1, d, m, "! map format error"));
	if (m->ym == 1 || (m->ym == 2 && m->xm < 2))
		return (pclear(1, d, m, "! map size error"));
	l(1, s, "format ok");
	m->status = 2;
	return (0);
}

void	parse(t_data *d, t_map *m)
{
	(m->status == 1 && !(m->seq = START_Z)) ? pformat(d, m) : 0;
	(m->status == 2 && !(m->seq = START_Z)) ? pbuildarray(d, m) : 0;
	exit (0);
}
