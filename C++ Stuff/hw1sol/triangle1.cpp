
#include <iostream>

bool get_input(int &ht, char &ch);


void draw_triangle(int ht, char ch);

int main()
{
    using namespace std;
    int height;
    char ch;

    char ans;
    do
    {
        if (get_input(height, ch))
            draw_triangle(height, ch);
        cout << "Again? y/n ";
        cin >> ans;
    } while(ans == 'y' || ans == 'Y');

    return 0;
}


bool get_input(int &ht, char &ch)
{
    using namespace std;
    cout << "Enter height: ";
    cin >> ht;
    if (ht <= 0)
        return false;
    cout << "Enter a character: ";
    cin >> ch;
    return true;
}

void draw_triangle(int ht, char ch)
{
    using namespace std;
    int num_spaces = ht - 1;
    int num_chars;
    for (int row = 1; row <= ht; ++row)
    {
        for (int j = 0; j < num_spaces; ++j)
            cout << ' ';
        num_spaces--;
        num_chars = 2*row - 1;
        for (int k = 0; k < num_chars; k++)
            cout << ch;
        cout << endl;
    }
}
