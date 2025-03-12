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
    int ra;
    int rb;
    int rra;
    int rrb;
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
int     init_stack_a(t_data *data);
t_stack *create_node(int value);
void append_node(t_stack **stack, int value);
void	swap(t_stack **stack, char stack_name);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void rotate(t_stack **stack, char stack_name);
void revrotate(t_stack **stack, char stack_name);
void    ss(t_stack **stack_a, t_stack **stack_b);
void    rrr(t_stack **stack_a, t_stack **stack_b);
void    rr(t_stack **stack_a, t_stack **stack_b);
t_stack *find_best_match_in_b(t_stack *stack_b, int value);
t_stack *find_max_in_stack(t_stack *stack_b);
void    find_target_in_b(t_stack **stack_a, t_stack **stack_b);
void    turk_sort(t_stack **stack_a, t_stack **stack_b);
int     get_stack_len(t_stack *stack);
int     is_sorted(t_stack *stack);
int     get_index(t_stack *stack, t_stack *node);
void	move_a_to_b(t_stack **stack_a , t_stack **stack_b);
void    calculate_cost_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	calculate_cost_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	bring_to_top_a(t_stack **stack_a);
void	bring_target_top_b(t_stack **stack_a, t_stack **stack_b);
void	bring_target_top_a(t_stack **stack_a, t_stack **stack_b);
void	bring_to_top_b(t_stack **stack_b);
void    move_cheapest_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
t_stack	*find_cheapest_in_a(t_stack *stack_a);
t_stack	*find_cheapest_in_b(t_stack *stack_b);
void	sort_three(t_stack **stack_a);
t_stack	*find_best_match_in_a(t_stack *stack_a, int value);
t_stack	*find_min_in_stack(t_stack *stack_a);
void	find_target_in_a(t_stack **stack_a, t_stack **stack_b);
void move_cheapest_to_a(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);



void    printf_both_stack(t_stack *stack_a, t_stack *stack_b);
#endif