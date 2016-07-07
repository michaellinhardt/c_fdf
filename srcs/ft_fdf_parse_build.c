/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse_build.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 04:16:52 by mlinhard          #+#    #+#             */
/*   Updated: 2016/07/07 22:51:46 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	pcol(t_map *m, int slot, char a, char b)
{
	int		vala;
	int		valb;

	if (a == '0' && b == '0' && !(m->col[m->y][m->x * 3 + slot] = 0))
		return ;
	(((a >= '0' && a <= '9') && ((vala = (a - '0')) || 1))
	|| ((a < 'a') && ((vala = (a - 55)) || 1))
	|| ((vala = (a - 87)) || 1)) ? (vala += 0) : 1;
	(((b >= '0' && b <= '9') && ((valb = (b - '0')) || 1))
	|| ((b < 'a') && ((valb = (b - 55)) || 1))
	|| ((valb = (b - 87)) || 1)) ? (valb += 0) : 1;
	m->col[m->y][m->x * 3 + slot] = (vala * 16) + valb;
}

void	pmallocarray(t_map *m)
{
	if (!(m->map = (int **)malloc(sizeof(int *) * m->ym)))
		exit1(1, data(), "Cant malloc.");
	m->y = -1;
	while (++m->y < m->ym)
		if (!(m->map[m->y] = (int *)malloc(sizeof(int) * m->xm)))
			exit1(1, data(), "Cant malloc.");
	if (!(m->col = (unsigned char **)malloc(sizeof(unsigned char *) * m->ym)))
		exit1(1, data(), "Cant malloc.");
	m->y = -1;
	while (++m->y < m->ym)
		if (!(m->col[m->y] = (unsigned char *)ft_strnew(
			(sizeof(unsigned char) * m->xm * 3) + 1)))
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
	z[6] = '\0';
	(m->j < 0) ? pcol(m, 0, li[m->i - 6], li[m->i - 5]) : pcol(m, 0, '0', '0');
	(m->j < 0) ? pcol(m, 1, li[m->i - 4], li[m->i - 3]) : pcol(m, 1, '0', '0');
	(m->j < 0) ? pcol(m, 2, li[m->i - 2], li[m->i - 1]) : pcol(m, 2, '0', '0');
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
