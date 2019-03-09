#include "filter.h"
#include "define.h"

std::vector<std::string> ip::set_subs (const std::string &str, const char end_subs)
{
    std::vector<std::string> ip_adress;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(end_subs);
   
    while(stop != std::string::npos)
    {
        ip_adress.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(end_subs, start);
    }

    ip_adress.push_back(str.substr(start));
    return ip_adress;
}


void ip::set_ip_pool()
{
    for(std::string line; std::getline(std::cin, line);)
        {
            auto v = ip::set_subs(line, END_IP_ADRESS);
            //ip::set_subs(ip_adress.at(0), '.');
            ip_pool.push_back(ip::set_subs(v.at(0), END_IP));   

        }
}

void ip::sort_reverse_all()
{
            std::sort(ip_pool.begin(),
                    ip_pool.end(),
                    [](auto a, auto b) 
                        {
                            if (a[0]==b[0]) 
                                {
                                    if (a[1]==b[1])
                                        {
                                            if (a[2]==b[2])
                                                return atoi(a[3].c_str()) > atoi(b[3].c_str());

                                            else  
                                            return atoi(a[2].c_str()) > atoi(b[2].c_str());    
                                        }
                                    else return atoi(a[1].c_str()) > atoi(b[1].c_str());

                                }
                            else return atoi(a[0].c_str()) > atoi(b[0].c_str());
                        }
                    );
}

std::vector<std::vector<std::string>>  ip::search_one_byte(const std::string one_byte)
{
    std::vector<std::vector<std::string>> search_ip_pool;
     for (auto ip = ip_pool.begin(); ip != ip_pool.end(); ++ip) 
       {
             if (*ip->begin()==one_byte) search_ip_pool.push_back(*ip);
       }
    return search_ip_pool;
}

std::vector<std::vector<std::string>>  ip::search_two_byte (const std::string one_byte, const std::string two_byte)
{
    std::vector<std::vector<std::string>> search_ip_pool;
     for (auto ip = ip_pool.begin(); ip != ip_pool.end(); ++ip) 
       {
             if (*ip->begin()==one_byte and (*ip)[1]==two_byte) search_ip_pool.push_back(*ip);
       }
    return search_ip_pool;
}

void ip::get()
{
    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
       {
            for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
            {
                if (ip_part != ip->cbegin())
                {
                    std::cout << ".";

                }
                std::cout << *ip_part;
            }
            std::cout << std::endl;
        }
}

void ip::push_back_ip_pool(std::vector<std::vector<std::string>> in_ip_pool)
{
    for (auto ip = in_ip_pool.begin(); ip != in_ip_pool.end(); ++ip) 
        ip_pool.push_back(*ip);
}
