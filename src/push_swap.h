#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647


typedef struct s_data
{
    char    **buffer;
    int     *tab;
    int     tab_size;
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

#endif