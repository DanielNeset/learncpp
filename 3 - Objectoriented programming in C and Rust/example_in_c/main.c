#include <stdio.h>

typedef struct {
  double length;
  double width;
} Surface;

double surface_area(Surface *surface) {
  return surface->length * surface->width;
}

typedef struct {
  Surface surface;
  double red;
  double green;
  double blue;
} ColoredSurface;

int main() {
  Surface surface = {2.0, 3.0};
  printf("%f\n", surface.width);
  printf("%f\n", surface_area(&surface));

  ColoredSurface colored_surface = {{2.0, 3.0}, 0.0, 0.0, 1.0};

  printf("%f\n", colored_surface.surface.width);
  printf("%f\n", colored_surface.blue);
  printf("%f\n", surface_area((Surface *)&colored_surface));
}
