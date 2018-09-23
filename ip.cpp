#include "ip.h"

#include <cstring>
#include <iostream>
#include <arpa/inet.h>
#include "getmyinfo.h"

Ip& Ip::operator=(uint8_t *op1)
{
    memcpy(&this->val,op1,IP_ADDR_LEN);
    return *this;

}

Ip& Ip::operator=(uint32_t *op1)
{
    memcpy(&this->val,op1,IP_ADDR_LEN);
    return *this;

}


Ip& Ip::operator=(char* op1)
{
    inet_pton(AF_INET,op1,&this->val);
    return *this;

}


bool Ip::operator==(uint8_t *op1)
{
    return (memcmp(&this->val,op1,IP_ADDR_LEN)==0);

}

bool Ip::operator==(uint32_t *op1)
{
    return (memcmp(&this->val,op1,IP_ADDR_LEN)==0);

}

void Ip::set_my_Ip(const char *device)
{
    getMyIP(device,&(this->val));
}

uint32_t* Ip::get_ip_ptr()
{
    return &this->val;
}

uint32_t Ip::get_ip()
{
    return this->val;
}

void Ip::set_rand_ip()
{
    srand(time(NULL));
    val = (rand() % UINT32_MAX) + 1 ;
}

bool Ip::inc_ip_addr()
{
    // UINT32_MAX is broadcast. so campare with '<'
    if( htonl(val) < UINT32_MAX)
        val = ntohl(htonl(val) +1);
    else
        //if out of range when increase ip addr
        return false;

    return true;

}
