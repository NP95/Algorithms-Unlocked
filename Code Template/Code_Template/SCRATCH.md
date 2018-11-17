#  Scratch file

```cpp
char * const file_parameters[] = { "/bin/cp", "./../CodeChef_Codes", "./../../ProjectStudio/Algorithms-Unlocked/Code\ Template/Code_Template", NULL};
char * const zip_parameters[] = { "/usr/bin/unzip", "-o", "-qq" ,"./Code/download.zip", "-d", "./Code", NULL };
"/bin/cp", "./../CodeChef_Codes", "./../../ProjectStudio/Algorithms-Unlocked/Code\ Template/Code_Template", NULL
"/usr/bin/unzip", "-o", "-qq" ,"./Code/download.zip", "-d", "./Code", NULL
```
```
https://github.com/SpawnTree/Algorithms-Unlocked.git 5f7709a69b6abdbf11Ded3e1e3793f5f99f94e57
```
#### Script to run after Xcode build (for automated git push.)

```
cd ../../../../../../../../../../../../
cd Users/sumitlahiri/
echo 'pwd' | sudo -S /bin/cp -r ./Documents/Coding/Code_Template/./ ./Documents/ProjectStudio/Algorithms-Unlocked/Code\ Template/Code_Template
echo 'pwd' | sudo -S ./git-merge-pull-diff-rebase.sh
```
