//===========================================================================
//                           Structure
//===========================================================================

typedef struct
{
  int width;
  int height;
  u_char* data;

}image;


//============================================================================
//                           Function declarations
//============================================================================
// Write the image contained in <data> (of size <width> * <height>)
// into plain RGB ppm file <file>
//void ppm_write_to_file(int width, int height, u_char* data, char* nom);
void ppm_write_to_file(image* im, const char* filename);

// Read the image contained in plain RGB ppm file <file>
// into <data> and set <width> and <height> accordingly
// Warning: data is malloc_ed, don't forget to free it
//void ppm_read_from_file(int *width, int *height, u_char** data, char* filename);
image* ppm_read_from_file(const char* filename);

// Desaturate (transform to B&W) <image> (of size <width> * <height>)
void ppm_desaturate(image* im);

// Shrink image (of original size <width> * <height>) by factor <factor>
// <width> and <height> are updated accordingly
void ppm_shrink(image* im, int factor);

