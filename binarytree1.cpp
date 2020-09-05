
#include <iostream>

using namespace std;

struct node {

	int cls;
	node* lson;
	node* rson;
	node* fa;
};

node* NEW_NODE() {
	node* nnode = new node();
	nnode -> lson = NULL;
	nnode -> rson = NULL;
	nnode -> fa = NULL;
	nnode -> cls = -1;
	return nnode;
}

int make(int* people, node* root, int nowpeople,int pairs) {
	// cout << nowpeople << '\n';
	int left[pairs];
	int right[pairs];
	int dis = 0; // right - left
	int a,b;
	if (nowpeople <= 1) {
		for (int i = 0; i < pairs; ++i) {
			if (people[i] == 1) {
				root -> cls = i;
				return i;
			}
		}
	}
	if (nowpeople == 0) {
		return 0;
	}
	// cout << 'L';
	for (int i = 0; i < pairs; ++i) {
		a = people[i] >> 1;
		b = people[i] - a;
		if (dis == 1) {
			left[i] = b;
			right[i] = a;
			dis -= b - a;
		} else {
			left[i] = a;
			right[i] = b;
			dis += b - a;
		}
		
	}
	node* l = NEW_NODE();
	node* r = NEW_NODE();
	l -> fa = root;
	r -> fa = root;
	root -> lson = l;
	root -> rson = r;
	// cout << 'E';
	make(left ,l,nowpeople >> 1,pairs);
	make(right,r,nowpeople - (nowpeople >> 1),pairs);

	return 0;
}

int dfs(node* root) {

	if (root -> lson == NULL && root -> rson == NULL) {
		cout << root -> cls << ' ';
		return 0;
	}
	dfs(root -> lson);
	dfs(root -> rson);
	return 0;
}


int main () {

	int pairs;
	cin >> pairs;

	int people[pairs];
	int nowpeople = 0;

	for (int i = 0; i < pairs; ++i) {
		cin >> people[i];
		nowpeople += people[i];
	}
	// cout << 'H' << '\n';
	node* root = NEW_NODE();
	// cout << 'H' << '\n';
	make(people,root,nowpeople,pairs);
	// cout << 'D';
	dfs(root);

	cout << '\n';
	return 0;
}
