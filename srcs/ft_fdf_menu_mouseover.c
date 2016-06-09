/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_menu_mouseover.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 15:01:51 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/09 15:40:40 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	menu_mouseover(t_data *d, t_menu *m)
{
	(m->u && mo(ARROWU) && m->mo != ARROWU && (m->mo = ARROWU)) ? loop(1) : 0;
	(m->u && !mo(ARROWU) && m->mo == ARROWU && !(m->mo = INIT)) ? loop(1) : 0;
	(m->d && mo(ARROWD) && m->mo != ARROWD && (m->mo = ARROWD)) ? loop(1) : 0;
	(m->d && !mo(ARROWD) && m->mo == ARROWD && !(m->mo = INIT)) ? loop(1) : 0;
}
