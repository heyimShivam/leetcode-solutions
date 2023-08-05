class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        dist[0][0]=0;
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            
            if(row==n-1 && col==m-1)return dis;

            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int neff=max(abs(heights[row][col]-heights[nr][nc]),dis);
                    if(neff<dist[nr][nc]){
                        dist[nr][nc]=neff;
                        pq.push({neff,{nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};