﻿#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Problem Number: 11660

Problem Description :
N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.
예를 들어, N = 4이고, 표가 아래와 같이 채워져 있는 경우를 살펴보자.

1	2	3	4
2	3	4	5
3	4	5	6
4	5	6	7

여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이고, (4, 4)부터 (4, 4)까지 합을 구하면 7이다.
표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.

Link: https://www.acmicpc.net/problem/11660

Input:
첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 
둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다. 
다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, (x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다. 
표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)

Output:
총 M줄에 걸쳐 (x1, y1)부터 (x2, y2)까지 합을 구해 출력한다.

Limit: none
*/


#define MAXSIZE 1025
int arr[MAXSIZE][MAXSIZE];
int n, m;

// 누적합
void PrefixSum()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 전행값 + 전열값 - 중복값 + 자기값
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + arr[i][j];
       } 
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j= 1; j<= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    PrefixSum();

    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> y1>> x2 >> y2;
        
        /*
        4 3

        1 2 3 4             1   3   6   10
        2 3 4 5      ->   3   8  15  24
        3 4 5 6            6  15  27 42
        4 5 6 7            10 24 42 64

        2 2 3 4
        전체 영역 - 제거영역1 - 제거영역2 + 중복영역
         arr[3][4] - arr[1][4] - arr[3][1] + arr[1][1] = 27
         42 - 10 - 6 + 1
        */
        cout << arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}