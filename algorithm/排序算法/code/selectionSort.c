#include <stdio.h>
#include <windows.h>


void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArr(int arr[], int n) {
  printf("当前数组：");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void selectionSort(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    printf("\n========== 外层第 %d 次选择开始 (i = %d) ==========\n", i + 1, i);

    int minIndex = i;
    printf("初始最小值：arr[%d] = %d\n", minIndex, arr[minIndex]);

    for (int j = i + 1; j < len; j++) {
      printf("\n-- 内层第 %d 次比较 (j = %d) --\n", j - i, j);
      printArr(arr, len);
      printf("比较：arr[%d] = %d 和 当前最小值 arr[%d] = %d\n", j, arr[j],
             minIndex, arr[minIndex]);

      if (arr[j] < arr[minIndex]) {
        minIndex = j;
        printf("=> 新的最小值：arr[%d] = %d\n", minIndex, arr[minIndex]);
      } else {
        printf("=> 无变化，保持最小值为 arr[%d] = %d\n", minIndex,
               arr[minIndex]);
      }
    }

    if (minIndex != i) {
      printf(
          "\n>> 当前位置 arr[%d] = %d 不是最小值，执行交换 arr[%d] <-> "
          "arr[%d]\n",
          i, arr[i], i, minIndex);
      swap(&arr[i], &arr[minIndex]);
      printf(">> 交换后数组：\n");
      printArr(arr, len);
    } else {
      printf("\n>> 当前位置已经是最小值，无需交换\n");
    }

    printf("========== 外层第 %d 次选择结束 ==========\n", i + 1);
    printArr(arr, len);
  }
}

void selectionSort2(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    int minIndex = i;
    for (int j = i + 1; j < len; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex != i) {
      swap(&arr[i], &arr[minIndex]);
    }
  }
}

int main() {
  // 设置控制台输出为 UTF-8
  SetConsoleOutputCP(CP_UTF8);
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组：\n");
  printArr(arr, len);

  selectionSort(arr, len);

  printf("\n排序后数组：\n");
  printArr(arr, len);

  return 0;
}

