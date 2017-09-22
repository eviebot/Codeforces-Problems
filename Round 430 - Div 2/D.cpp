#include <bits/stdc++.h>

#define fastIO ios::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define inf INT_MAX
#define minf INT_MIN

typedef long long int lli;

using namespace std;

ofstream outfile;
ifstream infile;

lli arr[30];
lli power(int x){
	return arr[x];
}

#define maxtriesize 27
struct mytrie{
	int n_leaves;
	struct mytrie *left; //left = 0
	struct mytrie *right;//right = 1
};

struct mytrie *head;

void insert(string s){
	struct mytrie *temp, *node = head;
	for(int i = 0; i < maxtriesize; ++i){
		if(s[i] == '0'){
			if(node->left == NULL){
				temp = (struct mytrie *)malloc(sizeof(struct mytrie));
				temp->left = NULL;
				temp->right = NULL;
				node->left = temp;
			}
			node = node->left;
		}else{
			if(node->right == NULL){
				temp = (struct mytrie *)malloc(sizeof(struct mytrie));
				temp->left = NULL;
				temp->right = NULL;
				node->right = temp;
			}
			node = node->right;
		}
	}
	return ;
}

lli query(string s){
	struct mytrie *node = head, *temp;
	int i;
	lli ans = 0;
	for(i = 0; i < maxtriesize; ++i){
		ans *= 2;
		if(node == NULL)
			continue;
		if(s[i] == '0'){
			temp = node->left;
			/*if(temp != NULL && i > 20){
			    cout << s[i] << " "<< temp->n_leaves << " "<< power(maxtriesize-i)<< " "<< i << ' '<< temp->left << " "<< temp->right << "\n";
			}*/
			if(temp != NULL && (temp->n_leaves == power(maxtriesize-i))) {
				temp = node->right;
				ans++;
			}
		}
		else{
			temp = node->right;
			/*if(temp != NULL && i > 20){
			    cout << s[i] << " "<< temp->n_leaves << " "<< power(maxtriesize-i)<< " " << i << ' '<< temp->left << " "<< temp->right << "\n";
			}*/
			if(temp != NULL && temp->n_leaves == power(maxtriesize-i) ){
				temp = node->left;
				ans++;
			}
		}
		node = temp;
	}
	return ans;
}
void create_trie(){
	head = (struct mytrie *)malloc(sizeof(struct mytrie));
	head->left = NULL;
	head->right = NULL;
	head->n_leaves = 0;
	arr[0] = 0;
	for(int i = 1; i < 30; ++i){
		arr[i] = arr[i-1]*2 + 1;
	}
}

void insert(lli x){
	string s = "", fin = "";int n = 0;
	while(x){
		n++;
		s += (x%2+'0');
		x /= 2;
	}
	reverse(s.begin(), s.end());
	for(int i = n+1; i <= maxtriesize; ++i)
		fin += "0";

	fin += s;
	insert(fin);
}
lli query(lli x){
	string s = "", fin = "";int n = 0;
	while(x){
		n++;
		s += (x%2+'0');
		x /= 2;
	}
	reverse(s.begin(), s.end());
	for(int i = n+1; i <= maxtriesize; ++i)
		fin += "0";

	fin += s;
	return query(fin);
}
int change(struct mytrie *node){
	if(node == NULL)
		return 0;
	node->n_leaves = change(node->left) + change(node->right) + 1;
	return node->n_leaves;
}
int main()
{
	infile.open("input.txt");
	outfile.open("output.txt");

	fastIO;
	create_trie();
	int n, m, t, i, x = 0;
	cin >> n >> m;
	for(i= 1; i <= n; ++i){
		cin >> t;
		insert(t);
	}
	change(head);

	for(i = 1; i <= m; ++i){
		cin >> t;
		x = x^t;
		cout << query(x) << "\n";
	}
}