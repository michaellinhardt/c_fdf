#include "ft_fdf.h"

// int		psetvalidchar(char valid[128])
// {
// 	valid['-'] = 1;
// 	return (1);
// }

// int		pchar_read_z(t_map *m)
// {
//
// 	if (m->seq == START && (m->seq = READ_Z) && c != '-' && !ft_isdigit(str[i]))
// 		return (0);
// 	while (m->read[m->i++])
// 		if (!ft_isdigit())
// 	return (1);
// }

int		pvalidchar(t_map *m, enum pseq *seq, char str[2049], int i)
{
	ft_printf("(%d, %d) Read [%d]: %c\n", m->x, m->ym, *seq, str[i]);
	if (!str[i])
		return (1);

	if (*seq == READ_SPACE && (str[i] == ' '))
		return (pvalidchar(m, seq, str, (i + 1)));
	else if (*seq == READ_SPACE && str[i] != '-' && !ft_isdigit(str[i]))
		return (0);
	else if (*seq == READ_SPACE)
		*seq = START_Z;

	if (*seq == START_Z && str[i] == '-' && (*seq = READ_Z) && ++m->x)
		return (pvalidchar(m, seq, str, (i + 1)));
	if (*seq == START_Z && !ft_isdigit(str[i]))
		return (exit1(0, data(), "START_Z invalide char"));
	if (*seq == START_Z && (*seq = READ_Z) && ++m->x)
		return (pvalidchar(m, seq, str, (i + 1)));

	if (*seq == READ_Z && ft_isdigit(str[i]))
		return (pvalidchar(m, seq, str, (i + 1)));
	else if (*seq == READ_Z && str[i] == ',' && (*seq = READ_COLOR))
		return (pvalidchar(m, seq, str, (i + 1)));
	else if (*seq == READ_Z && str[i] == ' ' && (*seq = READ_SPACE))
		return (pvalidchar(m, seq, str, (i + 1)));
	else if (*seq == READ_Z && str[i] == '\n' && !(*seq = START_Z))
	{
			m->ym++;
			if (m->xm == 0 && (m->xm = m->x))
				m->x = 0;
			else if (m->x != m->xm && ft_printf("%d != %d\n", m->x, m->xm))
				return (0);
			else
				m->x = 0;
			return (pvalidchar(m, seq, str, (i + 1)));
	}
	else if (*seq == READ_Z)
		return (0);



	return (1);
}
