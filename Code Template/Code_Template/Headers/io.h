/**
 * CodeObsess (SpawnTree)
 * Copyright © 2018 CodeObsess All rights reserved
 */

#ifndef reader_h
#define reader_h
#include "static.h"

#endif /* reader_h */

long long int reader;

void close()
{
    fclose(stderr);
    fclose(stdin);
    fclose(stdout);
}

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

void single_write_cout()
{
    std::cerr << "Write Test : cout used" << std::endl;
    for(auto i = 0; i < 10000; i++){
        for(auto j = 0; j < 10000; j++){
            std::cout << rd_ints() << ", ";
        }
        std::cout << "/n";
    }
}

void single_write_printf()
{
    std::cerr << "Write Test :  printf used" << std::endl;
    for(auto i = 0; i < 10000; i++){
        for(auto j = 0; j < 10000; j++){
            printf("%d ,", rd_ints());
        }
        printf("\n");
    }
}
void single_write_cin()
{
    std::cerr << "Read Test : Read using custom function" << std::endl;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            readInt();
        }
    }
}

void single_write_scanf()
{
    std::cerr << "Read Test : Read using scanf" << std::endl;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            scanf("%lld", &reader);
        }
    }
}

void read_data_write()
{
    std::cerr << "Read and write data using cin, printf" << std::endl;
    for(auto i = 0; i < 1000; i++){
        for(auto j = 0; j < 10000; j++){
            std::cin >> reader;
            std::cout << reader;
        }
        std::cout << "/n";
    }
}
