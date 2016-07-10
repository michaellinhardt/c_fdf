/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 22:38:39 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/10 01:49:51 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		pseq(t_map *m, char *li, int *i)
{
	while (li[*i] && li[*i] != ' ' && li[*i] != ',' && ++m->j)
	{
		if (li[*i] == '-' && m->j == 1 && (*i)++)
			continue ;
		if (!ft_isdigit(li[*i]))
			return (0 * l(1, "PARSING", "Z invalid char"));
		if (m->j > 11 || (m->j == 11 && li[*i - m->j] != '-'))
			return (0 * l(1, "PARSING", "Z overflow int size"));
		*i += 1;
	}
	m->j = -1;
	while (li[*i] && li[*i] != ' ' && (++m->j || 1))
	{
		if (m->j == 0 && (li[*i] != ',' || !li[*i + 1] || !li[*i + 2]
		|| li[*i + 1] != '0' || (li[*i + 2] != 'x' && li[*i + 2] != 'X')))
			return (0 * l(1, "PARSING", "color dont start with 0x or 0X"));
		else if (m->j == 0 && (*i += 3))
			continue ;
		if (m->j > 6 || (!ft_isdigit(li[*i])
		&& ((li[*i] < 'a' || li[*i] > 'f') && (li[*i] < 'A' || li[*i] > 'F'))))
			return (0 * l(1, "PARSING", "color is not hexa"));
		*i += 1;
	}
	return (1);
}

int		pformatcheck(t_map *m, char *line)
{
	m->xm = 0;
	m->ym = 0;
	while (ft_strdel(&line) && (get_next_line(m->fd, &line)) > 0 && (m->x = -1))
	{
		m->i = -1;
		while (line[++m->i])
			if (line[m->i] != ' ' && (++m->x || 1) && !(m->j = 0)
			&& (!pseq(m, line, &m->i)))
				return (0);
			else if (!line[m->i])
				break ;
		(!m->xm) ? (m->xm = m->x) : 0;
		if (m->x != m->xm || m->xm < 2)
			return (0 * l(1, "PARSING", "X total is wrong"));
		m->ym++;
	}
	if (m->ym < 2)
		return (0 * l(1, "PARSING", "Y total is wrong"));
	return (1);
}
