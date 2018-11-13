//
//  functions.h
//  Google_Code
//
//  Created by SUMIT  LAHIRI on 11/4/18.
//  Copyright © 2018 Google PPLNS. All rights reserved.
//

#ifndef functions_h
#define functions_h
#include "static.h"
#include "methods.h"

using std::operator""s;

namespace
{
    unsigned ln = 1;
    auto Color(int n, const std::string& s) { return "\33[38;5;"+std::to_string(n)+'m'+s+"\33[m"; }
    auto Line(int l) { int m=l-ln; ln=l; return "\r"+(m<0?"\33["+std::to_string(-m)+'A':std::string(m,'\n')); }
    std::mutex print_lock;
    
    std::size_t Download(const std::string& url, const std::string& filename, unsigned line)
    {
        std::ofstream of(filename);
        std::size_t written = 0;
        
        cURLpp::Easy req;
        req.setOpt(cURLpp::Options::Url(url));
        req.setOpt(cURLpp::Options::NoProgress(false));
        req.setOpt(cURLpp::Options::FollowLocation(true));
        req.setOpt(cURLpp::Options::ProgressFunction([&](std::size_t total, std::size_t done, auto...)
                                                     {
                                                         std::lock_guard<std::mutex> l(print_lock);
                                                         std::cout << Line(line) << Color(143, filename + ": ") << done << " of " << total
                                                         << " bytes received (" << int(total ? done*100./total : 0) << "%)" << std::flush;
                                                         return 0;
                                                     }));
        req.setOpt(cURLpp::Options::WriteFunction([&](const char* p, std::size_t size, std::size_t nmemb)
                                                  {
                                                      of.write(p, size*nmemb);
                                                      written += size*nmemb;
                                                      return size*nmemb;
                                                  }));
        req.perform();
        return written;
    }
    
    auto root = "http://iki.fi/bisqwit/ctu85/"s; // http://www.unicode.org/Public/MAPPINGS/ISO8859/
}

int file_download()
{
    cURLpp::initialize();
    unsigned line=1;
    
    std::vector<std::future<std::size_t>> sizes;
    
    for(const auto& p: {"8859-1.TXT"s, "8859-2.TXT"s, "8859-3.TXT"s, "8859-4.TXT"s, "8859-5.TXT"s,
        "8859-6.TXT"s, "8859-7.TXT"s, "8859-8.TXT"s, "8859-9.TXT"s, "8859-10.TXT"s,
        "8859-11.TXT"s,"8859-13.TXT"s,"8859-14.TXT"s,"8859-15.TXT"s,"8859-16.TXT"s})
    {
        sizes.emplace_back(std::async(std::launch::async, [p, l=line++]
                                      {
                                          return Download(root+p, p, l);
                                      }));
    }
    
    std::size_t total = 0;
    for(auto& s: sizes) total += s.get();
    
    std::cout << Line(line) << Color(174, std::to_string(total) + " bytes downloaded total\n");
    return 0;
}

#endif /* functions_h */
