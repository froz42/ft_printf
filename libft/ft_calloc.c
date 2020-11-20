/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:36:17 by tmatis            #+#    #+#             */
/*   Updated: 2020/10/17 18:08:17 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (!count || !size)
	{
		size = 1;
		count = 1;
	}
	dst = malloc(size * count);
	if (dst)
		ft_bzero(dst, size * count);
	return (dst);
}
