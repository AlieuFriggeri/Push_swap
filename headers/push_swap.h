/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:39 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/06 12:40:04 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	lol(char *str);
void	swap_a(t_list *pile_a);
void	swap_b(t_list *pile_b);
void	push_a(t_list **pile_a, t_list **pile_b);
void	push_b(t_list **pile_b, t_list **pile_a);
void	rotate_a(t_list **pile_a);
void	rotate_b(t_list **pile_b);
void	revrotate_a(t_list **pile_a);
void	revrotate_b(t_list **pile_b);
void	rotate_ab(t_list **pile_a, t_list **pile_b);
void	revrotate_ab(t_list **pile_a, t_list **pile_b);
void	printlist(t_list **pile_a, t_list **pile_b);
void	delete(t_list **root);
void	parse_arg(t_list **pile_a, char **argv, int argc);
int		checkdouble(t_list **pile_a, int nb);
void	setlist(t_list **pile_a, char **numbers);

#endif