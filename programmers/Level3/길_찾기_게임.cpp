// https://programmers.co.kr/learn/courses/30/lessons/42892
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int x, y, num;
    node* left = NULL;
    node* right = NULL;
};
node *root;

// root에 추가
void addNode(node *parent, node *child){
    if(parent->x > child->x){ // 왼 ?
        if(parent->left == NULL)
            parent->left = child;
        else
            addNode( parent->left, child);
    }
    else { // 오른
        if(parent->right == NULL)
            parent->right = child;
        else
            addNode( parent->right, child);
    }
}
// 전위 순회 (preorder... )
void front(vector<vector<int>> &answer, node *now){
    // 나 - 왼쪽 - 오른쪽
    answer[0].push_back(now->num);
    if(now->left != NULL) front(answer, now->left);
    if(now->right != NULL) front(answer, now->right);
}
// 후위 순회 (postorder ...)
void back(vector<vector<int>> &answer, node *now){
    // 왼쪽 - 오른쪽 - 나
    if(now->left != NULL) back(answer, now->left);
    if(now->right != NULL) back(answer, now->right);
    answer[1].push_back(now->num);
}

bool cmp(node a, node b){
    if(a.y > b.y)
        return true;
    return false;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    vector<node> v(nodeinfo.size());
    // node로 바꾸기 (vector로는 정렬 못함)
    for(int i=0; i<nodeinfo.size(); i++){
        node tmp;
        tmp.x = nodeinfo[i][0];
        tmp.y = nodeinfo[i][1];
        tmp.num = i+1;
        v[i] = tmp;
    }
    
    // y로 정렬
    sort(v.begin(), v.end(), cmp);
    
    // root에 전부 추가
    root = &v[0];
    for(int i=1; i<v.size(); i++){
        addNode( root, &v[i]);
    }
    
    // 순회
    front(answer, root);
    back(answer, root);
    return answer;
}

/**
 * 회고 : 
 * 처음에 막연히 이분탐색을 떠올렸었다. x 좌표 범위 때문에
 * 하지만 트리를 만들기 막막해서 다른 풀이로 풀어야 한다고 생각.
 * 
 * 접근법 : 
 * 결국은 이진트리를 직접 만드는 문제였다. 
 * 노드부터 addNode, 순회까지 직접 만들었는데 구현을 공부하기 좋은 문제였다. 
 * 
 * 주의 : 
 *  addNode에서 매개변수를 포인터로 부모, 자식 받는게 구현이 편하다.
 * node &parent 이런 식으로 받다가 addNode( *parent.left , ...) 사용이 실수의 여지가 있음
 * 
 */