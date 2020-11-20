/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:31:51 by tmatis            #+#    #+#             */
/*   Updated: 2020/11/16 12:35:07 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_is_uppercase(char *str)
{
	while (*str && ft_isupper(*str))
		str++;
	return (!*str || ft_isupper(*str));
}
