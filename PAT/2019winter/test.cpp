#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<string> v[26], word;
	string s, temp;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 7; j++){
			getline(cin, s);
			v[i].push_back(s);
		}
	}
	getline(cin, s);
	for(int i = 0; i < s.length(); i++){
		if(s[i] <= 'Z' && s[i] >= 'A'){
			temp += s[i];
		}else{
			if(temp != ""){
				word.push_back(temp);
				temp = "";
			}
		}
	}
	if(temp != "") word.push_back(temp);
	for(int i = 0; i < word.size(); i++){
		for(int j = 0; j < 7; j++){
			for(int k = 0; k < word[i].size(); k++){
				int ind = word[i][k] - 'A';
				printf("%s%s", k == 0?"":" ", v[ind][j].c_str());
			}
			if( !(i == word.size() - 1 && j == 6) )printf("\n");
		}
		if(i != word.size() - 1) printf("\n");
	}
	return 0;
}
