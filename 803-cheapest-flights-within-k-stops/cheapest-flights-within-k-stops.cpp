class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //  directed Node = second in pair;
    //  priceToNode = first in pair;
    vector<pair<int, int>> adj[n];

    for(int i = 0; i< flights.size(); i++) {
        adj[flights[i][0]].push_back({ flights[i][2], flights[i][1] });
    }

    vector<int> distPrice(n, 1e9);
    distPrice[src] = 0;

    queue<pair<pair<int, int>, int>> st;

    st.push({{0, src}, 0});

    while(!st.empty()) {
       int curPrice = (st.front()).first.first;
       int curNode = (st.front()).first.second;
       int curNodeStop = (st.front()).second;

       st.pop();
       
       if(curNodeStop > k) {
           continue;
       }
       
       for(auto it : adj[curNode]) {
           int nextNode = it.second;
           int priceToNode = it.first;
       
           if(curPrice + priceToNode < distPrice[nextNode] && curNodeStop <= k ) {
              distPrice[nextNode] = curPrice + priceToNode;
              st.push({{distPrice[nextNode], nextNode}, curNodeStop + 1});
           }
       }
    }

    if (distPrice[dst] == 1e9)
       return -1;

    return distPrice[dst];
  }
};