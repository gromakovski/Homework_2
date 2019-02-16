#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include <spdlog/spdlog.h>
#include "lib.h"

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}


int main(int , char **)
{
    try
    {
        

        std::vector<std::vector<std::string> > ip_pool;       
        std::vector<std::vector<std::string> > ip_pool_test;


        for(std::string line; std::getline(std::cin, line);)
        {
            auto v = split(line, '\t');
            ip_pool.push_back(split(v.at(0), '.'));
        }


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

        
       for (auto ip = ip_pool.begin(); ip != ip_pool.end(); ++ip) 
       {
            if (*ip->begin()=="1") ip_pool_test.push_back(*ip);
       }

        for (auto ip = ip_pool.begin(); ip != ip_pool.end(); ++ip) 
       {
            if (*ip->begin()=="46" and (*ip)[1]=="70") ip_pool_test.push_back(*ip);
       }


       //ip_pool.reserve(ip_pool.size()+ip_pool_test.size());
       ip_pool.insert(ip_pool.end(),ip_pool_test.begin(),ip_pool_test.end()); 

        
        
        
        
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


    //auto logger = spdlog::stdout_logger_mt("console");

    //logger->info("version {} was started", version());       
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}