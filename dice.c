#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int roll_dice(int dice_amount, int dice_size, int dice_modifier) {
    int roll_result = 0;
    for(int i = 0; i < dice_amount; i++) {
        roll_result += (rand() % dice_size) + 1;
    }
    return roll_result + dice_modifier;
}

int main(int argc, char *argv[]) {
    srand(time(0));

    for(int i = 1; i < argc; i++) {
        printf("dice roll #%d: %s\n", i, argv[i]);
        char *number_of_dice = strtok(argv[i], "d");
        char *faces_of_dice = strtok(NULL, "");
        char *modifier_of_dice = strpbrk(faces_of_dice, "-+");
        if(modifier_of_dice == NULL) {
            modifier_of_dice = "0";
        }
        printf("result: %d\n", roll_dice(atoi(number_of_dice), atoi(faces_of_dice), atoi(modifier_of_dice)));
    }

    return 0;
}

