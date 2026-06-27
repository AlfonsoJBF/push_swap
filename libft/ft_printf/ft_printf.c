/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtapiado <mtapiado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 15:12:12 by mtapiado          #+#    #+#             */
/*   Updated: 2026/06/25 13:21:21 by mtapiado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_putchar_printf(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	ft_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_printf(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstring(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr_base_un(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base_un(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base_un(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (c == '%')
		return (ft_putchar_printf('%'));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			count = count + ft_format(format[i], args);
		}
		else
			count = count + ft_putchar_printf(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
