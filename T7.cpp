#include <iostream>
#include <vector>

using namespace std;

void wordLadder(string s, string t, int &steps, vector<string> &p);

int main()
{
    int steps=0;
    vector<string> path;

    wordLadder("moose", "goose", steps, path);

    //ASSERT_EQ(steps,1);
    if (steps != 1)
    {
        std::cout << "moose->goose: expected/correct value for steps is 1, actual value when testing " << steps << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}