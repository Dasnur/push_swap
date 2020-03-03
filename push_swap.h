#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct  	s_lst
{
    int				value;
    struct s_lst	*next;
}               	t_lst;

typedef struct		s_head
{
	t_lst			*a;
	t_lst			*b;
}					t_head;

t_lst		*l_add_first(t_lst *head, int value);
void		l_print(t_lst *head);
t_lst		*l_reverse_rotate(t_lst *a);
t_lst		*l_rotate(t_lst *a);
void		l_pushb(t_head *stacks);
void		l_pusha(t_head *stacks);
t_lst		*l_swap(t_lst **h);
int			hmm(t_head *stacks);
void		push_al0(t_head stacks, int n);
void    	al_min(t_head stacks, int n);
void		al_1(t_head stacks, int n);
void	    al_mini_half(t_head stacks, int n);
void	    al_min_pro(t_head stacks, int n);
void	    al_min_pro_turbo(t_head stacks, int n);
#endif