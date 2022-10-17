#include "unp.h"

void str_echo(int sockfd){
	ssize_t	n;
	char	buf[MAXLINE];

again:
	while ( (n = read(sockfd, buf, MAXLINE)) > 0){
		Fputs("msg from client: ", stdout);
		Fputs(buf, stdout);
		Writen(sockfd, buf, n);
		bzero(buf, MAXLINE);
	}
		

	if (n < 0 && errno == EINTR)
		goto again;
	else if (n < 0)
		err_sys("str_echo: read error");
}
