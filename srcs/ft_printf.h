/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:16:04 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/25 17:54:17 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# define BUFFER_SIZE 2048

typedef	enum	e_length
{
	def,
	l,
	ll,
	h,
	hh
}				t_length;

typedef	enum	e_bool
{
	false = 0,
	true = 1
}				t_bool;

typedef	struct	s_buffer
{
	char	content[BUFFER_SIZE];
	size_t	size;
}				t_buffer;

typedef	struct	s_syntax
{
	t_bool		align_left;
	t_bool		plus;
	t_bool		space;
	t_bool		zero;
	t_bool		hash;
	int			width;
	int			precision;
	t_length	length;
	int			type;
}				t_syntax;

t_buffer		ft_buffinit(void);
void			ft_buffflush(t_buffer *buffer);
void			ft_buffcat(t_buffer *buffer, char *s2, size_t size);
t_syntax		ft_parseflags(char **format, t_syntax syntax);
t_syntax		ft_syntaxinit(void);
t_syntax		ft_parsewidth(char **format, t_syntax syntax , va_list va);
t_syntax		ft_parseprecision(char **format, t_syntax syntax, va_list va);
t_syntax		ft_parselength(char **format, t_syntax syntax);
t_syntax		ft_parsetype(char **format, t_syntax syntax);
t_syntax		ft_parsesyntax(char **format, va_list va);
#endif
