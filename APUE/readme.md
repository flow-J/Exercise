error.c 在apue.3e的lib文件夹下，而apue.h 在apue.3e的include 文件夹下。
sudo vim apue.h 这一步在 最下面一行的#endif前加上#include "error.c"
sudo cp apue.h /usr/include/
sudo cp error.c /usr/include/
