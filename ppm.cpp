
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "Image.h"



//============================================================================
//                                  Main
//============================================================================
int main(int argc, char* argv[])
{
  //--------------------------------------------------------------------------
  // Read file "gargouille.ppm" into image (width and height)
  //--------------------------------------------------------------------------

  image* theimage = NULL;

  theimage = ppm_read_from_file("gargouille.ppm");
 


  //--------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read and
  // write it into "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_bw

  image* image_bw=NULL;
  image_bw=(image*)malloc(sizeof(image)); 
  image_bw->width = theimage->width;
  image_bw->height = theimage->height;

  image_bw->data = (u_char*)malloc(3 * (image_bw->width) * (image_bw->height) * sizeof(*(image_bw->data)));

  memcpy(image_bw->data, theimage->data, 3 * (image_bw->width) * (image_bw->height) * sizeof(*(image_bw->data)));


  // Desaturate image_bw
  //ppm_desaturate(image_bw, width, height);
  ppm_desaturate(image_bw);

  // Write the desaturated image into "gargouille_BW.ppm"
  ppm_write_to_file(image_bw, "gargouille_BW.ppm");


  // Free the desaturated image
  //free(image_bw);


  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small

  image* image_small=NULL;
  image_small=(image*)malloc(sizeof(image)); 
  image_small->width = theimage->width;
  image_small->height = theimage->height;

  image_small->data = (u_char*)malloc(3 * (image_small->width) * (image_small->height) * sizeof(*(image_small->data)));

  memcpy(image_small->data, theimage->data, 3 * (image_small->width) * (image_small->height) * sizeof(*(image_small->data)));


  // Shrink image_small size 2-fold
  ppm_shrink(image_small, 2);

  // Write the shrinked image into "gargouille_small.ppm"
  ppm_write_to_file(image_small, "gargouille_small.ppm");
 
  ppm_write_to_file(theimage,"gargouille2.ppm");
  
  // Free the not yet freed images

  //free(image_small);
  free(image_small);
  free(image_bw);
  free(theimage);


  return 0;
}



































