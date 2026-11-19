#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int n;
    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩:");
    scanf("%d", &n);

    // 限制購買組數在 1~5 之間
    if (n < 1 || n > 5) {
        printf("輸入組數錯誤，請輸入 1 到 5 之間的數字。\n");
        return 1;
    }

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟檔案 lotto.txt\n");
        return 1;
    }

    // 取得目前系統時間並去除換行符號
    time_t curtime;
    time(&curtime);
    char *time_str = ctime(&curtime);
    time_str[strcspn(time_str, "\n")] = '\0';

    // 寫入標頭
    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str);

    srand((unsigned)time(NULL));

    // 產生 5 組號碼欄位
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "[%d]: ", i + 1);
        if (i < n) {
            int nums[7];
            int count = 0;
            while (count < 7) {
                int r = (rand() % 69) + 1; // 產生 1~69 亂數
                int duplicate = 0;
                for (int j = 0; j < count; j++) {
                    if (nums[j] == r) {
                        duplicate = 1;
                        break;
                    }
                }
                if (!duplicate) {
                    nums[count++] = r;
                }
            }
            // 寫入 7 個兩位數號碼
            for (int j = 0; j < 7; j++) {
                fprintf(fp, "%02d ", nums[j]);
            }
            fprintf(fp, "\n");
        } else {
            // 未購買的組別填入 --
            fprintf(fp, "-- -- -- -- -- -- --\n");
        }
    }

    // 寫入頁尾
    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的%d組樂透組合輸出至 lotto.txt\n", n);
    return 0;
}
