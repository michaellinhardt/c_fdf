/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 22:11:26 by mlinhard          #+#    #+#             */
/*   Updated: 2016/06/03 01:06:24 by mlinhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		exit1(t_data *d, char *msg)
{
	fdatabox(d);
	get_next_line(-10, NULL);
	exit(0);
	return (1);
}

int		exit2(t_data *d, char *del, char *msg)
{
	ft_strdel(&del);
	fdatabox(d);
	get_next_line(-10, NULL);
	exit(0);
	return (1);
}
