/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:42:35 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/28 17:15:16 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEST_H

# define FT_TEST_H

# include "../srcs/ft_printf.h"

void	ft_test_syntax(void);
void	ft_test_buffer(void);
void	ft_test_char(void);
int		ft_printf_no_flush(const char *format, t_buffer *buffer, ...);
void	ft_flush_nowrite(t_buffer *buffer);
int		ft_doconversion(t_syntax syntax, t_buffer *buffer, va_list va);

#endif