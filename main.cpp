#include <iostream>
#include <cctype>

typedef struct {
    std::string type;
    int score;
} Player;

char user_turn();

char computer_turn();

std::string results(char human_play, char computer_play);

void display_scores(Player human, Player computer);


int main() {
    Player human = {"human", 0};
    Player computer = {"computer", 0};

    std::cout << "Welcome to our SHI FU MI game \n";
    std::cout << "You are going to play a best of 3 against a computer, win 2 to be the champion\n";

    std::string winner = "nobody";

    do {
        display_scores(human, computer);
        std::string turn_winner = results(user_turn(), computer_turn());

        if (turn_winner == "human") {
            std::cout << "Human wins !!\n";
            human.score += 1;
        } else if (turn_winner == "computer") {
            std::cout << "Computer wins !!\n";
            computer.score += 1;
        } else {
            std::cout << "Draw !!\n";
        }

    } while (human.score < 2 && computer.score < 2);

    display_scores(human, computer);

    if (human.score > computer.score) {
        std::cout << "Human wins ! \n";
    } else {
        std::cout << "Computer wins ! \n";
    }
    return 0;
}

char user_turn() {
    char choice;

    do {
        std::cout << "Choose between ROCK(R), PAPER(P) and SCISSORS(S)\n";
        std::cout << "> ";
        std::cin >> choice;

        choice = std::toupper(choice);

        switch (choice) {
            case 'R':
                std::cout << "You chose Rock \n";
                break;
            case 'P':
                std::cout << "You chose Paper \n";
                break;
            case 'S':
                std::cout << "You chose Scissors \n";
                break;
            default:
                std::cout << "Please enter a valid option \n";
        }
    } while (choice != 'R' && choice != 'P' && choice != 'S');

    return choice;
}

char computer_turn() {
    srand(time(0));

    int random = rand() % 3 + 1;
    char choice;

    switch (random) {
        case 1:
            choice = 'R';
            std::cout << "Computer chose Rock\n";
            break;
        case 2:
            choice = 'P';
            std::cout << "Computer chose Paper\n";
            break;
        case 3:
            choice = 'S';
            std::cout << "Computer chose Scissors\n";
            break;
    }

    return choice;
}

std::string results(char human_play, char computer_play) {
    if (human_play == computer_play) {
        return "draw";
    } else if (human_play == 'R' && computer_play == 'P') {
        return "computer";
    } else if (human_play == 'R' && computer_play == 'S') {
        return "human";
    } else if (human_play == 'P' && computer_play == 'R') {
        return "human";
    } else if (human_play == 'P' && computer_play == 'S') {
        return "computer";
    } else if (human_play == 'S' && computer_play == 'R') {
        return "computer";
    } else if (human_play == 'S' && computer_play == 'P') {
        return "human";
    }
}

void display_scores(Player human, Player computer) {
    std::cout << "********SCORES********\n";
    std::cout << "Humans: " << human.score << std::endl;
    std::cout << "Computer: " << computer.score << std::endl;
    std::cout << "********SCORES********\n";
}
