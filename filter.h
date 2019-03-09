#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class ip
{
public:
        
    //ip() : ip_adress(NULL), ip_pool(NULL){};
    
    void get ();
    void set_ip_pool ();
    void sort_reverse_all ();
    void push_back_ip_pool (std::vector<std::vector<std::string>>);
    //void push_back_ip(std::vector<std::string>);

    std::vector<std::vector<std::string>> search_one_byte (const std::string);
    std::vector<std::vector<std::string>> search_two_byte (const std::string, const std::string);
    
private:
    std::vector<std::string> set_subs (const std::string &str, const char end_subs);

    std::vector<std::string> ip_adress;
    std::vector<std::vector<std::string>> ip_pool;
};


