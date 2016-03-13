#ifndef GENOZCS_H
#define genoZCS_H
int getGenoLength(char* geno);
char* cutLineBreaks_M(char* geno);
void capitalToLowerCase(char* geno);
char* getSequenceByFileName_M(char* fileNaem);
char* getBinsSequence_M(char* sequence,int sta,int ed);
int* getBins_M(char* binsName,int* binsSize);
void outputVector(int* thisVector,int vectorSize,char* outputFileName);
#endif // GENOZCS
