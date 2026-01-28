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

static void separator(const char *title)
{
    printf("\n================ %s ================\n", title);
}

void test_ft_write()
{
    ssize_t ret;

    /* ------------------------------------ */
    separator("TEST 1: ft_write to STDOUT");

    errno = 0;
    ret = ft_write(1, "Hello stdout\n", 13);

    printf("Return value: %zd\n", ret);
    printf("errno: %d (%s)\n", errno, strerror(errno));

    if (ret == 13)
        printf("PASS\n");
    else
        printf("FAIL\n");

    /* ------------------------------------ */
    separator("TEST 2: ft_write to FILE");

    int fd = open("test_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open");
    }

    errno = 0;
    ret = ft_write(fd, "File write OK\n", 14);

    printf("Return value: %zd\n", ret);
    printf("errno: %d (%s)\n", errno, strerror(errno));

    if (ret == 14)
        printf("PASS\n");
    else
        printf("FAIL\n");

    close(fd);
    printf("➡️ Check file: test_output.txt\n");

    /* ------------------------------------ */
    separator("TEST 3: ft_write with WRONG FD");

    errno = 0;
    ret = ft_write(-1, "Bad fd\n", 7);

    printf("Return value: %zd\n", ret);
    printf("errno: %d (%s)\n", errno, strerror(errno));

    if (ret == -1 && errno == EBADF)
        printf("PASS\n");
    else
        printf("FAIL\n");

    /* ------------------------------------ */
    separator("TEST 4: Compare with libc write");

    errno = 0;
    ssize_t libc_ret = write(-1, "Bad fd\n", 7);
    int libc_errno = errno;

    errno = 0;
    ret = ft_write(-1, "Bad fd\n", 7);
    int my_errno = errno;

    printf("libc write -> ret=%zd errno=%d (%s)\n",
           libc_ret, libc_errno, strerror(libc_errno));
    printf("ft_write   -> ret=%zd errno=%d (%s)\n",
           ret, my_errno, strerror(my_errno));

    if (libc_ret == ret && libc_errno == my_errno)
        printf("MATCHES LIBC\n");
    else
        printf("DOES NOT MATCH LIBC\n");
}

void test_ft_read()
{
    char buffer[128];
    ssize_t ret;

    /* ------------------------------------ */
    separator("TEST 1: ft_read from STDIN");

    printf("Type something and press ENTER: ");
    fflush(stdout);

    errno = 0;
    ret = ft_read(0, buffer, sizeof(buffer) - 1);

    if (ret >= 0)
        buffer[ret] = '\0';

    printf("\nReturn value: %zd\n", ret);
    printf("errno: %d (%s)\n", errno, strerror(errno));
    printf("Buffer: \"%s\"\n", (ret >= 0) ? buffer : "(invalid)");

    if (ret > 0)
        printf("PASS\n");
    else
        printf("FAIL\n");

    /* ------------------------------------ */
    separator("TEST 2: ft_read from FILE");

    int fd = open("test_input.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open for write");
    }

    write(fd, "File input OK\n", 14);
    close(fd);

    fd = open("test_input.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("open for read");
    }

    memset(buffer, 0, sizeof(buffer));
    errno = 0;
    ret = ft_read(fd, buffer, sizeof(buffer) - 1);

    if (ret >= 0)
        buffer[ret] = '\0';

    printf("Return value: %zd\n", ret);
    printf("errno: %d (%s)\n", errno, strerror(errno));
    printf("Buffer: \"%s\"\n", buffer);

    if (ret == 14 && strcmp(buffer, "File input OK\n") == 0)
        printf("PASS\n");
    else
        printf("FAIL\n");

    close(fd);

    /* ------------------------------------ */
    separator("TEST 3: ft_read with WRONG FD");

    errno = 0;
    ret = ft_read(-1, buffer, sizeof(buffer));

    printf("Return value: %zd\n", ret);
    printf("errno: %d (%s)\n", errno, strerror(errno));

    if (ret == -1 && errno == EBADF)
        printf("PASS\n");
    else
        printf("FAIL\n");

    /* ------------------------------------ */
    separator("TEST 4: Compare with libc read");

    errno = 0;
    ssize_t libc_ret = read(-1, buffer, sizeof(buffer));
    // ssize_t libc_ret = read(0, buffer, sizeof(buffer));
    int libc_errno = errno;

    errno = 0;
    ret = ft_read(-1, buffer, sizeof(buffer));
    // ret = ft_read(0, buffer, sizeof(buffer));
    int my_errno = errno;

    printf("libc read -> ret=%zd errno=%d (%s)\n",
           libc_ret, libc_errno, strerror(libc_errno));
    printf("ft_read   -> ret=%zd errno=%d (%s)\n",
           ret, my_errno, strerror(my_errno));

    if (libc_ret == ret && libc_errno == my_errno)
        printf("MATCHES LIBC\n");
    else
        printf("DOES NOT MATCH LIBC\n");
}

int main(void)
{
    ////---------- ft_strlen -------------
    const char *str = "meow";
    // const char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaa as da sd asdf ds fsd fs dfs d";
    printf("libc strlen: %zu\n", strlen(str));
    printf("ft_strlen: %zu\n", ft_strlen(str));

    ////---------- ft_strcpy -------------
    // const char src[] = "notmeow";
    // char dest[100];
    // char dest1[100];

    // strcpy(dest1, src);
    // ft_strcpy(dest, src);

    // printf("libc strcpy: %s\n", dest1);
    // printf("ft_strcpy: %s\n", dest);

    ////---------- ft_strcmp -------------
    // const char s1[] = "notmeo";
    // const char s2[] = "notmeow";
    // printf("libc strcmp %d\n", strcmp(s1, s2));
    // printf("ft_strcmp %d\n", ft_strcmp(s1, s2));

    ////---------- ft_write -------------
    // write(1,"meow", 4);
    // printf("\n");
    // ft_write(1,"meow", 4);
    // test_ft_write();


    ////---------- ft_read -------------
    // // char buffer[100];

    // // write(1, "Enter input: ", 13);
    // // ssize_t ret = ft_read(0, buffer, sizeof(buffer) - 1);

    // // if (ret == -1) {
    // //     perror("ft_read error");
    // //     return 1;
    // // }

    // // buffer[ret] = '\0';
    // // printf("You typed: %s", buffer);
    
    // test_ft_read();

    ////---------- ft_strdup -------------
    // char	s[] = "Hello!";
    // char	*d1 = NULL;
	// char	*d2 = NULL;

	// d1 = strdup(s);
	// d2 = ft_strdup(s);
	// if (strcmp(d1, d2) == 0)
	// 	printf("ok");
	// else
	// 	printf("not ok");
	// printf ("\nlibc: %s\n", d1);
	// printf ("my libasm: %s\n", d2);
	// free(d1);
	// free(d2);

    return 0;
}