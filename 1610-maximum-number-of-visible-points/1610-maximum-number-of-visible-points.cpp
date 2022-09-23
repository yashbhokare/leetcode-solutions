class Solution {
public:
    
    // My location
    int x0,y0;
    const double pi = M_PI;
    double angle_from_me_to_point(int x1,int y1){
        int height = y1 -y0;
        int width = x1 - x0;
        // For tan inverse using atan2() -> https://www.geeksforgeeks.org/atan2-function-in-c-stl
        double angle = atan2(height,width)*(180/pi);
        if(angle<0) angle+=360;
        return angle;
    }
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        
        x0 = location[0];
        y0 = location[1];
        
        vector<vector<int>> points_not_on_me;
        vector<double> angles;
        int points_on_me = 0;
        
        // Seperate out the points that are not on me
        for(auto point:points){
            if(point==location) points_on_me++;
            else points_not_on_me.push_back(point);
        }
        
        points = points_not_on_me;
        
        // Calculate angles from my position to given points
        for(auto point:points){
            angles.push_back(angle_from_me_to_point(point[0],point[1]));
            angles.push_back(angles.back()+360);
        }
        sort(angles.begin(),angles.end());
        int max_visible_points = 0;
        int left=0, right=0;
        int size = angles.size();
        while(right<size){
            while(right<size && angles[right]-angles[left]<=angle) {
                right++;
            }
            
            max_visible_points = max(max_visible_points,right-left);
            while(right<size && left<right && (angles[right]-angles[left]>angle)) {
                left++;
            }      
        }
        return max_visible_points+points_on_me;
    
    }
};

