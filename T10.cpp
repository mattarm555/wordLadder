#include <iostream>
#include <vector>

using namespace std;

void wordLadder(string s, string t, int &steps, vector<string> &p);

int main()
{
    int steps=0;
    vector<string> path;

    wordLadder("icier", "frost", steps, path);

    //ASSERT_EQ(steps,14);
    if (steps != 14)
    {
        std::cout << "icier->frost: expected/correct value for steps is 14, actual value when testing " << steps << ".\n";
        return 1;
    }

    std::cout << "Passed" << endl;
}