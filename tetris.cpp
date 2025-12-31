#include <iostream>
#include <vector>
#include <limits>
#include <thread>
#include <chrono>

using namespace std;

void menu();
void help();
void game();
void clear_screen();
void loading_animation ();
void render(int width, int hight, vector<vector<int>> gird);

#define RESET   "\033[0m"           //colors
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main () {
    const int width = 10;
    const int higth = 20;

    vector<vector<int>> grid = {{0}};

    grid[5][5] = 1;
    grid[5][6] = 1;
    grid[6][5] = 1;
    grid[6][6] = 1;

    render(width,higth, grid);
}

void help() {
    loading_animation(); 
    clear_screen();
    cout << "help";
    int  x;
    cin >> x;
    menu();
}

void game() {
    loading_animation(); 
    clear_screen();
    
    cout << "game";
    int  x;
    //render();
}

void menu () {
    clear_screen();
    cout << GREEN << " _____ _____ _____ ____  ___ ____  " << "\n";
    cout << "|_   _| ____|_   _|  _ ||_ _/ ___| " << "\n";
    cout << "  | | |  _|   | | | |_) || ||___ | "<< "\n";
    cout << "  | | | |___  | | |  _ < | | ___) |" << "\n";
    cout << "  |_| |_____| |_| |_| |_|___|____/ "<< RESET <<"\n";

    cout <<  "\n"<< "\n";
    cout << RED <<"1) PLAY THE GAME" << "\n";
    cout << "2) HELP" << "\n";
    cout << "3) EXIT" << RESET << "\n" << "\n";

    int input;
    while (true)
    {
        cout << CYAN << "Please enter the number: " << RESET;
        cin >> input;
        if (cin.fail() || input > 3 || input < 0) {
            clear_screen();
            cout << RED <<"INVALID INPUT \n" << RED;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else {
            break;
        }
    }
    if (input == 1) {
        game();
    }else if (input ==  2){
        help();
    }
}  


void clear_screen() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear"); // Unix/Linux/macOS
    #endif
}

void loading_animation () {
    const int barWidth = 50;

    for (int i = 0; i <= 100; i++) {
        int pos = barWidth * i / 100;

        cout << "\r[";
        for (int j = 0; j < barWidth; j++) {
            if (j < pos)
                cout << GREEN << "█" << RESET;
            else
                cout << "░";
        }
        cout << "] " << i << "%" << flush;

        this_thread::sleep_for(chrono::milliseconds(10));
    }

}


void render(int width, int hight, vector<vector<int>> grid) {
    for (int i = 1; i <= width+2; i++) {
        cout << WHITE <<"_";
    }cout << "\n";
    
    for (int i = 0; i < hight; i++){
        cout << "|";
        for (int j = 0; j < width; j++){
            if (grid[i][j] == 0) {
                cout << ".";
            }else if (grid[i][j]== 1){
                cout << "#";
            }
            
        }   
        cout << "|\n";
    }
    for (int i = 1; i <= width+2; i++) {
        cout << WHITE <<"-";
    }cout << "\n";
    
   

}





