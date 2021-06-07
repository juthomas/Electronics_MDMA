/* GIMP RGB C-Source image dump (items.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[8 * 8 * 3 + 1];
} gimp_image = {
  8, 8, 3,
  "\377\000\000?\000\000\000\000\000\000\000\000\000\000\000\000\000\000?\000\000\377\000\000\377\000\000\377\000\000?\000\000\000"
  "\000\000\000\000\000?\000\000\377\000\000\377\000\000\377\000\000\000\000\000\377\000\000?\000\000?\000\000\377\000\000\000"
  "\000\000\377\000\000\377\000\000\000\000\000\000\000\000\377\000\000\377\000\000\000\000\000\000\000\000\377\000\000\377"
  "\000\000\000\000\000\000\000\000\377\000\000\377\000\000\000\000\000\000\000\000\377\000\000\377\000\000\000\000\000\377\000"
  "\000?\000\000?\000\000\377\000\000\000\000\000\377\000\000\377\000\000\377\000\000?\000\000\000\000\000\000\000\000?\000\000"
  "\377\000\000\377\000\000\377\000\000?\000\000\000\000\000\000\000\000\000\000\000\000\000\000?\000\000\377\000\000",
};

