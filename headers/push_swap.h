/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrigger <afrigger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:10:39 by afrigger          #+#    #+#             */
/*   Updated: 2023/02/24 14:02:12 by afrigger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void	swap_a(t_list **pile_a, int mode);
void	swap_b(t_list **pile_b, int mode);
void	push_a(t_list **pile_a, t_list **pile_b);
void	push_b(t_list **pile_b, t_list **pile_a);
void	rotate_a(t_list **pile_a, int mode);
void	rotate_b(t_list **pile_b, int mode);
void	revrotate_a(t_list **pile_a, int mode);
void	revrotate_b(t_list **pile_b, int mode);
void	rotate_ab(t_list **pile_a, t_list **pile_b);
void	revrotate_ab(t_list **pile_a, t_list **pile_b);
void	printlist(t_list **pile_a, t_list **pile_b);
void	delete(t_list *root);
void	deletepart2(t_list *tmp, t_list *tmp2);
void	error(t_list **pile_a, t_list **pile_b);
void	parse_arg(t_list **pile_a, t_list **pile_b, char **argv, int argc);
int		checkdouble(char **numbers);
int		checkval(char **numbers, int index);
void	setlist(t_list **pile_a, t_list **pile_b, char **numbers, int index);
void	sort_sale(t_list **pile_a, t_list **pile_b);
int		checkdigit(char **str, t_list **pile_a, t_list **pile_b, int index);
int		checksort(t_list *pile);
void	normalizer(t_list **pile, char **numbers);
void	normalizer2(t_list **pile, char **numbers);
void	sorttest(t_list **pa, t_list **pb);
int		findpos(t_list **pile, int tofind);
void	sort3(t_list **p, int nbnb);
void	sort5(t_list **pa, t_list **pb);
void	sortk(t_list **pa, t_list **pb);
void	sortk2a(t_list **pa, t_list **pb);
void	sortk2b(t_list **pa, t_list **pb);
void	sortkfinal(t_list **pa);
int		midvalue(t_list *p);
int		findbig(t_list **p);
int		findsmall(t_list **p);
int		bestmove(t_list **p, int tofind);
int		movecalc(t_list **p, int tofind);
void	ft_scandale(t_list **pa, char **numbers, int index);
void	indexToBinary(t_list **pa, int bitmax);
int		bitmax(int maxnb);
void	radix_sort(t_list **pile_a, t_list **pile_b, int bitmax);
//int	checknbr(char str, int index);

#endif