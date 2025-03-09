#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
    int value;
    int index;
    int push_cost;
    int cheapest;
    int above_med;
    int size;
    struct s_stack *target_node;
    struct s_stack *prev;
    struct s_stack *next;
}              t_stack;


typedef struct s_data
{
    char        **buffer;
    int         *tab;
    int         tab_size;
    t_stack     **stack_a;
    t_stack     **stack_b;
}               t_data;


int	    *parse_input(t_data *data);
int     number_is_valid(char *str);
int	    ft_strlen(const char *s);
char	*ft_strcpy(char *dest, char *src);
long	ft_atol(char *str);
void	ft_error(void);
int	    ft_printf(const char *str, ...);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *destination, const char *source, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*join_args(int ac, char **av);
void	radix_sort(t_data *data);
int     init_stack_a(t_data *data);
t_stack *create_node(int value);
void append_node(t_stack **stack, int value);
void	swap(t_stack **stack);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void    rotate(t_stack **stack);
void    revrotate(t_stack **stack);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
t_stack *find_best_match(t_stack *stack_b, int value);
t_stack *find_max_in_stack(t_stack *stack_b);
void    find_target_a(t_stack **stack_a, t_stack **stack_b);
void    turk_sort(t_stack **stack_a, t_stack **stack_b);
int     get_stack_len(t_stack *stack);
int     is_sorted(t_stack *stack);
#endif