#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *filename;
    int count_chars = 0, count_words = 0, is_word = 0;
    FILE *f;

    // 检查参数是否合法
    if (argc < 2 || argc > 3) {
        printf("Usage: WordCount [-c|-w] [filename]\n");
        return 1;
    }
    if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-w") != 0) {
        printf("Invalid parameter \"%s\"\n", argv[1]);
        return 1;
    }
    if (argc == 3) {
        filename = argv[2];
    } else {
        filename = "input.txt";
    }

    // 打开文件并统计字符数和单词数
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Failed to open file \"%s\"\n", filename);
        return 1;
    }
    while (1) {
        int ch = fgetc(f);
        if (ch == EOF) {
            break;
        }
        count_chars++;
        if (!isspace(ch)) {
            is_word = 1;
        } else if (is_word) {
            count_words++;
            is_word = 0;
        }
    }
    if (is_word) {
        count_words++;
    }
    fclose(f);

    // 输出结果
    if (strcmp(argv[1], "-c") == 0) {
        printf("Character count: %d\n", count_chars);
    } else {
        printf("Word count: %d\n", count_words);
    }

    return 0;
}
