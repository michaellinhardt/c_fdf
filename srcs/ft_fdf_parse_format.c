#include "ft_fdf.h"

int		pformatstart(t_map *m, enum pseq *seq, char c)
{
	if (*seq == START_Z && c == ' ' && (*seq = READ_SPACE))
		return (1);
	if (*seq == READ_SPACE)
	{
		if (c == ' ')
			return (1);
		else if (c == '\n' && (*seq = READ_Z))
			return (0);
		else if (c != '-' && !ft_isdigit(c))
			return (-999 * l(1, "MAP ERROR", "invalid char found"));
		else
			*seq = START_Z;
	}
	if (*seq == START_Z)
	{
		if ((c == '-' || ft_isdigit(c)) && (*seq = READ_Z) && ++m->x)
			return (1);
		else
			return (-999 * l(1, "MAP ERROR", "Z invalid first char"));
	}
	return (-1);
}

int		pformatz(t_map *m, enum pseq *seq, char c)
{
	if (*seq >= READ_Z && *seq <= READ_Z_11)
	{
		if (ft_isdigit(c) && *seq == READ_Z_11 && m->read[m->i - 10] != '-')
			return (-999 * l(1, "MAP ERROR", "Z overflow int type"));
		if ((ft_isdigit(c)
			&& (*seq = (*seq == READ_Z_11) ? READ_SPACE : *seq + 1))
			|| (c == ',' && (*seq = READ_COLOR_0))
			|| (c == ' ' && (*seq = READ_SPACE)))
			return (1);
		else if (c == '\n' && !(*seq = START_Z))
		{
				m->ym++;
				if (m->xm == 0 && (m->xm = m->x))
					m->x = 0;
				else if (m->x != m->xm)
					return (-999 * l(1, "MAP ERROR", "X size is invalid"));
				else
					m->x = 0;
				return (1);
		}
		else
			return (-999 * l(1, "MAP ERROR", "Z invalid char found"));
	}
	return (-1);
}

int		pformatcolor(enum pseq *seq, char c, char cc)
{
	if (*seq == READ_COLOR_0 && c != '0')
		return (-999 * l(1, "MAP ERROR", "color first char is not '0'"));
	else if (*seq == READ_COLOR_0 && (*seq += 1))
		return (1);
	if (*seq == READ_COLOR_X && c != 'x' && c != 'X')
		return (-999 * l(1, "MAP ERROR", "color second char is not 'x'"));
	else if (*seq == READ_COLOR_X && (*seq += 1))
		return (1);
	if (*seq == READ_COLOR_6
		&& cc && cc != ' ' && cc != '\n')
		return (-999 * l(1, "MAP ERROR", "color end with bad char"));
	if (*seq >= READ_COLOR_1 && *seq <= READ_COLOR_6 && !ft_isdigit(c)
	&& (c < 'a' || c > 'f') && (c < 'A' || c > 'F'))
		return (-999 * l(1, "MAP ERROR", "color invalid char found"));
	else if (*seq >= READ_COLOR_1 && *seq <= READ_COLOR_6 && (*seq += 1))
		return (1);
	return (-1);
}

int		pformatcheck(t_map *m, enum pseq *seq, char str[BUFF_SIZE], int i)
{
	int		ret;

	while (str[i] || ((read(m->fd, m->read, BUFF_SIZE)) > 0 && !(i = 0)))
	{
		(i > 0) ? (str[i - 1] = '\0') : 0;
		if (!str[i] || (*seq == START_Z && str[i] == '\n' && !str[i + 1]))
			return (1);
		if ((ret = pformatstart(m, seq, str[i])) == -999)
			return (0);
		else if (ret > -1 && (i += ret))
			continue ;
		if ((ret = pformatz(m, seq, str[i])) == -999)
			return (0);
		else if (ret > -1 && (i += ret))
			continue ;
		if ((ret = pformatcolor(seq, str[i]
			, ((str[i + 1]) ? str[i + 1] : (char)NULL))) == -999)
			return (0);
		else if (ret > -1 && (i += ret))
			continue ;
	}
	return (1);
}
