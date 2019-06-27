/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_library.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 16:24:01 by amartin-          #+#    #+#             */
/*   Updated: 2019/06/23 23:25:43 by amartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUR_LIBRARY_H
# define OUR_LIBRARY_H

char	*ft_one_number_to_letters(char *nb_digits, char *dico);
char	*view_dico(void);
void	ft_putstr(char *str);
int		str_len(char *str);
char	*get_1000(int len);
int		errors(void);
void	if_zero(char *str);
void	ft_espace(char *str, int i);

#endif
