#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512 // Standard TAR

// https://www.gnu.org/savannah-checkouts/gnu/tar/manual/html_node/Standard.html
struct posix_header
{                              /* byte offset */
  char name[100];               /*   0 */
  char mode[8];                 /* 100 */
  char uid[8];                  /* 108 */
  char gid[8];                  /* 116 */
  char size[12];                /* 124 */
  char mtime[12];               /* 136 */
  char chksum[8];               /* 148 */
  char typeflag;                /* 156 */
  char linkname[100];           /* 157 */
  char magic[6];                /* 257 */
  char version[2];              /* 263 */
  char uname[32];               /* 265 */
  char gname[32];               /* 297 */
  char devmajor[8];             /* 329 */
  char devminor[8];             /* 337 */
  char prefix[155];             /* 345 */
                                /* 500 */
};

long int getFileSize(FILE* f)
{
    if(!f){
        printf("Error calculating file size");
        return -1;
    }
    fseek(f, 0L, SEEK_END);
    long int res = ftell(f);
    rewind(f);

    return res;
}

int main(int argc, char** argv)
{
    FILE* f = fopen("testfile.txt", "rb");
    printf("%ld", getFileSize(f));
    fclose(f);
    return 0;  
}