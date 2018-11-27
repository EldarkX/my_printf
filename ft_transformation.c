/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transformation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantropo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:48:33 by aantropo          #+#    #+#             */
/*   Updated: 2018/11/26 15:54:27 by aantropo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char	*ft_transform_int(va_list args, t_format *format)
{
	intmax_t	nbr;

	if (format->mod == 0)
		nbr = va_arg(args, long);
	else if (format->mod == 1)
		nbr = va_arg(args, long long);
	else if (format->mod == 2)
		nbr = (short)va_arg(args, int);
	else if (format->mod == 3)
		nbr = (char)va_arg(args, int);
	else if (format->mod == 4)
		nbr = va_arg(args, intmax_t);
	else
		nbr = va_arg(args, int);
	return (ft_itoa_base(nbr, 10));
}

void	ft_take_arg(va_list args, t_format *format)
{
	char		*string;

	if (format->type == 's')
		string = ft_strdup(va_arg(args, char *));
	else if (format->type == 'd' || format->type == 'i')
		string = ft_strdup(ft_transform_int(args, format));
	format->string = ft_strdup(string);
}
