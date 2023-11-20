#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char *s;
	int a;
	int fd = open("test.txt", O_RDONLY, 0777);
	a = 2;
	while (a)
	{
		s = get_next_line(fd);
		if (!s)
			break;
		printf("%s", s);
		free(s);
		a--;
	}
}
