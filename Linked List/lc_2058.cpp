/* we are given LL , there will be some critical points but condition is that the  adjacent element should  greater or smaller than critical point */
/* we have to return the MIN_dist & MAX_dist b/w two distinct  critical points */

#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(){
        this->data = data;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head,Node* &tail,int data){

    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;

}

void print(Node* &head){

    if(!head) return;

    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

vector<int> findCp(Node* &head){

    vector<int>ans = {-1,-1};

    Node* prev = head;               // take 3 pointers so that we can compare the adjacent values to find CP
    if(!prev) return ans;

    Node* curr = head->next;
    if(!curr) return ans;

    Node* nxt = head->next->next;
    if(!nxt) return ans;

    int firstCP = -1;
    int lastCP = -1;
    int minDist = INT_MAX;
    int i = 1;

    while(curr->next){
                               // check for CP
        bool isCP = ((curr->data > prev->data && curr->data > nxt->data)  || (curr->data < prev->data && curr->data < nxt->data)) ? true : false;

        if(isCP && firstCP == -1){          // if CP but firstCP doesn't exist -> means its's first CP  -> then mark as first & last CP
            firstCP = i;
            lastCP = i;
        }
        else if(isCP){                               // if CP only then last minDist should be compared with curr diff b/w present index & lastCP
            minDist = min(minDist,i - lastCP);
            lastCP = i;                                // update the lastCP
        }

        i++;
        prev = prev->next;          // tarverse the poniter & index
        curr = curr->next;
        nxt = nxt->next;
    }

    if(firstCP == lastCP){            // if only one CP exists
        return ans;
    }
    else{
        ans[0] = minDist;                 // minimum distance
        ans[1] = lastCP - firstCP;        // maximum distance
    } 

    return ans;

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout<<"Enter no. of nodes : ";
    cin>>n;

    int data;
    cout<<"Enter The Node Value : ";
    for(int i=0;i<n;i++){
        cin>>data;
        insertAtTail(head,tail,data);
    }

    vector<int> cp = findCp(head);

    cout<<"The Critical Points : "<<cp[0]<<" "<<cp[1];

    return 0;

}