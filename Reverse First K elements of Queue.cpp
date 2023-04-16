queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    
    stack<int> s;//initialize a stack
    
    //Eg:- 1 2 3 4 5 6 given k=3;
    //ans would be 3 2 1 4 5 6
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    //after the step q will be 4 5 6 
    //stack will be 
    // |3 |
    // |2 |
    // |1 |
    
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }
    // q will be 4 5 6 3 2 1
    // which his far from 3 2 1 4 5 6 
    //so we need to pop the elements from the front and push them back
    
    int t=q.size()-k;
    while(t--){
        int val=q.front();
        q.pop();
        q.push(val);
    }
    
    // now the q will look like 3 2 1 4 5 6
    return q;
}
