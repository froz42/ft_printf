/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:51:21 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/13 16:55:40 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_wstrtostr(char *dest, int *wsrc)
{
	char	buff[4];
	size_t	i;
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
	dest[len++] = '\0';
	return (len);
}

char	*ft_wstrtostr_malloc(int *wsrc)
{
	char	buff[4];
	size_t	i;
	size_t	len;
	int		buffed;
	char	*dest;

	i = 0;
	len = 0;
	dest = (char *)malloc(sizeof(char));
	while (wsrc[i])
	{
		buffed = ft_utf8_encode(wsrc[i++], buff);
		dest = ft_realloc(dest, len, buffed);
		memcpy(dest + len, buff, buffed);
		len += buffed;
	}
	dest[len++] = '\0';
	return (dest);
}
