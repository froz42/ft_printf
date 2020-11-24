/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:22:13 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/23 18:41:58 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

t_buffer	ft_buffinit(void)
{
	t_buffer buff;
	buff.size = 0;
	return (buff);
}

void		ft_buffflush(t_buffer *buffer)
{
	write(1, buffer->content, buffer->size);
	buffer->size = 0;
}

void		ft_buffcat(t_buffer *buffer, char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (&buffer->content[buffer->size] == &buffer->content[BUFFER_SIZE])
			ft_buffflush(buffer);
		buffer->content[buffer->size++] = s2[i];
		i++;
	}
}

