#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <pcap/socket.h>

#define endl "\n"
using namespace std;

int main(int argc, char* argv[]) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // TCP 소켓 생성
    if (sockfd == -1) {
        cerr << "소켓 생성 실패" << endl;
        return 1;
    }
    cout << "소켓 생성 성공" << endl;

    int dataSocket=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(dataSocket==INVALID_SOCKET){
        cout<<"소켓 생성 실패"<<endl;
    }

    close(sockfd); // 소켓 종료
    cout << "소켓을 종료합니다." << endl;
    return 0;
}