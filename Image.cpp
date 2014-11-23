#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Image.h"

//============================================================================
//                          Constructors
//============================================================================

Image::Image(void)
{
  width=0;
  height=0;
  data = new u_char[1];
}


Image::Image(const Image& im)
{
  width = im.getWidth();
  height = im.getHeight();
  data = new u_char[3 * im.getWidth() * im.getHeight() * sizeof(u_char)];
  memcpy(data, im.getData(), 3 * width * height * sizeof(*data));
}

//============================================================================
//                            Getters
//============================================================================
int Image::getWidth(void) const{
  return width;
}

int Image::getHeight(void) const{
  return height;
}

u_char* Image::getData(void) const{
  return data;
}


//============================================================================
//                       Other Function definition
//============================================================================


//void Image::ppm_write_to_file(Image* im, const char* filename)
void Image::ppm_write_to_file(const char* filename)
{
  //create a pointer on a file and open the image into the file
  FILE* file = fopen(filename, "wb");


  // Write header
  fprintf(file, "P6\n%d %d\n255\n", width, height);

  // Write pixels
  fwrite(data, 3, width * height, file);

  //Close the file
  fclose(file);
}

void Image::ppm_read_from_file(const char* filename)
{

  //create a pointer on a file and open the image into the file
  FILE* file = fopen(filename, "rb");


  // Read file header
  fscanf(file, "P6\n%d %d\n255\n", &width, &height);

  //Delete the data temporary which had been created in the constructor
   delete [] data;

  // Allocate memory according to width and height
  data = new u_char[3 * (width) * (height) * sizeof(u_char)];
  

  // Read the actual image data
  fread(data, 3, width * height, file);

  //Close the file
  fclose(file);

}


void Image::ppm_desaturate(void)
{
  int x, y;

  // For each pixel ...

  for (x = 0 ; x < width ; x++)
  {
    for (y = 0 ; y < height ; y++)
    {
      u_int grey_lvl = 0;
      int rgb_canal;

      // Compute the grey level
      for (rgb_canal = 0 ; rgb_canal < 3 ; rgb_canal++)
      {
        grey_lvl += data[ 3 * (y * width + x) + rgb_canal ];
      }
      grey_lvl /= 3;
      assert(grey_lvl >= 0 && grey_lvl <=255);

      // Set the corresponding pixel's value in new_image
      memset(&data[3 * (y * width + x)], grey_lvl, 3);
    }
  }
}


void Image::ppm_shrink(int factor)
{
  // Compute new image size and allocate memory for the new image
  int new_width   = width / factor;
  int new_height  = height / factor;

  u_char* new_image = new u_char[3 * new_width * new_height];

  // Precompute factor^2 (for performance reasons)
  int factor_squared = factor * factor;

  // For each pixel of the new image...
  int x, y;
  for (x = 0 ; x < new_width ; x++)
  {
    for (y = 0 ; y < new_height ; y++)
    {
      // ... compute the average RGB values of the set of pixels (a square of side factor)
      // that correspond to the pixel we are creating.

      // Initialize RGB values for the new image's pixel
      u_int red   = 0;
      u_int green = 0;
      u_int blue  = 0;

      // Compute coordinates and index of the first (top-left) pixel from the
      // model image corresponding to the pixel we are creating
      int x0 = x * factor;
      int y0 = y * factor;
      int i0 = 3 * (y0 * width + x0);

      // Compute RGB values for the new pixel
      int dx, dy;
      for (dx = 0 ; dx < factor ; dx++)
      {
        for (dy = 0 ; dy < factor ; dy++)
        {
          // Compute the offset of the current pixel (in the model image)
          // with regard to the top-left pixel of the current "set of pixels"
          int delta_i = 3 * (dy * (width) + dx);

          // Accumulate RGB values
          red   += data[i0+delta_i];
          green += data[i0+delta_i+1];
          blue  += data[i0+delta_i+2];
        }
      }

      // Divide RGB values to get the mean values
      red   /= factor_squared;
      green /= factor_squared;
      blue  /= factor_squared;

      // Set new pixel's RGB values
      new_image[ 3 * (y * new_width + x) ]     = red;
      new_image[ 3 * (y * new_width + x) + 1 ] = green;
      new_image[ 3 * (y * new_width + x) + 2 ] = blue;
    }
  }

  // Update image size
  width = new_width;
  height = new_height;

  // Update image

  delete [] data;
  data = new_image;

}




