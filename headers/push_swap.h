/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:39 by afrigger          #+#    #+#             */
/*   Updated: 2022/12/05 16:03:10 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	lol(char *str);
void	swap_a(t_list *pile_a);
void	push_a(t_list **pile_a, t_list **pile_b);
void	printlist(t_list **pile_a, t_list **pile_b);
void	delete(t_list **root);

#endif