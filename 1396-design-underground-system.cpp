struct node1{
    string station;
    int start_time;
};
struct node2{
    int total_time=0;
    int total_id=0;
};
class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin_map[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = checkin_map[id].station;
        int start = checkin_map[id].start_time;
        route_map[startStation+"_"+stationName].total_time += t - start;
        route_map[startStation+"_"+stationName].total_id += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double) route_map[startStation+"_"+endStation].total_time/route_map[startStation+"_"+endStation].total_id;
    }
    unordered_map <int, node1> checkin_map;
    unordered_map <string, node2> route_map;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */