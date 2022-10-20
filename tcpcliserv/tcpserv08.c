#include "unp.h"
#include "sigchldwaitpid.c"
#include "str_echo08.c"

int
main(int argc, char **argv)
{
    int     listenfd, connfd;
    pid_t   childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    void    sig_chld(int);

    listenfd = Socket(AF_INET, SOCK_STREAM, 0);
    // Fputs("listenfd = ", stdout);
    // Fputs((const char*)listenfd, stdout);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

    Listen(listenfd, LISTENQ);

    Signal(SIGCHLD, sig_chld);
 
    for(;;){
        clilen = sizeof(cliaddr);
        if( (connfd = accept(listenfd, (SA *) &cliaddr, &clilen)) < 0){
            if(errno == EINTR)
                continue;
            else
                err_sys("accept error");
        }
        // Fputs("connfd = ", stdout);
        // Fputs((const char*)connfd, stdout);
        if( (childpid = Fork()) == 0){
            Close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        Close(connfd);
    }
} 