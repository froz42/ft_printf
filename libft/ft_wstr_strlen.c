/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:23:21 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/04 14:28:56 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstr_strlen(int *wstr)
{
	char	buff[4];
	int		strlen;
	int		buffed;

	strlen = 0;
	while (*wstr)
	{
		buffed = ft_utf8_encode(*wstr++, buff);
		strlen += buffed;
	}
	return (strlen);
}
