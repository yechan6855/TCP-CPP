#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <pcap/socket.h>

using namespace std;

int main(int argc, char* argv[]) {
//    if(argc!=2){
//        printf("다음과 같이 실행하십시오.\n");
//        printf("    nameResilve host_name\n");
//        return 1;
//    }
    hostent* remoteHost;
//    remoteHost=gethostbyname(argv[1]);
    remoteHost=gethostbyname("www.naver.com");
    if(remoteHost==NULL){
        printf("호스트 이름 리졸브 오류");
        return 1;
    }
    printf("호스트 이름 : %d\n", remoteHost->h_name);
    char** pAlias;
    for(pAlias=remoteHost->h_aliases;*pAlias!=NULL; pAlias++){
        printf("별명: %s\n",*pAlias);
    }
    in_addr addr;
    int i=0;
    while(remoteHost->h_addr_list[i]!=NULL){
        addr.s_addr=*(unsigned long *)remoteHost->h_addr_list[i];
        printf("IP 주소 %s\n",inet_ntoa(addr));
        i++;
    }
}