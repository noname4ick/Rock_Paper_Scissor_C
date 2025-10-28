#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void toLowerCase(char *str) {
  int str_length = strlen(str);
  for (int i = 0; i < str_length; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32; // by shifting each characters ASCII value by 32 we
                            // can convert it to lowercase
    }
  }
}

static void decide_the_winner(int user_choice_id, int computer_choice_id) {
  if (user_choice_id == computer_choice_id) {
    printf("It's a tie!\n");
  } else if ((user_choice_id == 0 /*rock*/ &&
              computer_choice_id == 1 /*scissor*/) ||
             (user_choice_id == 1 /*scissor*/ &&
              computer_choice_id == 2 /*paper*/) ||
             (user_choice_id == 2 /*paper*/ &&
              computer_choice_id == 0 /*rock*/)) {
    printf("You win!\n");
  } else {
    printf("Computer wins!\n");
  }
}

static int make_decision(char *user_choice) {
  toLowerCase(user_choice);
  if (strcmp(user_choice, "exit") == 0) {
    return 0;
  }
  if (strcmp(user_choice, "rock") != 0 && strcmp(user_choice, "scissor") != 0 &&
      strcmp(user_choice, "paper") != 0) {
    printf("Invalid input! Please choose either Rock, Paper or Scissor\n");
    return 0;
  } else {
    int user_choice_id;
    switch (user_choice[0]) {
    case 'r':
      user_choice_id = 0;
      break;
    case 's':
      user_choice_id = 1;
      break;
    case 'p':
      user_choice_id = 2;
      break;
    }
    srand(time(0));
    int decision_index =
        rand() %
        3; // Creating random number between 0-2 to decide computer's choice
    // Assume 0 is rock, 1 is paper and 2 is scissor
    const char *decison[3] = {"Rock", "Scissor", "Paper"};
    printf("Computer chose: %s\n", decison[decision_index]);
    decide_the_winner(user_choice_id, decision_index);
    return 1;
  }
}

int main(void) {

  char user_choice[10];
  printf("Enter your choice (Rock, Paper, Scissor):");
  do {
    scanf("%9s", user_choice);
    make_decision(user_choice);
    printf("Enter your choice (Rock, Paper, Scissor) or type 'exit' to quit: ");
  } while (strcmp("exit", user_choice) != 0);
  return 0;
}