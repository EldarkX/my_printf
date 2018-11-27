/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_filler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantropo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:17:38 by aantropo          #+#    #+#             */
/*   Updated: 2018/11/26 10:17:40 by aantropo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

char    ft_set_type(char *str, int *i, int *format_end)
{
	char t;

	while (str[*i] && str[*i] != '%')
	{
		t = str[*i];
		if (t == 'd' || t == 'i' || t == 'o' || t == 'u' || t == 'x' || t == 'X'
			|| t == 'f' || t == 'F' || t == 'e' || t == 'E' || t == 'g'
			|| t == 'G' || t == 'a' || t == 'A' || t == 'c' || t == 's' ||
			t == 'p')
		{
			*format_end = *i;
			return (t);
		}
		*i = *i + 1;
	}
	t = ' ';
	return (0);
}

char    *ft_set_flags(char *str, int format_start, int format_end)
{
	char    *flags;
	int     i;

	i = 0;
	flags = (char *)malloc(sizeof(char) * 5);
	ft_bzero(flags, 5);
	while (format_start < format_end)
	{
		if (str[format_start] == '-' && !ft_strchr(flags, '-'))
			flags[i++] = '-';
		if (str[format_start] == '+' && !ft_strchr(flags, '+'))
			flags[i++] = '+';
		if (str[format_start] == ' ' && !ft_strchr(flags, ' '))
			flags[i++] = ' ';
		if (str[format_start] == '#' && !ft_strchr(flags, '#'))
			flags[i++] = '#';
		if (str[format_start] == '0' && !ft_strchr(flags, '0'))
			flags[i++] = '0';
		format_start++;
	}
	return (flags);
}

int     ft_set_width(char *str, int format_start, int format_end, va_list args)
{
	int     width;

	width = 0;
	while (format_start < format_end)
	{
		if (str[format_start - 1] == '.' && ft_isdigit(str[format_start]))
		{
			while (format_start < format_end && ft_isdigit(str[format_start]))
				format_start++;
			continue;
		}
		else if (ft_isdigit(str[format_start]))
		{
			width = ft_atoi(ft_strsub(str, format_start, ft_strlen(str)));
			format_start += ft_digit_cnt_base(width, 10);
		}
		else if (str[format_start] == '*' && str[format_start - 1] != '.')
		{
			width = va_arg(args, int);
			format_start++;
		}
		else
			format_start++;
	}
	return (width);
}

int     ft_set_precision(char *str, int format_start, int format_end, va_list args)
{
	int     precision;

	precision = 0;
	while (format_start < format_end)
	{
		if (ft_isdigit(str[format_start]) && str[format_start - 1] == '.')
			precision = ft_atoi(ft_strsub(str, format_start, format_end - format_start));
		if (str[format_start] == '*' && str[format_start - 1] == '.')
			precision = va_arg(args, int);
		format_start++;
	}
	return (precision);
}

int    ft_set_mod(char *str, int format_start, int format_end)
{
	while (format_start < format_end)
	{
		if (str[format_start] == 'l' && str[format_start + 1] == 'l')
			return (1);
		else if (str[format_start] == 'l')
			return (0);
		if (str[format_start] == 'h' && str[format_start + 1] == 'h')
			return (3);
		else if (str[format_start] == 'h')
			return (2);
		else if (str[format_start] == 'j')
			return (4);
		else if (str[format_start] == 'z')
			return (5);
		else if (str[format_start] == 'y')
			return (6);
		else if (str[format_start] == 'L')
			return (7);
		format_start++;
	}
	return (-1);
}