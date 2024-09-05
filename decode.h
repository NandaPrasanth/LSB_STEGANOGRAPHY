/*

Author:Nanda P

Organisation:Emertxe

Date:30-05-2024

Description:Steganography is a technique used to hide information within a digital medium,such as image.It involves modifying the least significant bit of each data byte in the carrier medium to embed the hidden message.

The main objectives of the project:
1)Encoding secret data in the least bits of carrier file's pixels
2)Decoding secret data without altering the image.
*/
#ifndef DECODE_H
#define DECODE_H


#include "types.h" //contains user defined types


/* 
 * Structure to store information required for
 * decoding secret message from output
 * Info about output and intermediate data is
 * also stored
 */

typedef struct _DecodeInfo
{
    /*input source code image info*/

    char *d_src_image_fname;
    FILE *d_fptr_src_image;
    char *secret_fname;
    char secret_extn[20];
    FILE *fptr_secret;
    long secret_file_size;
}Decode;
/* read and validate encode args from argv */
Status read_and_validate_decode_args(char *argv[],Decode *decInfo);

/* perform decoding */
Status do_decoding(Decode *decInfo);

/* skip input image header data */
Status skip_bmp_header(FILE *d_fptr_src_image);

/* Decode magic string */
Status decode_magic_string(Decode *decInfo);

/* Decode secret file extension */
Status decode_secret_file_extn(Decode *decInfo);

/* Decode secret file size */
Status decode_secret_file_size(Decode *decInfo);

/* decode secret file data */
Status decode_secret_file_data(Decode *decInfo);

/* decode byte from lsb of image array */
Status decode_byte_from_lsb(char *data);

/*decode size  to lsb of image data array*/
Status decode_size_from_lsb(char *image_buffer);

/*Function to open files */
Status decode_open_files(Decode *decInfo);
/* function to print error message */
void error_msg();
#endif



