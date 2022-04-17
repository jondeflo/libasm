/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:28:23 by jondeflo          #+#    #+#             */
/*   Updated: 2020/11/06 17:44:45 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>


size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);
char 	*ft_strdup(const char *s1);

int main()
{
	printf("\n\x1b[33m============== ft_strlen ==============\n\n\x1b[0m");
	printf("O: strlen = %lu\nM: strlen = %lu\n", strlen("abcdef"), ft_strlen("abcdef"));

	printf("\n\x1b[33m============== ft_strcpy ==============\n\n\x1b[0m");
	char *src = "abcdefghijABCDEFGHIJ";
	char dst1[40];
	char dst2[40];
	strcpy(dst1, src);
	ft_strcpy(dst2, src);
	printf("O: dst1 = %s\nM: dst2 = %s\n", dst1, dst2);

	printf("\n\x1b[33m============== ft_strcmp ==============\n\n\x1b[0m");
	char *str1 = "aaa";
	char *str2 = "bbb";
	printf("O: strcmp = %d\nM: strcmp = %d\n", strcmp(str1, str2), ft_strcmp(str1, str2));

	printf("\n\x1b[33m============== ft_write ==============\n\n\x1b[0m");
	printf("O: write = \"");fflush(stdout);
	size_t a = write(2, dst1, 10);
	printf("\", with size of %zd, errno %s\nM: write = \"", a, strerror(errno));fflush(stdout);
	size_t b = ft_write(2, dst1, 10);
	printf("\", with size of %zd, errno %s\n", b, strerror(errno));

	printf("\n\x1b[33m============== ft_read ==============\n\n\x1b[0m");
	int fd = open("Makefile", O_RDONLY);
	char buf[33];
	int cnt = read(fd, buf, 32);
	buf[cnt] = '\0';
	int i = 0;
	printf("O: read = \"");
	while (buf[i])
		printf("%c", buf[i++]);
	printf("\"  %d chars readed, errno %s\n", cnt, strerror(errno));
	close (fd);

	int fd1 = open("Makefile", O_RDONLY);
	char buf1[33];
	int cnt1 = ft_read(fd1, buf1, 32);
	buf1[cnt1] = '\0';
	i = 0;
	printf("M: read = \"");
	while (buf1[i])
		printf("%c", buf1[i++]);
	printf("\"  %d chars readed, errno %s\n", cnt1, strerror(errno));
	close (fd1);

	printf("\n\x1b[33m============== ft_strdup ==============\n\n\x1b[0m");
	char *orig = "The very original string";
	printf("O: \"%s\"\nM: \"%s\"\n\n", strdup(orig), ft_strdup(orig));

	return 0;
}