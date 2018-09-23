#ifndef JPCAPLIB_H
#define JPCAPLIB_H

#include <iostream>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

using namespace std;

#define NONPROMISCUOUS 0
#define PROMISCUOUS 1

#pragma pack(push,1)

struct MaximumSegementSize{
    uint8_t kind;
    uint8_t length;
    uint16_t MSSvalue;
}typedef MaximumSegementSize;

struct TcpSackPermittedOption{
    uint8_t kind;
    uint8_t length;

}typedef TcpSackPermittedOption;

struct TimeStamps{
    uint8_t kind;
    uint8_t length;
    uint32_t timeStampValue;
    uint32_t timeStampEchoReply;

}typedef TimeStamps;

struct WindowScale{
    uint8_t kind;
    uint8_t length;
    uint8_t shifCount;
}typedef WindowScale;

struct SynOptions{

    /*Maximum segment Size*/
    MaximumSegementSize maximumSegementSize;

    /*TcpSackPermittedOption*/
    TcpSackPermittedOption tcpSackPermittedOption;

    /*TimeStamps*/
    TimeStamps timestamp;

    /*No-Operation*/
    uint8_t noOperation=1;

    /*Window Scale*/
    WindowScale windowScale;
}typedef SynOptions,SynAckOptions;

struct AckOptions{
    uint8_t Nop1=1;
    uint8_t Nop2=1;
    TimeStamps timeStamps;

};

#pragma pack(pop)


bool recvPacket(pcap_t *pcd, uint8_t **packetData, int &dataLen);   //recv data & save data point packetData
bool parseEther(uint8_t **data, int& dataLen, int type);            //parse Ethernet header & cmp type if type is right move pointer to type header
bool parseIP(uint8_t** data,int& dataLen, int type);                //parse IP header & cmp type if type is right move pointer to type header
bool parseTCPData(uint8_t** data,int& dataLen);                     //parse TCP header & move pointer to TCP Data
void packetSend(pcap_t* pcd, uint8_t* data, int dataLen);           //packet Send Don't need to
#endif // JPCAPLIB_H
