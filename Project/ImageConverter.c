/* GIMP RGBA C-Source image dump (TimerBG.c) */

#include <stdio.h>
#include "/Users/tmp/Desktop/MDMA_Images/BG_C/DevilEyes.h"

int main()
{
  unsigned short color_palette[16];
  int nb_color = 0;

  for (int i = 0; i < gimp_image.width * gimp_image.height; i++)
  {
    for (int j = 0; j < nb_color; j++)
    {
      if (((unsigned short *)gimp_image.pixel_data)[i] == color_palette[j])
      {
        (((unsigned short *)gimp_image.pixel_data)[i]) = j;
        goto quit_for;
      }
    }
    color_palette[nb_color] = (((unsigned short *)gimp_image.pixel_data)[i]);
    // printf("%#.4x\n",(((unsigned short *)gimp_image.pixel_data)[i]));
    ((unsigned short *)gimp_image.pixel_data)[i] = nb_color;
    nb_color++;
quit_for:
    ;
  }


  printf("const unsigned char ____BG[] PROGMEM={");
  for (int i = 0; i < gimp_image.height; i++)
  {
    for (int j = 0; j < gimp_image.width; j += 2)
    {
      (((unsigned short *)gimp_image.pixel_data)[j + i * gimp_image.width]) ? printf("%#x", (((unsigned short *)gimp_image.pixel_data)[j + i * gimp_image.width])) : printf("0x0");
      printf("%x, ", (((unsigned short *)gimp_image.pixel_data)[j+1 + i * gimp_image.width]));
    }
    printf("\n");
  }
  printf("};\nconst unsigned short ____BGPalette[] = {  ");
  for (int j = 0; j < nb_color; j++)
  {
    printf("%#.4x, ", color_palette[j]);
  }
  printf("};\n");
}
