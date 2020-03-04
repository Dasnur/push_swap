#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct  	s_lst
{
    int				value;
    struct s_lst	*next;
    int             is_color;
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
int		    l_pushb(t_head *stacks);
int		    l_pusha(t_head *stacks);
t_lst		*l_swap(t_lst **h);
int			hmm(t_head *stacks);
void	    al_min(t_head stacks, int n);
int		    ft_printf(char *line, ...);
void	    print_all(t_head *stacks, int n);
int		    check_argv(char *res);
int		    check_dupl(t_lst *a, int check);
int		    valid_arg(t_head *stacks, char **argv, int argc, int fv);
int		    exc(void);
int		    find_maxi(t_lst a);
int		    find_mini(t_lst a);
#endif