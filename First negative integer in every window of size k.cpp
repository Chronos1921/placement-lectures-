vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
        /*
        
        Approach:-
        initialize a deque and a array ans
        now in the dequeue we will insert the index of the element that are negetive 
        first we will do for the Ksize window and then ofor the rest of the elements 
        
        
        */
        deque <long long int> dq;                                     
        vector<long long> ans;  
        for(int i=0;i<K;i++){
            if(A[i]<0){//if negetive element is present then push their index
                dq.push_back(i);
            }
        }
        
        //we need to find the first element that is negetive so just check the front
        if(dq.size()>0){
            ans.push_back(A[dq.front()]);
        }
        else{
            ans.push_back(0);// if no element is present then push zero
        }
        
        
        for(int i=K;i<N;i++){//for the rest of the elements 
            if((i-dq.front()>=K) && !dq.empty()){// this id for the elements that are outside the window
                dq.pop_front();
            }
            if(A[i]<0){
                dq.push_back(i);
            }
            if(dq.size()>0){
            ans.push_back(A[dq.front()]);//for each new elemnt check the deque 
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
                                                 
}
