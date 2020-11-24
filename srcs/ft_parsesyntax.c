/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsesyntax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:35:29 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/24 16:35:04 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_syntax	ft_syntaxinit(void)
{
	t_syntax	s;

	s.align_left = false;
	s.plus	= false;
	s.space = false;
	s.zero = false;
	s.hash = false;
	s.width = 0;
	s.precision = -1;
	s.length = def;
	s.conversion = 0;
	return (s);
}

int			ft_parseflags(char format, t_syntax *t_flags)
{
	const	char	*charset = "-+ 0#";

}

t_syntax	ft_parsesyntax(char *format, va_list va)
{
	 
}
