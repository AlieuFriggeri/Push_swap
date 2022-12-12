/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:39 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/08 15:00:58 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	swap_a(t_list *pile_a, int mode);
void	swap_b(t_list *pile_b, int mode);
void	push_a(t_list **pile_a, t_list **pile_b);
void	push_b(t_list **pile_b, t_list **pile_a);
void	rotate_a(t_list **pile_a, int mode);
void	rotate_b(t_list **pile_b, int mode);
void	revrotate_a(t_list **pile_a, int mode);
void	revrotate_b(t_list **pile_b, int mode);
void	rotate_ab(t_list **pile_a, t_list **pile_b);
void	revrotate_ab(t_list **pile_a, t_list **pile_b);
void	printlist(t_list **pile_a, t_list **pile_b);
void	delete(void *root);
void	parse_arg(t_list **pile_a, char **argv, int argc);
int		checkdouble(char **numbers);
void	setlist(t_list **pile_a, char **numbers, int index);
void	sort_sale(t_list **pile_a, t_list **pile_b);
int		checkdigit(char **str);
int	checksort(t_list *pile);

#endif