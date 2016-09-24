#include "com_example_socket_pool_JniUtil.h"
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <android/log.h>
#define MAXLINE 80
#define SERV_PORT 8000
JNIEXPORT void JNICALL Java_com_example_socket_1pool_JniUtil_start
  (JNIEnv * env, jobject obj){
	struct sockaddr_in servaddr;
	char buf[MAXLINE]={0};
	int sockfd,n;
	char * str = "hello android ndk socket";
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET,"192.168.1.102",&servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);
	connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	write(sockfd,str,strlen(str));
	n = read(sockfd,buf,MAXLINE);
	__android_log_print(ANDROID_LOG_ERROR, "jnitag", "resonpse from server:%s\n",buf);
	close(sockfd);
	return ;

}