/**
原始数组：
当前数组：64 34 25 12 22 11 90

========== 外层第 1 次选择开始 (i = 0) ==========
初始最小值：arr[0] = 64

-- 内层第 1 次比较 (j = 1) --
当前数组：64 34 25 12 22 11 90
比较：arr[1] = 34 和 当前最小值 arr[0] = 64
=> 新的最小值：arr[1] = 34

-- 内层第 2 次比较 (j = 2) --
当前数组：64 34 25 12 22 11 90
比较：arr[2] = 25 和 当前最小值 arr[1] = 34
=> 新的最小值：arr[2] = 25

-- 内层第 3 次比较 (j = 3) --
当前数组：64 34 25 12 22 11 90
比较：arr[3] = 12 和 当前最小值 arr[2] = 25
=> 新的最小值：arr[3] = 12

-- 内层第 4 次比较 (j = 4) --
当前数组：64 34 25 12 22 11 90
比较：arr[4] = 22 和 当前最小值 arr[3] = 12
=> 无变化，保持最小值为 arr[3] = 12

-- 内层第 5 次比较 (j = 5) --
当前数组：64 34 25 12 22 11 90
比较：arr[5] = 11 和 当前最小值 arr[3] = 12
=> 新的最小值：arr[5] = 11

-- 内层第 6 次比较 (j = 6) --
当前数组：64 34 25 12 22 11 90
比较：arr[6] = 90 和 当前最小值 arr[5] = 11
=> 无变化，保持最小值为 arr[5] = 11

>> 当前位置 arr[0] = 64 不是最小值，执行交换 arr[0] <-> arr[5]
>> 交换后数组：
当前数组：11 34 25 12 22 64 90
========== 外层第 1 次选择结束 ==========
当前数组：11 34 25 12 22 64 90

========== 外层第 2 次选择开始 (i = 1) ==========
初始最小值：arr[1] = 34

-- 内层第 1 次比较 (j = 2) --
当前数组：11 34 25 12 22 64 90
比较：arr[2] = 25 和 当前最小值 arr[1] = 34
=> 新的最小值：arr[2] = 25

-- 内层第 2 次比较 (j = 3) --
当前数组：11 34 25 12 22 64 90
比较：arr[3] = 12 和 当前最小值 arr[2] = 25
=> 新的最小值：arr[3] = 12

-- 内层第 3 次比较 (j = 4) --
当前数组：11 34 25 12 22 64 90
比较：arr[4] = 22 和 当前最小值 arr[3] = 12
=> 无变化，保持最小值为 arr[3] = 12

-- 内层第 4 次比较 (j = 5) --
当前数组：11 34 25 12 22 64 90
比较：arr[5] = 64 和 当前最小值 arr[3] = 12
=> 无变化，保持最小值为 arr[3] = 12

-- 内层第 5 次比较 (j = 6) --
当前数组：11 34 25 12 22 64 90
比较：arr[6] = 90 和 当前最小值 arr[3] = 12
=> 无变化，保持最小值为 arr[3] = 12

>> 当前位置 arr[1] = 34 不是最小值，执行交换 arr[1] <-> arr[3]
>> 交换后数组：
当前数组：11 12 25 34 22 64 90
========== 外层第 2 次选择结束 ==========
当前数组：11 12 25 34 22 64 90

========== 外层第 3 次选择开始 (i = 2) ==========
初始最小值：arr[2] = 25

-- 内层第 1 次比较 (j = 3) --
当前数组：11 12 25 34 22 64 90
比较：arr[3] = 34 和 当前最小值 arr[2] = 25
=> 无变化，保持最小值为 arr[2] = 25

-- 内层第 2 次比较 (j = 4) --
当前数组：11 12 25 34 22 64 90
比较：arr[4] = 22 和 当前最小值 arr[2] = 25
=> 新的最小值：arr[4] = 22

-- 内层第 3 次比较 (j = 5) --
当前数组：11 12 25 34 22 64 90
比较：arr[5] = 64 和 当前最小值 arr[4] = 22
=> 无变化，保持最小值为 arr[4] = 22

-- 内层第 4 次比较 (j = 6) --
当前数组：11 12 25 34 22 64 90
比较：arr[6] = 90 和 当前最小值 arr[4] = 22
=> 无变化，保持最小值为 arr[4] = 22

>> 当前位置 arr[2] = 25 不是最小值，执行交换 arr[2] <-> arr[4]
>> 交换后数组：
当前数组：11 12 22 34 25 64 90
========== 外层第 3 次选择结束 ==========
当前数组：11 12 22 34 25 64 90

========== 外层第 4 次选择开始 (i = 3) ==========
初始最小值：arr[3] = 34

-- 内层第 1 次比较 (j = 4) --
当前数组：11 12 22 34 25 64 90
比较：arr[4] = 25 和 当前最小值 arr[3] = 34
=> 新的最小值：arr[4] = 25

-- 内层第 2 次比较 (j = 5) --
当前数组：11 12 22 34 25 64 90
比较：arr[5] = 64 和 当前最小值 arr[4] = 25
=> 无变化，保持最小值为 arr[4] = 25

-- 内层第 3 次比较 (j = 6) --
当前数组：11 12 22 34 25 64 90
比较：arr[6] = 90 和 当前最小值 arr[4] = 25
=> 无变化，保持最小值为 arr[4] = 25

>> 当前位置 arr[3] = 34 不是最小值，执行交换 arr[3] <-> arr[4]
>> 交换后数组：
当前数组：11 12 22 25 34 64 90
========== 外层第 4 次选择结束 ==========
当前数组：11 12 22 25 34 64 90

========== 外层第 5 次选择开始 (i = 4) ==========
初始最小值：arr[4] = 34

-- 内层第 1 次比较 (j = 5) --
当前数组：11 12 22 25 34 64 90
比较：arr[5] = 64 和 当前最小值 arr[4] = 34
=> 无变化，保持最小值为 arr[4] = 34

-- 内层第 2 次比较 (j = 6) --
当前数组：11 12 22 25 34 64 90
比较：arr[6] = 90 和 当前最小值 arr[4] = 34
=> 无变化，保持最小值为 arr[4] = 34

>> 当前位置已经是最小值，无需交换
========== 外层第 5 次选择结束 ==========
当前数组：11 12 22 25 34 64 90

========== 外层第 6 次选择开始 (i = 5) ==========
初始最小值：arr[5] = 64

-- 内层第 1 次比较 (j = 6) --
当前数组：11 12 22 25 34 64 90
比较：arr[6] = 90 和 当前最小值 arr[5] = 64
=> 无变化，保持最小值为 arr[5] = 64

>> 当前位置已经是最小值，无需交换
========== 外层第 6 次选择结束 ==========
当前数组：11 12 22 25 34 64 90

排序后数组：
当前数组：11 12 22 25 34 64 90
*/
