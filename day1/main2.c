#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addMaxCalorie(int *top_three_calories, int calorie_count) {
    for (int i = 0; i < 3; i++) {
        if (calorie_count > top_three_calories[i]) {
            for (int j = 1; j >= i; j--) {
                top_three_calories[j+1] = top_three_calories[j];
            }
            top_three_calories[i] = calorie_count;
            break;
        }
    }
}

int main() {
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    int calorie_count = 0;
    int top_three_calories[3] = {0};

    stream = fopen("input.txt", "r");
    if (stream == NULL) {
        printf("NO FILE!");
        return 1;
    }

    while ((nread = getline(&line, &len, stream)) != -1) {
        calorie_count += atoi(line); // if line == "\n" atoi returns 0
        
        if (strcmp(line, "\n") == 0) {
            addMaxCalorie(top_three_calories, calorie_count);
            calorie_count = 0;
        }
    }
    // last value isn't used because there's no new line after it only an EOF, so we need to execute it one more time
    addMaxCalorie(top_three_calories, calorie_count);

    free(line);
    fclose(stream);

    printf("%d\n", top_three_calories[0] + top_three_calories[1] + top_three_calories[2]);

    return 0;
}
