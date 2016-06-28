#include "ft_fdf.h"

int		pvalidchar_3(enum pseq *seq, char c, char cc)
{
	if (*seq == READ_COLOR_0 && c != '0')
		return (-999);
	else if (*seq == READ_COLOR_0 && (*seq += 1))
		return (1);
	if (*seq == READ_COLOR_X && c != 'x' && c != 'X')
		return (-999);
	else if (*seq == READ_COLOR_X && (*seq += 1))
		return (1);
	if (*seq == READ_COLOR_6
		&& cc && cc != ' ' && cc != '\n')
		return (-999);
	if (*seq >= READ_COLOR_1 && *seq <= READ_COLOR_6 && !ft_isdigit(c)
	&& (c < 'a' || c > 'f') && (c < 'A' || c > 'F'))
		return (-999);
	else if (*seq >= READ_COLOR_1 && *seq <= READ_COLOR_6 && (*seq += 1))
		return (1);
	return (-1);
}

int		pvalidchar_2(t_map *m, enum pseq *seq, char c)
{
	if (*seq == READ_Z && ft_isdigit(c))
		return (1);
	else if (*seq == READ_Z && c == ',' && (*seq = READ_COLOR_0))
		return (1);
	else if (*seq == READ_Z && c == ' ' && (*seq = READ_SPACE))
		return (1);
	else if (*seq == READ_Z && c == '\n' && !(*seq = START_Z))
	{
			m->ym++;
			if (m->xm == 0 && (m->xm = m->x))
				m->x = 0;
			else if (m->x != m->xm)
				return (-999);
			else
				m->x = 0;
			return (1);
	}
	else if (*seq == READ_Z)
		return (-999);
	if (*seq == READ_Z && ft_isdigit(c))
		return (1);
	return (-1);
}

int		pvalidchar_1(t_map *m, enum pseq *seq, char c)
{
	if (*seq == START_Z && c == ' ' && (*seq = READ_SPACE))
		return (1);
	if (*seq == READ_SPACE && (c == ' '))
		return (1);
	else if (*seq == READ_SPACE && (c == '\n') && (*seq = READ_Z))
		return (0);
	else if (*seq == READ_SPACE && c != '-' && !ft_isdigit(c))
		return (-999);
	else if (*seq == READ_SPACE)
		*seq = START_Z;
	if (*seq == START_Z && c == '-' && (*seq = READ_Z) && ++m->x)
		return (1);
	if (*seq == START_Z && !ft_isdigit(c))
		return (-999);
	if (*seq == START_Z && (*seq = READ_Z) && ++m->x)
		return (1);
	return (-1);
}

int		pvalidchar(t_map *m, enum pseq *seq, char str[BUFF_SIZE], int i)
{
	int		ret;

	while (str[i])
	{
		(str[i - 1]) ? (str[i - 1] = '\0') : 0;
		if (!str[i] || (*seq == START_Z && str[i] == '\n' && !str[i + 1]))
			return (1);
		if ((ret = pvalidchar_1(m, seq, str[i])) == -999)
			return (0);
		else if (ret > -1 && (i += ret))
			continue ;
		if ((ret = pvalidchar_2(m, seq, str[i])) == -999)
			return (0);
		else if (ret > -1 && (i += ret))
			continue ;
		if ((ret = pvalidchar_3(seq, str[i]
			, ((str[i + 1]) ? str[i + 1] : (char)NULL))) == -999)
			return (0);
		else if (ret > -1 && (i += ret))
			continue ;
	}
	return (1);
}
