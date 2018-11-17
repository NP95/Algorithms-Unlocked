```bash
$ g++ -std=c++17 -O3 -Wall -Wextra -pedantic -pthread -march=native -DONLINE_JUDGE=1 -fomit-frame-pointer -g -DHASH=1 -DOFFLINE_START_BUILD=1 code.cpp -o code.out

$ g++ -std=c++17 -O3 -Wall -Wextra -pedantic -pthread -march=native -DONLINE_JUDGE=1 -fomit-frame-pointer -g -DOFFLINE_START_BUILD=1 code.cpp -o code.exe
```

```
//:configuration = Debug
OTHER_LDFLAGS = -I/usr/local/include -I/usr/local/opt/openssl/include -L/usr/local/opt/openssl/lib -L/usr/local/bin -L/usr/local/lib -L/usr/bin -L/usr/lib -lcurl -lcurlpp -lpthread -lssl -lcrypto

//:configuration = Release
OTHER_LDFLAGS = -I/usr/local/include -I/usr/local/opt/openssl/include -L/usr/local/opt/openssl/lib -L/usr/local/bin -L/usr/local/lib -L/usr/bin -L/usr/lib -lcurl -lcurlpp -lpthread -lssl -lcrypto

//:completeSettings = some
OTHER_LDFLAGS

```

#### Script to run after Xcode build (for automated git push.)

```
cd ../../../../../../../../../../../../
cd Users/sumitlahiri/
echo 'pwd' | sudo -S /usr/bin/rsync -r ./Documents/Coding/Code_Template/./ ./Documents/ProjectStudio/Algorithms-Unlocked/Code\ Template/Code_Template
echo 'pwd' | sudo -S ./git-merge-pull-diff-rebase.sh
```

### Script

```bash
sudo git pull origin master
sudo git rebase
sudo git add .
output=$(date | openssl sha256 | openssl sha256 )
commit=$(date | openssl md5 )
sudo git commit -a -m "X-Code Mac $commit " -m "$output"
echo "$commit : $output"
sudo git push origin master
```
