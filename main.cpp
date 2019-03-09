#include "lib.h"
#include "filter.h"
#include <iostream>


int main(int argc, char const *argv[])
{
    try
    {
       ip IP_TEST;  
       IP_TEST.set_ip_pool();
       IP_TEST.sort_reverse_all();
       IP_TEST.push_back_ip_pool(IP_TEST.search_one_byte("1"));
       IP_TEST.push_back_ip_pool(IP_TEST.search_two_byte("46","70"));
       IP_TEST.get();
       
      }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        
    return 0;
    
}
