/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 13:34:19 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/16 14:12:53 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*p;

	p = (unsigned char *)b;
	while (len-- > 0)
		*p++ = (unsigned char)c;
	return (b);
}
