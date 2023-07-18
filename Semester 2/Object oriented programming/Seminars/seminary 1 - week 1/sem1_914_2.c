#include <stdio.h>

typedef struct {
    int arr[50], len;
} vector;


vector readVector() {
    int x;
    vector a;
    a.len = 0;

    do {

        printf("Element: ");
        scanf("%d", &x);
        a.arr[a.len++] = x;

    } while (x != 0);

    a.len -= 1;

    return a;

}


vector readVector2() {

    vector b;

    printf("Number of elements: ");
    scanf("%d", &b.len);

    for (int i = 0; i < b.len; i++) {
        scanf("%d", &b.arr[i]);
    }
    return b;
}


void longestSubsequence(vector arr, int* start, int* end) {
    int max_len_start_end = 0;
    int len_start_end = 0;

        *start = 0;
        *end = 0;

    for (int i = 0; i < arr.len - 1; i++) {
        int j = i + 1;
        while (j < arr.len && arr.arr[i] == arr.arr[j]) {
            j++;
        }
        len_start_end = j - i;
         if (len_start_end > max_len_start_end) {
               *start = i;
               *end = j - 1;
               max_len_start_end = len_start_end;
        }

    }
}


void printSubsequence(vector arr, int start, int end) {
    printf("The longest array is: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr.arr[i]);
    }
}



int sum(vector arr) {
    int i, sum=0;
    for (i = 0; i < arr.len; i++) {
        sum += arr.arr[i];
    }

    return sum;
}



int main()
{   
    int option;

    while (1) {
        printf("Option 1: Sum of number\n");
        printf("Option 2: Longest subsequence\n");
        printf("Option 3: Exit");

        printf("Select option: ");
        scanf("%d", &option);
        if (option == 0) {
            break;
        }
         switch (option) {
            case 1: {
                vector arr = readVector();
                int s = sum(arr);
                printf("%d\n", s);
                break;
            }
            case 2: {
                vector arr = readVector2();
                int start;
                int end;
                longestSubsequence(arr, &start, &end);
                printSubsequence(arr, start, end);
                break;
            }
         }
    }
    return 0;
}
