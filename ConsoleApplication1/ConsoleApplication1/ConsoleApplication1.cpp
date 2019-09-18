// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> solution1(vector<vector<int> > v);
vector<int> solution2(vector<int> arr);
vector<vector<int>> solution3(vector<vector<int>> arr);

int main()
{
    std::cout << "Hello World!\n" << endl;

	// [[1, 4], [3, 4], [3, 10]]
	vector<vector<int>> xy({
		vector<int>({1, 2, 3}),
		vector<int>({4, 5, 6}),
		vector<int>({7, 8, 9})
	});
	vector<int> arr1({ 1, 1, 3, 3, 0, 1, 1 });

	vector<vector<int>> arr2({
		vector<int>({1, 1, 3, 3, 0, 1, 1 }),
		vector<int>({1, 3, 0, 1}),
		vector<int>({4, 4, 4, 3, 3}),
		vector<int>({4, 3 })
		});

	// [1, 1, 3, 3, 0, 1, 1]
	// [1, 3, 0, 1]
	// [4, 4, 4, 3, 3]
	// [4, 3]

	vector<vector<int>> vvResult;
	vector<int> vResult;

	vvResult = solution1(xy);
	for (int y = 0; y < vvResult.size(); ++y)
	{
		for (int x = 0; x < vvResult.at(y).size(); ++x)
		{
			cout << vvResult[y][x] << " ";
		}
		cout << endl;
	}
	vvResult.clear();

	cout << endl;

	vResult = solution2(arr1);
	for (int value : vResult)
	{
		cout << value << "";
	};

	cout << endl;
	cout << endl;

	vvResult = solution3(arr2);
	for (int y = 0; y < vvResult.size(); ++y)
	{
		for (int x = 0; x < vvResult.at(y).size(); ++x)
		{
			cout << vvResult[y][x] << " ";
		}
		cout << endl; 
	}
	vvResult.clear();

	return 0;
}

vector<vector<int>> solution1(vector<vector<int> > v) {
	vector<vector<int>> ans(v.size(), vector<int>(v.at(0).size(), 0));
	ans.reserve(v.size() * v.at(0).size());

	// 자신이 속한 행열의 합을 더하는 코드 
	for (int y = 0; y < v.size(); ++y)
	{	
		int nSum = 0;
		// 자신이 속한 행의 합을 구한다.
		for (int x = 0; x < v[y].size(); ++x)
		{
			nSum += v[y][x];
		}

		// 자신이 속한 행에 합을 쓴다.
		for (int x = 0; x < v[y].size(); ++x)
		{
			ans[y][x] += nSum;
		}
	
		nSum = 0;
		// 자신이 속한 열의 합을 구한다.
		for (int x = 0; x < v[y].size(); ++x)
		{
			nSum += v[x][y];
		}

		// 자신이 속한 열에 합을 쓴다.
		for (int x = 0; x < v[y].size(); ++x)
		{
			ans[x][y] += nSum;
		}
	}

	// 원래의 행열에서 자기 자신의 값을 행열 합에서 뺀다
	for (int y = 0; y < v.size(); ++y)
	{
		for (int x = 0; x < v.at(y).size(); ++x)
		{
			ans[y][x] -= v[y][x];
		}
	}

	return ans;
}

// 배열 arr가 주어집니다.배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다.
// 이때, 배열 arr에서 연속적으로 나타나는 숫자는 하나만 남기고 전부 제거하려고 합니다.
// 단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다.
// 예를 들면,
// arr = [1, 1, 3, 3, 0, 1, 1] 이면[1, 3, 0, 1] 을 return 합니다.
// arr = [4, 4, 4, 3, 3] 이면[4, 3] 을 return 합니다.
// 배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.
// 제한사항
// 배열 arr의 크기 : 1, 000, 000 이하의 자연수
// 배열 arr의 원소의 크기 : 0보다 크거나 같고 9보다 작거나 같은 정수
// 
// 입출력 예
// arr
// answer
// [1, 1, 3, 3, 0, 1, 1]
// [1, 3, 0, 1]
// [4, 4, 4, 3, 3]
// [4, 3]
// 입출력 예 설명
// 입출력 예 #1, 2
// 문제의 예시와 같습니다.
vector<int> solution2(vector<int> arr)
{
	vector<int> answer;
	int nNum = 999;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (nNum != arr[i])
		{
			nNum = arr[i];
			bool bIsNum = false;
			//if(answer.empty())
			//	answer.push_back(nNum);

			for (int n : answer)
				if (n == nNum)
					bIsNum |= true;

			if(!bIsNum)
				answer.push_back(nNum);
		}
	}

	return answer;
}


vector<vector<int>> solution3(vector<vector<int>> arr)
{
	vector<vector<int>> answer(arr.size());
	for (int y = 0; y < arr.size(); ++y)
	{
		for (int x = 0; x < arr[y].size(); ++x)
		{
			int nNum = 999;
			if (nNum != arr[y][x])
			{
				nNum = arr[y][x];
				bool bIsNum = false;

				for (int n : answer[y])
					if (n == nNum)
						bIsNum |= true;

				if (!bIsNum)
					answer[y].push_back(nNum);
			}
		}
	}

	return answer;
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
