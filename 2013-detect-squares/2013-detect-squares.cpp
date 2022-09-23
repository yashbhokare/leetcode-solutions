class DetectSquares
{
public:
    unordered_map<int, unordered_map<int, int>> points; // (x, (y, count))

    void add(vector<int> p)
    {
        points[p[0]][p[1]]++;
    }
    
    int count(vector<int> p)
    {
        int x1 = p[0];
        int y1 = p[1];
        int res = 0;
        
        for (auto x: points)
        {
            for (auto y : x.second)
            {
                int x3 = x.first;
                int y3 = y.first;
                
                // Skip points that are on same x-axis or y-axis
                if (abs(x3-x1) == 0 || abs(x3-x1) != abs(y3-y1))
                    continue;
                
                res += points[x3][y3] * points[x1][y3] * points[x3][y1];
            }
        }
        return res;
    }
};