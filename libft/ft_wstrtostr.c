/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:51:21 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/03 21:04:40 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrtostr(char *dest, int *wsrc)
{
	char	buff[4];
	size_t  i;
	size_t	len;
	int		buffed;

	i = 0;
	len = 0;
	while (wsrc[i])
	{
		buffed = ft_utf8_encode(wsrc[i++], buff);
		memcpy(dest + len, buff, buffed);
		len += buffed;
	}
	return (len);
}
