#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "filestat.c"


void dir_stat(char * path){
  DIR* dir = opendir(path);

  long size = 0;
  
  struct dirent* current;
  current = readdir(dir);
  while(current){
    if(current -> d_type != DT_REG){
      printf("directory: %s\n", current -> d_name);
    }
    else{
      printf("file: %s\n", current -> d_name);
      size += file_stat(current -> d_name);
    }
    current = readdir(dir);
  }
  closedir(dir);
  printf("Size of directory: %ld bytes\n", size);
}

int main(){
  dir_stat(".");
  
  return 0;
}
