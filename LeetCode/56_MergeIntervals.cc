#include <iostream>
using namespace std;

vector<Interval> merge(vector<Interval>& intervals) {
    
    // Sort the array by the smaller values
    sort( intervals.begin( ), intervals.end( ), [ ]( const Interval& lhs, const Interval& rhs )
    {
        return lhs.start < rhs.start;
    });
    
    // Iterate through each of the intervals. At each interval, take note
    // of the larger of the two values. With this in mind, look at the next
    // interval. If either of its values are <= the previous max,
    // these two intervals can be merged. Set the new max accordingly.
    // Repeat the same process until neither of the current interval's
    // values are less than the current max. We may now insert into the
    // output an interval with our newfound max and min.
    vector<Interval> output;
    int low = INT_MIN;
    int high = INT_MAX;
    for(int i = 0; i < intervals.size(); i++){
        
        // We've found the end of our interval
        if(intervals[i].start > high){
            Interval interval1(low, high);
            output.push_back(interval1);
            low = intervals[i].start;
            high = intervals[i].end;
        }
        
        // We need to expand our current interval
        else{
            high = (high == INT_MAX) ? intervals[i].end : max(intervals[i].end, high);
            if(low == INT_MIN) low = intervals[i].start;
        }
    }
    if(intervals.size() != 0){
        Interval i(low, high);
        output.push_back(i);
    }
    
    return output;
    
}

int main(){
	
}