#pragma once
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push,1) 
typedef struct BMPHeader {
  unsigned char ID[2];
  unsigned int file_size;
  unsigned char unused[4];
  unsigned int pixel_offset;
} BMPHeader;

typedef struct DIBHeader {
  unsigned int header_size;
  unsigned int width;
  unsigned int height;
  unsigned short color_planes;
  unsigned short bits_per_pixel;
  unsigned int compresion; 
  unsigned int data_size;
  unsigned int pwidth;
  unsigned int pheight;
  unsigned int colors_count;
  unsigned int imp_colors_count;
} DIBHeader;

typedef struct BMPFile {
  BMPHeader bhdr;
  DIBHeader dhdr;
  unsigned char* data;
} BMPFile;
#pragma pack(pop)
