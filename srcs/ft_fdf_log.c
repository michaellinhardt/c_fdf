#include "ft_fdf.h"

int		l1(int ico, char *name, char *info)
{
	wchar_t		uni;
	t_data		*d;

	d = data();
	(ico == 1) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 2) ? (uni = L'🕹') : (wchar_t)NULL;
	(ico == 3) ? (uni = L'🖥') : (wchar_t)NULL;
	(ico == 4) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 5) ? (uni = L'🎦') : (wchar_t)NULL;
	(ico == 6) ? (uni = L'🖱') : (wchar_t)NULL;
	(ico == 7) ? (uni = L'➿') : (wchar_t)NULL;
	(ico == 8) ? (uni = L'❎') : (wchar_t)NULL;
	(ico == 9) ? (uni = L'🆕') : (wchar_t)NULL;
	(ico == 10) ? (uni = L'➿') : (wchar_t)NULL;
	ft_printf(" %C %s %20s  %s  %-47s %s\n", uni, LINE_BLUE, name
	, LINE_GREEN2, info, LINE_YEL);
	ico = (ico == 7) ? (ft_printf("\e[93m") + ft_printf("🎼  ╠")
	+ ft_printf("\e[90m") + ft_printf("═══════════════════════")
	+ ft_printf("\e[93m")+ ft_printf("╬") + ft_printf("\e[90m")
	+ ft_printf("══════════════════════════════════════════════════")
	+ ft_printf("\e[93m")+ ft_printf("╣\n")) : 1;
	return (1);
}

int		l2(int ico, char *name, char *info, int val)
{
	wchar_t		uni;
	t_data		*d;

	d = data();
	if (ico == 2 && !LOG_KEY)
		return (1);
	(ico == 1) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 2) ? (uni = L'🕹') : (wchar_t)NULL;
	(ico == 3) ? (uni = L'🖥') : (wchar_t)NULL;
	(ico == 4) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 5) ? (uni = L'📗') : (wchar_t)NULL;
	(ico == 6) ? (uni = L'🖱') : (wchar_t)NULL;
	(ico == 7) ? (uni = L'➿') : (wchar_t)NULL;
	ft_printf(" %C %s %20s  %s  %-4d%-43s %s\n", uni, LINE_BLUE, name
	, LINE_GREEN2, val, info, LINE_YEL);
	return (1);
}

int		l3(int ico)
{
	wchar_t		uni;
	t_data		*d;
	static char *strnum[] = { "-> INTRO_LOAD", "-> INTRO_MENU", "-> INTRO_OUT"
							, "-> MAIN_LOAD", "-> MAIN" };

	d = data();
	uni = L'🎦';
	ico = (ico == 1) ? (ft_printf("\e[93m") + ft_printf("🎼  ╠")
	+ ft_printf("\e[90m") + ft_printf("═══════════════════════")
	+ ft_printf("\e[93m")+ ft_printf("╬") + ft_printf("\e[90m")
	+ ft_printf("══════════════════════════════════════════════════")
	+ ft_printf("\e[93m")+ ft_printf("╣\n")) * 0 + 1 : ico;
	if (ico == 0)
		ft_printf(" %C %s %20s  %s  %-47s %s\n", uni, LINE_BLUE, "SCENE INIT"
	, LINE_GREEN2, strnum[d->scene], LINE_YEL);
	else
		ft_printf(" %C %s %20s  %s  %23s %-23s %s\n", uni, LINE_BLUE
		, "SCENE CHANGE"
	, LINE_GREEN2, strnum[d->scenelast], strnum[d->scene], LINE_YEL);
	return (1);
}

int		l4(int btn, int x, int y, char *action)
{
	if (!LOG_MOUSE)
		return (1);
	ft_printf(" 🖱 %s %20s  %s  x %-5d y %-5d%-32s %s\n", LINE_BLUE
	, ((btn == 1) ? "MOUSE LEFT" : "MOUSE RIGHT")
	, LINE_GREEN2, x, y, action, LINE_YEL);
	return (1);
}
