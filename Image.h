
class Image
{


//============================================================================
//                        Function declarations
//============================================================================

public:

	//default constructor
	Image(void);

	//constructor that create a new Image from an Image which exists already 
	Image(const Image& im);

	// Write the image contained in <data> (of size <width> * <height>)
	// into plain RGB ppm file <file>
	void ppm_write_to_file(const char* filename);

	// Read the image contained in plain RGB ppm file <file>
	// into <data> and set <width> and <height> accordingly
	// Warning: data is malloc_ed, don't forget to free it
	void ppm_read_from_file(const char* filename);

	// Desaturate (transform to B&W) <image> (of size <width> * <height>)
	void ppm_desaturate(void);

	// Shrink image (of original size <width> * <height>) by factor <factor>
	// <width> and <height> are updated accordingly
	void ppm_shrink(int factor);

	//getters
	int getWidth(void) const;
	int getHeight(void) const;
	u_char* getData(void) const;

private:

	//attributes
	int width;   
	int height;
	u_char* data;  //pointer on the values R,G and B of the differents pixel

};
