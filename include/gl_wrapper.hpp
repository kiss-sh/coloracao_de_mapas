#ifndef GL_WRAPPER
#define GL_WRAPPER

struct VerticePosition {
  int x;
  int y;
};

struct ArestaPosition {
  int x_begin;
  int y_begin;
  int x_end;
  int y_end;
};

void open_window(int, int);

#endif
