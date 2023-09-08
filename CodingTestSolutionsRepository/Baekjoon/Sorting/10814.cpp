﻿#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
Problem Number: 10814

Problem Description :
온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로, 
나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

Link: https://www.acmicpc.net/problem/10814

Input:
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)

둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고,
이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 입력은 가입한 순서로 주어진다.

Output:
첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.

Limit: none
*/

const int MAX_SIZE = 100001;

typedef struct
{
	int age;
	string name;
	int num;
}Data;

Data profile[MAX_SIZE];

int compare(Data a, Data b)
{
	//길이가 짧은 것부터
	//길이가 같으면 사전 순으로
	if (a.age == b.age) return a.num < b.num;
	else return a.age < b.age;
}

int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> profile[i].age >> profile[i].name;
		profile[i].num = i;
	}

	// 정렬 알고리즘사용
	sort(profile, profile +N, compare);

	for (int i = 0; i < N; i++)
	{
		cout << profile[i].age<<" "<< profile[i].name << '\n';
	}

	return 0;
}