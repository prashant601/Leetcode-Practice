class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int total=0, surplus=0, ind=0;
        // for(int i=0; i<gas.size(); i++){
        //     total+= gas[i]-cost[i];
        //     surplus+= gas[i]- cost[i];
        //     if(surplus<0){
        //         surplus=0;
        //         ind=i+1;
        //     }
        // }
        // return total<0?-1:ind;
        
        
        int start(0),total(0),tank(0);
        //if car fails at 'start', record the next station
        for(int i=0;i<gas.size();i++){
            if((tank=tank+gas[i]-cost[i])<0) 
            {
                start=i+1;
                total+=tank;
                tank=0;
            }
        }
        return (total+tank<0)? -1:start;
    }
};