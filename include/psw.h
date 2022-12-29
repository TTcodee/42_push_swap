#ifndef PSW_H
# define PSW_H
# include "stack.h"
# include "../libft/libft.h"

typedef struct s_psw_stack t_pswstx;

struct	s_psw_stack
{
	char	*name;
	t_stack	*stack;
	t_pswstx	*tmp;
	void	(*push)(t_pswstx *self);
	void	(*sw)(t_pswstx *self);
	void	(*ro)(t_pswstx *self);
	void	(*rro)(t_pswstx *self);
};


int	ft_isnum(char *str);
t_stack	*receive_input(int argc, char **argv);
t_pswstx	*pswstx_init();
//algorithm part
int	find_median(t_stack *stack, int start, int end);
int	m_floor(double n);
int	m_ceil(double n);
int	is_lsort(t_pswstx *stx, int len, int rev);//start counting from top of the stx
void	small_sort(t_pswstx *stx);
int	find_nsmaller(t_stack *s, int num, int len);
#endif
