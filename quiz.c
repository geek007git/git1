 #include <stdio.h>
#include <stdlib.h>

void displayQuestion(const char *question, const char *options[], char correctAnswer);
char getAnswer();
void clearScreen();

int main() {
    int score = 0;  // Keeps track of the user's score
    const int totalQuestions = 3;
    const char *questions[] = {
        "What is the capital of France?",
        "Which programming language is this quiz written in?",
        "What is 2 + 2?"
    };
    const char *options[][4] = {
        {"A. Berlin", "B. Madrid", "C. Paris", "D. Rome"},
        {"A. Python", "B. Java", "C. C", "D. JavaScript"},
        {"A. 3", "B. 4", "C. 5", "D. 6"}
    };
    const char correctAnswers[] = {'C', 'C', 'B'};
    for (int i = 0; i < totalQuestions; i++) {
        clearScreen();
        printf("Question %d/%d:\n", i + 1, totalQuestions);
        displayQuestion(questions[i], options[i], correctAnswers[i]);
        char userAnswer = getAnswer();
        if (userAnswer == correctAnswers[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer was %c.\n", correctAnswers[i]);
        }
        printf("\nPress Enter to continue...\n");
        getchar();  // Wait for the user to press Enter
    }
    clearScreen();
    printf("Quiz Completed!\n");
    printf("Your Score: %d/%d\n", score, totalQuestions);
    return 0;
}
void displayQuestion(const char *question, const char *options[], char correctAnswer) {
    printf("%s\n", question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", options[i]);
    }
    printf("Enter your answer (A, B, C, or D): ");
}
char getAnswer() {
    char answer;
    scanf(" %c", &answer);
    answer = toupper(answer); 
    getchar(); 
    return answer;
}
void clearScreen() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear");  // For Unix-based systems
    #endif
}
