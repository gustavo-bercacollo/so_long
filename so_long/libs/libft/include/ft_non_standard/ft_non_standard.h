#ifndef FT_NON_STANDARD_H
# define FT_NON_STANDARD_H

# include <stdlib.h>
# include <unistd.h>
#include "ft_string.h"

int		ft_ilen(int n);
int		ft_isdouble(const char *str);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
double	ft_strtod(const char *str, char **endptr);
int		ft_strtoi(const char *str, char **endptr);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif