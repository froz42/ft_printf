/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:16:04 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/23 18:42:52 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# define BUFFER_SIZE 2048

typedef	struct	s_buffer
{
	char	content[BUFFER_SIZE];
	size_t	size;
}				t_buffer;

t_buffer	ft_buffinit(void);
void		ft_buffflush(t_buffer *buffer);
void		ft_buffcat(t_buffer *buffer, char *s2, size_t size);
#endif
