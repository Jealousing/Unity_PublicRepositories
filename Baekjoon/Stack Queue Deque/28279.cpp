﻿/*
Problem Number: 28279

Problem Description :
정수를 저장하는 덱을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

1 X: 정수 X를 덱의 앞에 넣는다. (1 ≤ X ≤ 100,000)
2 X: 정수 X를 덱의 뒤에 넣는다. (1 ≤ X ≤ 100,000)
3: 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
4: 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
5: 덱에 들어있는 정수의 개수를 출력한다.
6: 덱이 비어있으면 1, 아니면 0을 출력한다.
7: 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
8: 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.

Link: https://www.acmicpc.net/problem/28279

Input:
첫째 줄에 명령의 수 N이 주어진다. (1 ≤ N ≤ 1,000,000)
둘째 줄부터 N개 줄에 명령이 하나씩 주어진다.
출력을 요구하는 명령은 하나 이상 주어진다.

Output:
출력을 요구하는 명령이 주어질 때마다 명령의 결과를 한 줄에 하나씩 출력한다.

Limit: none
*/


#include <iostream>
#include <algorithm>
using namespace std;

#define MAXSIZE 2000002
int deque[MAXSIZE];

int checkDeque(int value)
{
    if (value < 0)
    {
        return MAXSIZE-1;
    }
    else if (value > MAXSIZE - 1)
    {
        return 0;
    }
    return value;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int front = (MAXSIZE/2), end = (MAXSIZE / 2)+1;

    // 입력 
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp,x;
        cin >> temp;
        switch (temp)
        {
        case 1:
            cin >> x;
            deque[checkDeque(front--)] = x;
            break;
        case 2:
            cin >> x;
            deque[checkDeque(end++)] = x;
            break;
        case 3:
            if (front + 1 != end)
            {
                cout << deque[checkDeque(front+1)] << '\n';
                front++;
            }
            else
            {
                cout << "-1\n";
            }
            break;
        case 4:  
            if (front + 1 != end)
            {
                cout << deque[checkDeque(end-1)] << '\n';
                end--;
            }
            else
            {
                cout << "-1\n";
            }
            break;
        case 5:
            cout << abs(end - front) -1 << '\n';
            break;
        case 6:
            if (front + 1 != end)
            {
                cout << "0\n";
            }
            else
            {
                cout << "1\n";
            }
            break;
        case 7:
            if (front + 1 != end)
            {
                cout << deque[checkDeque(front+1)] << '\n';
            }
            else
            {
                cout << "-1\n";
            }
            break;
        case 8: 
            if (front + 1 != end)
            {
                cout << deque[checkDeque(end - 1)] << '\n';
            }
            else
            {
                cout << "-1\n";
            }
            break;
        default:
            break;
        }
    }
    return 0;
}