/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:26 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/07 02:15:22 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		exit1(int err, t_data *d, char *msg)
{
	fdatabox(d);
	get_next_line(-10, NULL);
	if (err != 0)
		ft_printf("Error: %s\n", msg);
	else
		ft_putendl(msg);
	exit(0);
	return (1);
}

int		exit2(int err, t_data *d, char *del, char *msg)
{
	ft_strdel(&del);
	fdatabox(d);
	get_next_line(-10, NULL);
	if (err != 0)
		ft_printf("Error: %s\n", msg);
	else
		ft_putendl(msg);
	exit(0);
	return (1);
}
