/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
            return a.start < b.start;
        });
        vector<int>rooms;
        for (auto & interval: intervals){
            bool booked = false;
            for (auto & room: rooms){
                if (room <= interval.start){
                    room = interval.end;
                    booked=true;
                    break;
                }
            }
            if (booked) continue;
            rooms.push_back(interval.end);
        }
        return rooms.size();
    }
};
