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


Ip& Ip::operator=(const char *op1)
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

uint32_t Ip::get_ip_broadcast(const char _class)
{

    //val already saved by Network byte order so that reconvert host order set.
    //and return by network byte order

    char network_class=_class;
    if(isupper(_class))
        network_class += 32;

    switch (network_class) {
    case 'a':
        return htonl(((ntohl(val) >> 24) << 24 )+ 0x00ffffff);
        break;

    case 'b':
        return htonl(((ntohl(val) >> 16) << 16 )+ 0x0000ffff);
        break;

    case 'c':
        return htonl(((ntohl(val) >> 8) << 8 )+ 0x000000ff);
        break;

    default:
        std::cout<<"Wrong class type. Please check your network class"<<std::endl;
        exit(1);
    }
}
