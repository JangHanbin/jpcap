#ifndef CALCHECKSUM_H
#define CALCHECKSUM_H


#include <stdint.h>

#pragma pack(push,1)

struct Pseudoheader{
    uint32_t srcIP;
    uint32_t destIP;
    uint8_t reserved=0;
    uint8_t protocol;
    uint16_t TCPLen;
};

#pragma pack(pop)

#define CARRY 65536


//blog : http://blog.dork94.com/10
//pointer of IP header
uint16_t calIPChecksum(uint8_t* data);
//pointer of IP Header start, Whole data length from IP header start
uint16_t calTCPChecksum(uint8_t *data,int dataLen);
//pointer of IP Header start, Whole data length from IP header start
uint16_t calICMPChecksum(uint8_t *data,int dataLen);
//pointer of IP Header start, Whole data length from IP header start
uint16_t calUDPChecksum(uint8_t *data, int dataLen);
uint16_t calculate(uint16_t* data, int dataLen);


#endif // CALCHECKSUM_H
