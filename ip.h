#ifndef IP_H
#define IP_H

#include <cstdint>
#include <cstring>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include "mac.h"

#define IP_ADDR_LEN 4

class Ip{

public:
    Ip& operator =(uint8_t *op1);
    bool operator ==(uint8_t *op1);
    bool operator ==(uint32_t *op1);
    Ip& operator=(uint32_t *op1);
    Ip& operator =(char* op1);
    uint32_t val = 0; //IP
    void set_my_Ip(const char *device);
    uint32_t* get_ip_ptr();
    uint32_t get_ip();
    void set_rand_ip();
    bool inc_ip_addr();

};
#endif // IP_H
