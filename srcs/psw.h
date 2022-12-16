#ifndef PSW_H
# define PSW_H
# include "container/stack.h"
# include "../libft/libft.h"

int	ft_isnum(char *str);
t_stack	*receive_input(int argc, char **argv);

void	push(t_stack *a, t_stack *b, char c);
void	sw(t_stack *a, t_stack *b, char c);
void	ro(t_stack *a, t_stack *b, char c);
void	rro(t_stack *a, t_stack *b, char c);
#endif