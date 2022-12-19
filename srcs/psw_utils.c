#include "../include/psw.h"

int	ft_isnum(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

t_stack	*receive_input(int argc, char **argv)
{
	t_stack	*stack;
	int	*nptr;

	stack = stack_init();
	if (!stack )
		return (NULL);
	while (argc > 1)
	{
		if (!ft_isnum(argv[argc - 1]))
		{
			stack->clear(stack, free);
			free(stack);
			return (NULL);
		}
		nptr = malloc(sizeof(int));
		*nptr = ft_atoi(argv[--argc]);
		stack->push(stack, nptr);
	}
	return (stack);
}