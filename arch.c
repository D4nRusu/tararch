#include <stdio.h>
#include <string.h>

#include "arch.h"

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

struct posix_header initHeader(struct posix_header header)
{
    memset(&header, 0x0, sizeof(struct posix_header));
    header.name[99] = '\0';
    header.mode[7] = '\0';              
    header.uid[7] = '\0';             
    header.gid[7] = '\0';              
    header.size[11] = '\0';         
    header.mtime[11] = '\0';       
    header.chksum[7] = '\0';      
    header.typeflag = '\0';      
    header.linkname[99] = '\0';     
    header.magic[5] = '\0';      
    header.version[1] = '\0';     
    header.uname[31] = '\0';     
    header.gname[31] = '\0';   
    header.devmajor[7] = '\0';     
    header.devminor[7] = '\0';     
    header.prefix[154] = '\0';    
    header.padding[11] = '\0';
    return header;   
}

struct posix_header generateHeader(FILE* file, char* fname) // some of these are hardcoded values TODO: replace with actual ones
{                                                              // as well as implement the rest of the header values
    struct posix_header header = initHeader(header);
    
    // set name
    strcpy(header.name, fname);

    //set mode
    // strcpy(header.mode,"0000644");

    // //set uid
    // strcpy(header.uid,"0001750");

    // //set gid
    // strcpy(header.gid,"0001750");

    //set size
    sprintf(header.size, "%ld", getFileSize(file));
    return header;
}

void writeFile(FILE* fin, FILE* fout, char* finame)
{
    int a = 1;
}