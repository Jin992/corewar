/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earteshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:02:00 by earteshc          #+#    #+#             */
/*   Updated: 2018/01/24 17:52:04 by earteshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>
# include "libft.h"

typedef struct	s_out
{
	char	*out;
	wchar_t	*u_out;
	int		ch_zero;
	int		below_zero;
}				t_out;

typedef struct	s_dat
{
	size_t	width;
	size_t	prscn;
	size_t	out_len;
	ssize_t	w_crctn;
	size_t	var_type;
	char	var;
	char	error;
}				t_dat;

typedef struct	s_flag
{
	int hash;
	int minus;
	int plus;
	int zero;
	int space;
}				t_flag;

typedef struct	s_lst
{
	t_out			out;
	t_dat			data;
	t_flag			flag;
	struct s_lst	*next;
}				t_lst;

t_lst			*lst_init(void);
void			lst_free(t_lst **list);
int				check_flag(const char *s, t_lst *list);
int				check_width(const char *s, t_lst *list, va_list *ap);
int				check_prcsn(const char *s, t_lst *list, va_list *ap);
int				check_var_size(const char *s, t_lst *list);
int				check_var(const char *s, t_lst *list);
int				get_param(unsigned *i, const char *f, t_lst **l, va_list *ap);
char			*ft_itoa_base(size_t value, int base, int u);
int				set_width(t_lst *list);
int				set_precision(t_lst *list);
int				process_format(const char *format, t_lst *list, va_list *ap);
int				ft_printf(const char *format, ...);
int				digit_dec(t_lst *list, va_list *ap);
int				type_handler(t_lst *list, va_list *ap);
int				print_dec(t_lst *list);
int				add_width(t_lst *list);
int				add_prcsn(t_lst *list);
ssize_t			print_type(t_lst *list);
int				digit_hex(t_lst *list, va_list *ap);
int				print_hex(t_lst *list);
int				digit_unsigned(t_lst *list, va_list *ap);
int				print_unsigned(t_lst *list);
int				digit_oct(t_lst *list, va_list *ap);
int				print_oct(t_lst *list);
int				print_ptr(t_lst *list);
int				digit_ptr(t_lst *list, va_list *ap);
int				percent(t_lst *list, va_list *ap);
int				print_percent(t_lst *list);
int				print_char(t_lst *list);
int				char_c(t_lst *list, va_list *ap);
int				print_char_c(t_lst *list);
int				char_c_c(t_lst *list, va_list *ap);
int				print_char_string(t_lst *list);
int				char_string(t_lst *list, va_list *ap);
char			*uni_proc(unsigned int *str, ssize_t precision, int zero);
int				unicode_string(t_lst *list, va_list *ap);
int				error_input(t_lst *list, va_list *ap);
int				print_error(t_lst *list);
int				count_bits(unsigned int c);
int				wrong_var(const char *s, t_lst *list);
int				count_bytes(unsigned int c);
void			star_width(t_lst *list, va_list *ap, const char *s, size_t *i);
void			star_prcn(t_lst *list, va_list *ap, const char *s, size_t *i);
int				add_space(t_lst *list);
int				add_0x(t_lst *list);
int				digit_float(t_lst *list, va_list *ap);
int				print_float(t_lst *list);

#endif
