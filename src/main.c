#include <stdlib.h>
#include <stdio.h>
#include "bmp_reader.h"

void freeBMPFile(BMPFile* bmp_file) {
  if(bmp_file) {
    if(bmp_file->data)
      free(bmp_file->data);
    free(bmp_file);
  };
};
int main() {
    
    FILE* fp = fopen("src/red.bmp", "r");
    
    BMPFile* bmpf = (BMPFile*)malloc(sizeof(BMPFile));
    fread(&bmpf->bhdr, sizeof(BMPHeader), 1, fp);
    fread(&bmpf->dhdr, sizeof(DIBHeader), 1, fp);

    int data_size = bmpf->dhdr.width * bmpf->dhdr.height * bmpf->dhdr.bits_per_pixel / 8;
    bmpf->data = (unsigned char*)malloc(data_size);
    fseek(fp, bmpf->bhdr.pixel_offset, SEEK_SET);
    fread(bmpf->data, data_size, 1, fp);
    
    for (int i = 0; i < data_size; i+=3) {
        if (bmpf->data[i] == 0 && bmpf->data[i+1] == 0 && bmpf->data[i+2] == 255) {
            bmpf->data[i] = 255;
            bmpf->data[i+1] = 255; 
        } 
    }   
    
    FILE* fp_new = fopen("new.bmp", "w");

    fwrite(&bmpf->bhdr, sizeof(BMPHeader), 1, fp_new);
    fwrite(&bmpf->dhdr, sizeof(DIBHeader), 1, fp_new);
    fwrite(bmpf->data, data_size, 1, fp_new);
    
    freeBMPFile(bmpf);
    fclose(fp);
    fclose(fp_new);
    return 0;
}