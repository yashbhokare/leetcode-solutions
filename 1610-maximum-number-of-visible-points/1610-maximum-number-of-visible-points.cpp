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


// class Solution {
// public:
//     // Coordinates of your location.
//     int x1, y1;
    
//     // Returns the angle between you and point in degrees.
//     double angle_from_me(vector<int>& point) {
//         int x2 = point[0];
//         int y2 = point[1];
//         int height = y2 - y1;
//         int width = x2 - x1;
//         double alpha = atan2(height, width) * (180 / pi);
//         return (alpha >= 0) ? alpha : alpha + 360;
//     }
    
//     int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
//         x1 = location[0];
//         y1 = location[1];
        
//         // 1. Count and remove any points that are at your location.
//         int points_on_me = 0;
//         vector<vector<int>> points_not_on_me;
//         for (vector<int>& point : points) {
//             if (point == location) {
//                 points_on_me++;
//             } else {
//                 points_not_on_me.push_back(point);
//             }
//         }
//         points = points_not_on_me;
        
//         // 2. Calculate the angle between you and each point.
//         //    i.  Sort the angles from smallest to largest.
//         //    ii. Extend angles [0, 40, 355] -> [0, 40, 355, 360, 400, 715]
//         //        This allows us to see that 355 is close to 0.
//         vector<double> angles;
//         for (vector<int>& point : points) {
//             angles.push_back(angle_from_me(point));
//             angles.push_back(angles.back() + 360);
//         }
//         sort(angles.begin(), angles.end());
//          for(auto a:angles){
//                     cout<<a<<" ";
//                 }
//         // 3. Use a sliding window to count the most points that can be observed.
//         //    The sliding window [i,j] changes size so that all angles[i:j] are visible.
//         int most_points_observable = 0, i = 0, j = 0;
//         int size = angles.size();
//         while (j < size) {
//             // Increase window size (increasing j while i is constant)
//             while ((j < size) && (angles[j] - angles[i] <= angle)) j++;
            
//             most_points_observable = max(j - i, most_points_observable);

//             // Decrease window size (increasing i while j is constant)
//             while ((j < size) &&  (i < j) && (angles[j] - angles[i] > angle)) i++;
//         }
        
//         return points_on_me + most_points_observable;
//     }
// };