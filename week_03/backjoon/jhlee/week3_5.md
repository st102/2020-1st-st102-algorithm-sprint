# 백준 괄호 <9012>

## 문제 설명
괄호를 입력 받아 옳지 않은 괄호 입력이라면 NO 옳다면 YES를 출력하라.


## 나의 풀이법
```c++

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		stack<char> s;
		bool check = false;

		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') s.push('(');
			else {
				if (s.size() == 0) {
					cout << "NO" << '\n';
					check = true;
					break;
				}
				s.pop();
			}
		}
		if (!check) {
			if(s.size() == 0) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
	return 0;
}
** stack을 사용하였다. '('가 들어온다면 스택에 넣어주고 ')'가 들어온다면 스택에서 빼주어 최종적으로 스택의 수가 0이거나 스택에 아무것도 없는데 스택을 빼주려 할 때 'NO'를 출력해 주었다.




## 다른 사람 풀이
``` c++

#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool vps(string ps) {
    stack<char> s;
    bool sw = true;
    for (int i = 0; i < ps.size(); ++i) {
        if (ps[i] == '(')
            s.push(ps[i]);
        else if (!s.empty() && ps[i] == ')')
            s.pop();
        else if (s.empty() && ps[i] == ')') {
            sw = false;
            break;
        }
            
    }
    if (s.empty() && sw) return true;
    else return false;
}
int main() {
    int num;
    string ps;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> ps;
        if (vps(ps)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
** 이 사람도 역시 스택을 사용하였다. 이 사람은 판별하는 함수를 분리하여 만들어서 구현하였다.









