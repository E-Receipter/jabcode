//build the getter and setter functions for all structs and values used in src/jabcode/include/jabcode.h
#include "jabcode.h"
#include<stdlib.h>
#include<stdio.h>
jab_bitmap *createJabBitmap(
    int width,int height,
    int pixel_length
    ){
        int bits_per_pixel = BITMAP_BITS_PER_PIXEL;
        int bits_per_channel = BITMAP_BITS_PER_CHANNEL;
        int channel_count = BITMAP_CHANNEL_COUNT;

        jab_bitmap* bitmap = (jab_bitmap*)malloc(sizeof(jab_bitmap) + pixel_length);
        bitmap -> width = width;
        bitmap -> height = height;
        bitmap -> bits_per_pixel = bits_per_pixel;
        bitmap -> bits_per_channel = bits_per_channel;
        bitmap -> channel_count = channel_count;
        return bitmap;
    }

jab_byte* getPixelArray(jab_bitmap* bitmap){
    return bitmap -> pixel;
}

jab_data* decode(jab_bitmap *bitmap){
    jab_int32 decode_status;
	jab_decoded_symbol symbols[MAX_SYMBOL_NUMBER];
    return decodeJABCodeEx(bitmap, NORMAL_DECODE, &decode_status, symbols, MAX_SYMBOL_NUMBER);
}

jab_char* getData(jab_data *data){
    return data -> data;
}
jab_int32 getLength(jab_data *data){
    return data -> length;
}

int main(){
    jab_char file_name[] = "../src/test.png";
    jab_bitmap *img = readImage(file_name);
    jab_data *data = decode(img);
    FILE* output_file = fopen("../src/test2.txt", "wb");
    fwrite(data->data,data->length,1,output_file);
    fclose(output_file);
}