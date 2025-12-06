#include <iostream>
#include <vector>

using namespace std;

void wordLadder(string s, string t, int &steps, vector<string> &p);

int main()
{
    int steps=0;
    vector<string> path;

    wordLadder("liter", "meter", steps, path);

    //ASSERT_EQ(steps,2);
    if (steps != 2)
    {
        std::cout << "liter->meter: expected/correct value for steps is 2, actual value when testing " << steps << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}