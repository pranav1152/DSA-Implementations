/* Author : Pranav Deshmukh
            PICT,Pune
   Purpose: Tree Input & Printing(DFS,BFS Style),Count leaf nodes,Find total number of nodes,Find element,
   			Find height,Find sum of all nodes,Find maximum in all nodes,Find just larger than given element,
			Find number of elements than given,Print postorder,preorder,Find if two trees are identical and
			structurally identical;
   Stay Focused!
*/
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

template <typename T>
class TreeNode {
public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(int data) {
		this-> data = data;
	}

	~TreeNode() {
		for (int i = 0; i < children.size(); i++) {
			delete children[i];
		}
	}
};

int countLeaf(TreeNode<int>* root) {
	bool isLeaf = true;
	for (int i = 0; i < root->children.size(); i++) {
		isLeaf = false;
		break;
	}
	if (isLeaf) {
		return 1;
	}
	int leafNodes = 0;
	for (int i = 0; i < root->children.size(); i++) {
		leafNodes += countLeaf(root->children[i]);
	}
	return leafNodes;
}

int numNodes(TreeNode<int>* root) {
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++) {
		ans += numNodes(root->children[i]);
	}
	return ans;
}

bool findElement(TreeNode<int>* root, int data) {
	if (root->data == data) {
		return true;
	}
	for (int i = 0; i < root->children.size(); i++) {
		if (findElement(root->children[i], data))
			return true;
	}
	return false;
}

int findHeight(TreeNode<int>* root) {
	// Edge Case
	if (root == NULL) {
		return 0;
	}
	int maxheight = 0;
	for (int i = 0; i < root->children.size(); i++) {
		int childHeight =  findHeight(root->children[i]);
		maxheight = max(maxheight, childHeight);
	}
	return maxheight + 1;
}

int findSum(TreeNode<int>* root) {
	// Edge case
	if (root == NULL) {
		return 0;
	}

	int sum = root->data;
	for (int i = 0; i < root->children.size(); i++) {
		sum += findSum(root->children[i]);
	}
	return sum;
}

int maxDataFunction(TreeNode<int>* root) {
	int maxData = root->data;
	for (int i = 0; i < root->children.size(); i++) {
		int childData = maxDataFunction(root->children[i]);
		maxData = max(maxData, childData);
	}
	return maxData;
}

int findNextLarger(TreeNode<int>* root, int element) {
	if (root->data > element)
		return root->data;
	int localMax = INT_MAX;
	for (int i = 0; i < root->children.size(); i++) {
		int childMax = findNextLarger(root->children[i], element);
		if (childMax < localMax)
			localMax  = childMax;
	}
	return localMax;
}

int noOfGreater(TreeNode<int>* root, int x) {
	int ans = 0;
	if (root->data > x)
		ans++;
	for (int i = 0; i < root->children.size(); i++) {
		ans += noOfGreater(root->children[i], x);
	}
	return ans;
}

void postOrder(TreeNode<int>* root) {
	// Edge Case
	if (root == NULL) {
		return;
	}
	for (int i = 0; i < root->children.size(); i++) {
		postOrder(root->children[i]);
	}
	cout << root->data << " ";
}

void preOrder(TreeNode<int>* root) {
	// Edge Case
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";

	for (int i = 0; i < root->children.size(); i++) {
		postOrder(root->children[i]);
	}
}

bool isIdenticalTrees(TreeNode<int>* root1, TreeNode<int>* root2) {
	// Edge case if diffrent number of childrens.
	if (root1 == NULL || root2 == NULL) {
		return false;
	}
	if (root1->data != root2->data)
		return false;
	for (int i = 0; i < root1->children.size(); i++) {
		if (!isIdenticalTrees(root1->children[i], root2->children[i]))
			return false;
	}
	return true;
}

bool isStructurallyIdentical(TreeNode<int>* root1, TreeNode<int>* root2) {
	if (root1->children.size() != root2->children.size()) {
		return false;
	}
	for (int i = 0; i < root1->children.size(); i++) {
		if (!isStructurallyIdentical(root1->children[i], root2->children[i]))
			return false;
	}
	return true;
}

//LevelWise Input
TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter Root Data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter num of children of " << front->data << endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

// LevelWise Printing
void LevelWisePrinting(TreeNode<int>* root) {
	queue<TreeNode<int>*> q;

	q.push(root);
	while (q.size() != 0) {
		TreeNode<int>* front = q.front();
		q.pop();
		cout << front->data << " ";
		for (int i = 0; i < front->children.size(); i++) {
			q.push(front->children[i]);
		}
	}
}


TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout << "Enter number of children of " << rootData << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTree(TreeNode<int>* root) {
	//Edge Case
	if (root == NULL) {
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->children.size(); i++) {
		printTree(root->children[i]);
	}
}

int main() {
	cout << "Enter first tree:" << endl;
	TreeNode<int>* root1 = takeInputLevelWise();
	cout << "Given tree is:" << endl;
	LevelWisePrinting(root1);
	cout << findElement(root1, 6) << endl;
	cout << "Enter second tree:" << endl;
	TreeNode<int>* root2 = takeInputLevelWise();
	LevelWisePrinting(root2);
	cout << isStructurallyIdentical(root1, root2) << endl;
	delete root1;
	delete root2;
	return 0;
}
	/*
		Input for :						1
							2		3		4
								5		6

	is - 1 3 2 3 4 0 2 5 6 0 0 0
	*/
