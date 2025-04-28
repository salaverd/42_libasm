#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

size_t      ft_strlen(const char *str);
char        *ft_strcpy(char *dest, const char *src);
int         ft_strcmp(const char *s1, const char *s2);
ssize_t     ft_write(int fd, const void *buf, size_t count);
ssize_t     ft_read(int fd, void *buf, size_t count);
char        *ft_strdup(const char *s);

int *___error(void)
{
    return &errno;
}

int main(void)
{
    ////---------- ft_strlen -------------
    // const char *str = "meow";
    // printf("%zu\n", ft_strlen(str));

    ////---------- ft_strcpy -------------
    // const char src[] = "notmeow";
    // char dest[10];

    // ft_strcpy(dest, src);

    // printf("Source: %s\n", src);
    // printf("Destination: %s\n", dest);

    ////---------- ft_strcmp -------------
    // const char s1[] = "notmeo";
    // const char s2[] = "notmeow";
    // printf("%d\n", ft_strcmp(s1, s2));

    ////---------- ft_write -------------
    // write(1,"meow", 4);
    // printf("\n");
    // ft_write(1,"meow", 4);

    ////---------- ft_read -------------
    // char buffer[100];

    // write(1, "Enter input: ", 13);
    // ssize_t ret = ft_read(0, buffer, sizeof(buffer) - 1);

    // if (ret == -1) {
    //     perror("ft_read error");
    //     return 1;
    // }

    // buffer[ret] = '\0';
    // printf("You typed: %s", buffer);

    ////---------- ft_strdup -------------
    char	*s = "Hello!";
    char	*d1;
	char	*d2;

	d1 = strdup(s);
	d2 = ft_strdup(s);
	if (strcmp(d1, d2) == 0)
		printf("ok");
	else
		printf("not ok");
	printf ("\nlibc: [%s]\n", d1);
	printf ("my libasm: [%s]\n", d2);
	free(d1);
	free(d2);

    return 0;
}