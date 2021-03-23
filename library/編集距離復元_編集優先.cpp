#include <stdio.h>
#include <stdlib.h>

int vmax_(int x, int y) { return x > y ? x : y; }                  // 2つの最大値
int vmax3_(int a, int b, int c) { return vmax_(a, vmax_(b, c)); }  // 3つの最大値
int vmin_(int x, int y) { return x < y ? x : y; }                  // 2つの最小値
int vmin3_(int a, int b, int c) { return vmin_(a, vmin_(b, c)); }  // 3つの最小値

void zeros_(     // 文字列用の配列を\0で初期化する関数
    char* data,  // 文字列を格納する配列
    int N        // 文字列の長さ
) {
  for (int i = 0; i < N; ++i) {
    data[i] = '\0';  // 配列のi番目の要素を\0で初期化
  }
}

char* read_string_(  // 文字列用のメモリ確保と、標準入力からの文字列読み込みを行う関数
    const int N      // 文字列の長さ
) {
  char* data = (char*)malloc(N * sizeof(char));  // 配列に動的メモリを割り当てる
  if (data == NULL) {                            // メモリ確保に失敗した際のエラー処理 
    printf("Can not allocate memory. 'data' is NULL.\n");
    exit(1);  // メモリ確保に失敗したら、プログラムを終了
  }
  zeros_(data, N);            // 配列dataを関数zeros_で初期化
  scanf("%s", data);          // 文字列を読み込む
  if (data[N - 1] != '\0') {  // 文字列がN以上の場合のエラー処理
    printf("Reading invalid string\n");
    exit(1);  // プログラムを終了
  }
  return data;  // 配列dataの先頭のポインタを返す
}

int count_len_(        // 文字列の長さを計算する関数
    const char* array  // 文字列用の配列
) {
  int ri = 0;
  while (array[ri] != '\0') {  // 配列として定義されているが, 中身がないもの, 空文字
    ri++;
  }
  return ri;  // 文字列の長さriを返す
}

int** mal_2d_(const int len_x, const int len_y){
  int** memo = (int **)malloc(sizeof(int *)*(len_x));
    if(memo == NULL){
        printf("Can not allocate memory. 'memo' is NULL.\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<len_x;++i){
        memo[i] = (int*)malloc(sizeof(int)*(len_y));
        if(memo[i] == NULL){
            printf("Can not allocate memory. 'memo[i]' is NULL.\n");
            exit(EXIT_FAILURE);
        }
    }
    return memo;
}

void free_2d_(int **array, int len_x){
  for(int i=0;i<len_x;++i)free(array[i]);
  free(array);
}

int delta(char *X, int m, char *Y, int n) {
  return (X[m] != Y[n]);
}

int ld_dp(char *X, int m, char *Y, int n, int **dpt) {
  for(int i=0;i<m+1;i++)for(int j=0;j<n+1;j++)dpt[i][j] = 1e9;
  for(int i=0;i<m+1;i++)dpt[i][0] = i;
  for(int j=0;j<n+1;j++)dpt[0][j] = j;

  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      dpt[i][j] = vmin_(dpt[i][j], dpt[i-1][j-1] + delta(X, i-1, Y, j-1));
      dpt[i][j] = vmin_(dpt[i][j], dpt[i][j-1] + 1);
      dpt[i][j] = vmin_(dpt[i][j], dpt[i-1][j] + 1);
    }
  }
  return dpt[m][n];
}

void show_matrix(char *X, int m, char *Y, int n, int **dpt);
void get_ops(char *X, int m, char *Y, int n, int **dpt,
            char *seq_x, char *seq_y, char *ops);

int main() {
  int N = 21;                      // ???
  char *data_x = read_string_(N);  // ???
  char *data_y = read_string_(N);  // ???
  int len_x = count_len_(data_x);  // ???
  int len_y = count_len_(data_y);  // ???
  int **dpt = mal_2d_(len_x+1, len_y+1); // ???
  char *ops = (char*)malloc(sizeof(char)*(2*N+1)); //編集操作列
  char *seq_x = (char*)malloc(sizeof(char)*(2*N+1));
  char *seq_y = (char*)malloc(sizeof(char)*(2*N+1));

  //get_dp_table_(data_x, len_x, data_y, len_y, dpt);  //DP実行
  ld_dp(data_x, len_x, data_y, len_y, dpt); //上の代わり
  show_matrix(data_x, len_x, data_y, len_y, dpt);
  get_ops(data_x, len_x, data_y, len_y, dpt, seq_x, seq_y, ops);

  free(data_x);  // ???
  free(data_y);  // ???
  free(ops);
  free(seq_x);
  free(seq_y);
  free_2d_(dpt, len_x);
  return 0;      // ???
}

void show_matrix(char *X, int m, char *Y, int n, int **dpt){
  printf("    ");
  for(int j=0;j<n;j++)printf("%3c",Y[j]);
  printf("\n");

  for(int i=0;i<m+1;i++){
    if(i == 0)printf(" ");
    else printf("%c", X[i-1]);

    for(int j=0;j<n+1;j++){
      printf("%3d", dpt[i][j]);
    }
    printf("\n");
  }
}

//操作列規則:コピー/置換をGreedyに探索
void get_ops(char *X, int m, char *Y, int n, int **dpt,char *seq_x, char *seq_y, char *ops){
  int i = m, j = n, idx = 0;
    while (i > 0 && j > 0)
    {
        // (i-1, j-1) -> (i, j) と更新されていた場合
        if(dpt[i][j] == dpt[i-1][j-1] + (X[i-1] != Y[j-1]) ) {
            if(X[i-1] != Y[j-1])ops[idx++] = 'R';
            else ops[idx++] = '=';
            --i, --j;
        }
        else if (dpt[i][j] == dpt[i-1][j] + 1) {//(i-1, j) -> (i, j) と更新されていた場合
            --i;
            ops[idx++] = 'D';
        }
        else if (dpt[i][j] == dpt[i][j-1] + 1) {// (i, j-1) -> (i, j) と更新されていた場合
            --j;
            ops[idx++] = 'I';
        }
    }
    while(i > 0)ops[idx++] = 'D',i--;
    while(j > 0)ops[idx++] = 'I',j--;
    //reverse
    for(int i=0;i<idx/2;i++){
      auto tmp = ops[idx - i - 1];
      ops[idx - i - 1] = ops[i];
      ops[i] = tmp;
    }
    //得られたops配列からseq_xとseq_yを作る
    int idx_x = 0, idx_y = 0;
    for(int i=0;i<idx;i++){
      if(ops[i] == 'I')seq_x[i] = ' ';
      else seq_x[i]= X[idx_x++];
    }
    for(int i=0;i<idx;i++){
      if(ops[i] == 'D')seq_y[i] = ' ';
      else seq_y[i]= Y[idx_y++];
    }
    for(int i=0;i<idx;i++)printf("%c",seq_x[i]);
    printf("\n");
    for(int i=0;i<idx;i++)printf("%c",seq_y[i]);
    printf("\n");
    for(int i=0;i<idx;i++)printf("%c",ops[i]);
    printf("\n");
}