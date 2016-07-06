/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse_build.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 04:16:52 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/06 06:12:25 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		phextoi(char z[11], int col, int i, int slot)
{
	while (++i < 6)
	{
		(((z[i] >= '0' && z[i] <= '9') && ((slot = (z[i] - '0')) || 1))
		|| ((z[i] < 'a') && ((slot = (z[i] - 55)) || 1))
		|| ((slot = (z[i] - 87)) || 1)) ? (i += 0) : 1;
		(i == 0) ? (col += slot * 1048576) : 0;
		(i == 1) ? (col += slot * 65536) : 0;
		(i == 2) ? (col += slot * 4096) : 0;
		(i == 3) ? (col += slot * 256) : 0;
		(i == 4) ? (col += slot * 16) : 0;
		(i == 5) ? (col += slot) : 0;
	}
	return (col);
}

void	pmallocarray(t_map *m)
{
	if (!(m->map = (int **)malloc(sizeof(int *) * m->ym)))
		exit1(1, data(), "Cant malloc.");
	m->y = -1;
	while (++m->y < m->ym)
		if (!(m->map[m->y] = (int *)malloc(sizeof(int) * m->xm)))
			exit1(1, data(), "Cant malloc.");
	if (!(m->col = (char **)malloc(sizeof(char *) * m->ym)))
		exit1(1, data(), "Cant malloc.");
	m->y = -1;
	while (++m->y < m->ym)
		if (!(m->col[m->y] = (char *)ft_strnew((sizeof(char) * m->xm * 6) + 1)))
			exit1(1, data(), "Cant malloc.");
}

int		pseqrec(t_map *m, char *li, int *i, intmax_t verif)
{
	char	z[11];

	while (li[*i] && li[*i] != ' ' && li[*i] != ',' && ++m->j)
		*i += 1;
	ft_memcpy(z, &(li[m->i - m->j]), m->j);
	z[m->j] = '\0';
	verif = ft_atoimax(z);
 	if (verif > INT_MAX || verif < INT_MIN)
		return (0 * l(1, "BUILD ARRAY", "Z overflow int size"));
	m->map[m->y][m->x] = (int)verif;
	if (li[*i] && li[*i] == ',' && (m->j = -999))
		*i += 9;
	(m->j < 0) ? ft_memcpy(&(m->col[m->y][m->x * 6]), &(li[m->i - 6]), 6)
	: ft_memcpy(&(m->col[m->y][m->x * 6]), "000000", 6);
	return (1);
}

int		pbuildarray(t_map *m, char *line)
{
	pmallocarray(m);
	m->y = 0;
	while (ft_strdel(&line) && (get_next_line(m->fd, &line)) > 0 && (m->x = -1))
	{
		m->i = -1;
		while (line[++m->i])
			if (line[m->i] != ' ' && (++m->x || 1) && !(m->j = 0)
			&& (!pseqrec(m, line, &m->i, 0)))
				return (0);
			else if (!line[m->i])
				break ;
		m->y++;
	}
	return (1);
}
