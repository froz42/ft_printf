/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:24:51 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/29 18:20:29 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	ft_strnlen_s(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (s[i] && i < maxlen)
		i++;
	return (i);
}

static	char	*ft_strncpy_s(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	while (*s && start--)
		s++;
	dest = malloc((ft_strnlen_s(s, len) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strncpy_s(dest, s, len);
	dest[len] = '\0';
	return (dest);
}
