void copy(int *f1, int *e1, int *f2) {
  int *cur = f1;
  while (cur != e1) {
    *f2++ = *cur++;
  }
}
