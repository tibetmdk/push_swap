#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647


int 	*parse_input(char *str, int *size);
char	*join_args(int ac, char **av);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
long	ft_atol(char *str);
void	ft_error(void);

#endif