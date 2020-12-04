/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 12:09:06 by tmatis            #+#    #+#             */
/*   Updated: 2020/12/04 12:16:41 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *src, size_t size, size_t addbyte)
{
	char	*csrc;
	char	*cdest;

	csrc = (char *)src;
	cdest = (char *)malloc((size + addbyte) * sizeof(char));
	ft_memcpy(cdest, csrc, size);
	free(src);
	return ((void *) cdest);
}
