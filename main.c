#include <stdio.h>

size_t  ft_strlen(const char *str);

int main(void)
{
    const char *str = "Meow";
    printf("%zu\n", ft_strlen(str));
    return 0;
}