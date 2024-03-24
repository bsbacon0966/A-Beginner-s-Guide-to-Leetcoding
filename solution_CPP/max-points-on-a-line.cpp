// If the slope from this point to other points is mostly same, it means that they are on the same line (because fixing a point, to other points can be the same slope, it must be the same line) 
// Using unordered_map is mainly because the slope has multiple solutions. It is impossible to list all possible slopes using vectors, so use the unordered_map directly to remember the slopes that appear 

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        int ans=0;
        
        double d;
        for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(points[i][0]==points[j][0]){
                    d=INT_MAX;// here slope is infinite 
                }
                else{
                    d=(double)(points[i][1]-points[j][1])/(points[i][0]-points[j][0]);//slope of the line
                }
                mp[d]++;
                ans=max(ans,mp[d]);
            }
        }
        return ans+1;
    }
};