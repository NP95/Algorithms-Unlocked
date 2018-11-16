```bash
$ g++ -std=c++17 -O3 -Wall -Wextra -pedantic -pthread -march=native -DONLINE_JUDGE=1 -fomit-frame-pointer -g -DHASH=1 -DOFFLINE_START_BUILD=1 -DOFFLINE_END_BUILD=1 code.cpp -o code

//:configuration = Debug
OTHER_LDFLAGS = -I/usr/local/include -I/usr/local/opt/openssl/include -L/usr/local/opt/openssl/lib -L/usr/local/bin -L/usr/local/lib -L/usr/bin -L/usr/lib -lcurl -lcurlpp -lpthread -lssl -lcrypto

//:configuration = Release
OTHER_LDFLAGS = -I/usr/local/include -I/usr/local/opt/openssl/include -L/usr/local/opt/openssl/lib -L/usr/local/bin -L/usr/local/lib -L/usr/bin -L/usr/lib -lcurl -lcurlpp -lpthread -lssl -lcrypto

//:completeSettings = some
OTHER_LDFLAGS

```
