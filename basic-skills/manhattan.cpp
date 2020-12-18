#include <stack>
#include <vector>
#include <iostream>

int solution(std::vector<int> &H)
{
    int stones = 0;
    std::stack<int> heights;

    for (auto h : H) {
        while (!heights.empty() && h < heights.top())
        {
            heights.pop();
        }
        if (heights.empty() || h > heights.top())
        {
            heights.push(h);
            ++stones;
        }
    }
    return stones;
 
}

int main()
{
    std::vector<int> H = { 8, 8, 5, 7, 9, 8, 7, 4, 8 };
    std::cout << solution(H) << "\n";
}

/*
 * You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by an array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.

The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.

Write a function:

int solution(vector<int> &H);

that, given an array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.

For example, given array H containing N = 9 integers:

  H[0] = 8    H[1] = 8    H[2] = 5
  H[3] = 7    H[4] = 9    H[5] = 8
  H[6] = 7    H[7] = 4    H[8] = 8
the function should return 7. The figure shows one possible arrangement of seven blocks.
*
*/
