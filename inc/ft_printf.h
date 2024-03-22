/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:50:14 by jyap              #+#    #+#             */
/*   Updated: 2023/12/12 18:49:02 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct s_format
{
	int		minus;
	int		plus;
	int		width;
	int		pcs;
	int		neg_pcs;
	char	specifier;
	int		zero;
	int		dot;
	int		space;
	int		sharp;
}	t_format;

# define SPECIFIERS "cspdiuxX%"

int			ft_printf(const char *str, ...);
int			print_dupe_fd(char c, int n, int fd);
t_format	ft_newformat(void);
int			ft_print_format(t_format f, va_list ap);
int			ft_print_c_pct(t_format f, va_list ap);
int			ft_print_s(t_format f, va_list ap);
int			ft_print_d_i(t_format f, va_list ap, int *count);
int			ft_print_u(t_format f, va_list ap);
int			ft_print_x(t_format f, va_list ap);
int			ft_print_p(t_format f, va_list ap);
int			ft_parse(char *str, va_list ap);

#endif