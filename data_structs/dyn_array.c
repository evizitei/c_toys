/*
Create a list, seqList, of N empty sequences,
where each sequence is indexed from 0 to N-1.
The elements within each of the N sequences also use 0-indexing.

Create an integer, lastAnswer, and initialize it to 0.

The 2 types of queries that can be performed on your list of
sequences are described below:

Query: 1 x y
Find the sequence, seq, at index ((x^lastAnswer) % N) in seqList.
Append integer y to sequence seq.

Query: 2 x y
Find the sequence, seq, at index ((x^lastAnswer) % N) in seqList.
Find the value of element y % size in seq (where size is the size of seq)
 and assign it to lastAnswer.
Print the new value of lastAnswer on a new line

Sample Input:
2 5
1 0 5
1 1 7
1 0 3
2 1 0
2 1 1

Sample Output:
7
3
*/
#include <stdlib.h>
#include <stdio.h>

struct query {
  int type;
  int x;
  int y;
};

int runQuery(int **seqList, int *seqSizes, int n, struct query curQ, int lastAnswer){
  int seqIdx = (curQ.x ^ lastAnswer) % n;
  int *seq = seqList[seqIdx];
  int seqSize = seqSizes[seqIdx];
  if(curQ.type == 1){
    // append value
    // TODO: check size and double as necessary
    if(seqSize >=2 && ((seqSize & (seqSize - 1)) == 0)){
      // is power of 2, double size
      int *bigSeq = realloc(seq, seqSize * 2 * sizeof(int));
      if(!bigSeq){
        printf("ERROR: Realloc failed!");
        return -1;
      }
      seq = bigSeq;
      seqList[seqIdx] = bigSeq;
    }
    seq[seqSize] = curQ.y;
    seqSizes[seqIdx] = seqSize + 1;
    return lastAnswer;
  }else{
    int value = seq[curQ.y % seqSize];
    printf("%d\n", value);
    return value;
  }
}

int main(){
  int n, queryCount;
  scanf("%d %d", &n, &queryCount);
  struct query *queries = malloc(queryCount * sizeof(struct query));
  for(int qi = 0; qi < queryCount; qi++){
    struct query curQ;
    scanf("%d %d %d", &curQ.type, &curQ.x, &curQ.y);
    queries[qi] = curQ;
  }

  // TODO: This is probably using too much memory, initalize to empty;
  // initialize seq list
  int **seqList = malloc(n * sizeof(int *));
  int *seqSizes = calloc(n, sizeof(int)); // all seqs start at 0 size
  for(int ni = 0; ni < n; ni++){
    // initialize them all to small arrays, will double as necessary
    seqList[ni] = malloc(2 * sizeof(int));
  }
  int lastAnswer = 0;

  // run queries in order
  for(int qi = 0; qi < queryCount; qi++){
    struct query curQ = queries[qi];
    lastAnswer = runQuery(seqList, seqSizes, n, curQ, lastAnswer);
  }

  return 0;
}
