/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantropo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:30:35 by aantropo          #+#    #+#             */
/*   Updated: 2018/11/22 11:30:37 by aantropo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int		ft_parse_format(char *str, va_list args, int *i, t_format *format)
{
	int         format_start;
	int         format_end;

	*i = *i + 1;
	format_start = *i;
	format_end = format_start;
	if (!(format->type = ft_set_type(str, i, &format_end)))
		return (0);
	format->flags = ft_set_flags(str, format_start, *i);
	format->width = ft_set_width(str, format_start, *i, args);
	format->precision = ft_set_precision(str, format_start, *i, args);
	format->mod = ft_set_mod(str, format_start, *i);
	ft_take_arg(args, format);
	ft_putstr(format->string);
	return (ft_strlen(format->string));
}

int		ft_printf(const char *format, ...)
{
	int 	    i;
	char 	    *str;
	int         cnt;
	t_format    *format_str;
	va_list	args;

	format_str = (t_format *)malloc(sizeof(t_format));
	va_start(args, format);
	str = ft_strdup(format);
	cnt = 0;
	i = -1;
	while (str[++i])
	{
		while (str[i] && str[i] != '%')
			ft_putchar(str[i++]);
		if (str[i + 1] == '%')
		{
			ft_putchar('%');
			i += 2;
		}
		if (str[i] == '%')
			cnt += ft_parse_format(str, args, &i, format_str);
	}
	va_end(args);
	return (cnt);
}