/*bwt.h*/
#ifndef BWT_H
#define BWT_H
void circular_shift(char*,char*,char*,int*);
int measure_specificity(char*);
int bwtScore(char* sequence);
#endif // BWT_H
