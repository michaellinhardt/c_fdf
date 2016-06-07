/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:32 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 11:13:45 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	fascii(int ico, char *type, char *data)
{
	wchar_t		uni;
	char		msg[4096];

	uni = (ico == 1) ? L'✅' : L'❌';
	(ico == 1) ?
	ft_memcpy(msg, "free'ed\0", 8) : ft_memcpy(msg, "already empty\0", 14);
	ft_printf("  %C║ %13s ║ %-24s ║ %-24s ║\n", uni, type, data, msg);
}

int		flmenu(t_data *d)
{
	t_lmenu	*lst;
	t_lmenu	*del;

	if (!d->menu.lst)
		return (1);
	lst = d->menu.lst;
	while (lst)
	{
		del = lst;
		lst = lst->p;
		ft_memdel((void **)&del);
	}
	d->menu.lst = NULL;
	return (1);
}

void	fdestroyimg(t_data *d)
{
	fascii(((d->img.img) ? 1 : 0), "t_img *", "d->img.img");
	(d->img.img) ? mlx_destroy_image(d->mlx, d->img.img) : 0;
	fascii(((d->intro.img) ? 1 : 0), "t_img *", "d->intro.img");
	(d->intro.img) ? mlx_destroy_image(d->mlx, d->intro.img) : 0;
	fascii(((d->pressany.img) ? 1 : 0), "t_img *", "d->pressany.img");
	(d->pressany.img) ? mlx_destroy_image(d->mlx, d->pressany.img) : 0;
	fascii(((d->bkg.img) ? 1 : 0), "t_img *", "d->bkg.img");
	(d->bkg.img) ? mlx_destroy_image(d->mlx, d->bkg.img) : 0;
	fascii(((d->imenu.img) ? 1 : 0), "t_img *", "d->imenu.img");
	(d->imenu.img) ? mlx_destroy_image(d->mlx, d->imenu.img) : 0;
	fascii(((d->btnact.img) ? 1 : 0), "t_img *", "d->btnact.img");
	(d->btnact.img) ? mlx_destroy_image(d->mlx, d->btnact.img) : 0;
	fascii(((d->btnoff.img) ? 1 : 0), "t_img *", "d->btnoff.img");
	(d->btnoff.img) ? mlx_destroy_image(d->mlx, d->btnoff.img) : 0;
	fascii(((d->btnover.img) ? 1 : 0), "t_img *", "d->btnover.img");
	(d->btnover.img) ? mlx_destroy_image(d->mlx, d->btnover.img) : 0;
}

void	fdatabox(t_data *d)
{
	pascii(ASC_FREEDATA);
	fascii(((d->map) ? 1 : 0), "char *", "d->map");
	ft_strdel(&d->map);
	fascii(((d->menu.lst) ? 1 : 0), "t_lmenu *", "d->menu.lst");
	flmenu(d);
	fascii(1, "t_gnl *", "gnl->fd");
	get_next_line(-10, NULL);
	fdestroyimg(d);
	ft_putstr("  🎼╚═══════════════╩══════════════════════");
	ft_putendl("════╩══════════════════════════╝");
}
