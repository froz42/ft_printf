/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:19:36 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/25 17:01:19 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_syntax	ft_parseflags(char **format, t_syntax syntax)
{
	const	char	*charset = "-+ 0#";

	while (ft_strchr(charset, **format))
	{
		if (**format == '-')
			syntax.align_left = true;
		else if (**format == '+')
			syntax.plus = true;
		else if (**format == ' ')
			syntax.space = true;
		else if (**format == '0')
			syntax.zero = true;
		else if (**format == '#')
			syntax.hash = true;
		(*format)++;
	}
	return (syntax);
}

t_syntax	ft_parsewidth(char **format, t_syntax syntax , va_list va)
{
	int		width;

	if (**format == '*')
	{
		width = va_arg(va, int);
		if (width < 0)
			syntax.width = -width;
		else
			syntax.width = width;
		(*format)++;
	}
	else
	{
		syntax.width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	return (syntax);
}

t_syntax	ft_parseprecision(char **format, t_syntax syntax, va_list va)
{
	int	precision;

	precision = 0;
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			precision = va_arg(va, int);
			if (precision > 0)
				syntax.precision = precision;
		}
		else
		{
			while (**format && ft_isdigit(**format))
				precision = precision * 10 + (*(*format)++ - 48);
		syntax.precision = precision;
		}
	}
	return (syntax);
}

t_syntax	ft_parselength(char **format, t_syntax syntax)
{
	if (ft_strncmp(*format, "ll", 2) == 0)
	{
		syntax.length = ll;
		(*format) += 2;
	}
	else if (ft_strncmp(*format, "hh", 2) == 0)
	{
		syntax.length = hh;
		(*format) += 2;
	}
	else if (ft_strncmp(*format, "h", 1) == 0)
	{
		syntax.length = h;
		(*format)++;
	}
	else if (ft_strncmp(*format, "l", 1) == 0)
	{
		syntax.length = l;
		(*format)++;
	}
	return (syntax);
}

t_syntax	ft_parsetype(char **format, t_syntax syntax)
{
	const	char	*charset = "cspdiuxX%nfge";
	int				result;

	result = ft_strchr(charset, **format) - charset;
	if (!result)
		syntax.type = -1;
	else
		syntax.type = result;
	return (syntax);
}