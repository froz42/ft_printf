/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 19:45:40 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/29 18:16:52 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnlen_s(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (s[i] && i < maxlen)
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const	size_t	srclen = ft_strlen(src);
	const	size_t	dstlen = ft_strnlen_s(dst, dstsize);

	if (dstlen == dstsize)
		return (dstsize + srclen);
	if (srclen < dstsize - dstlen)
		ft_memcpy(dst + dstlen, src, srclen + 1);
	else
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dstlen + srclen);
}
