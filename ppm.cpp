
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Image.h"



//============================================================================
//                                  Main
//============================================================================
int main(int argc, char* argv[])
{
  //--------------------------------------------------------------------------
  // Read file "gargouille.ppm" into image (width and height)
  //--------------------------------------------------------------------------

  Image theimage;
  theimage.ppm_read_from_file("gargouille.ppm");


  //--------------------------------------------------------------------------
  // Create a desaturated (B&W) copy of the image we've just read and
  // write it into "gargouille_BW.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_bw

  Image image_bw(theimage);
  
  // Desaturate image_bw
  image_bw.ppm_desaturate();

  // Write the desaturated image into "gargouille_BW.ppm"
  image_bw.ppm_write_to_file("gargouille_BW.ppm");


  //--------------------------------------------------------------------------
  // Create a resized copy of the image and
  // write it into "gargouille_small.ppm"
  //--------------------------------------------------------------------------
  // Copy image into image_small
  Image image_small(theimage);

  // Shrink image_small size 2-fold
  image_small.ppm_shrink(2);

  // Write the shrinked image into "gargouille_small.ppm"
  image_small.ppm_write_to_file("gargouille_small.ppm");
 
  return 0;
}



































