#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma once

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
    char padding[12];             /* 500 */
                                  /* 512 */
};

long int getFileSize(FILE* f);

struct posix_header generateHeader(FILE* file, char* fname);

struct posix_header initHeader(struct posix_header header);

void writeFile(FILE* fin, FILE* fout, char* finame);
