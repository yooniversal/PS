class UndergroundSystem {

    private Map<String, AllTime> timeMap;
    private Map<Integer, Station> startTimeMap;

    public UndergroundSystem() {
        timeMap = new HashMap<>();
        startTimeMap = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        startTimeMap.put(id, new Station(stationName, t));
    }
    
    public void checkOut(int id, String stationName, int t) {
        Station startStation = startTimeMap.get(id);
        int diffTime = t - startStation.t;

        String key = startStation.name + ":" + stationName;

        if (timeMap.containsKey(key)) {
            AllTime allTime = timeMap.get(key);
            allTime.addTime(diffTime);
        } else {
            timeMap.put(key, new AllTime(diffTime));
        }
    }
    
    public double getAverageTime(String startStation, String endStation) {
        String key = startStation + ":" + endStation;
        AllTime allTime = timeMap.get(key);

        return allTime.getAvg();
    }

    class Station {
        String name;
        int t;

        public Station(String name, int t) {
            this.name = name;
            this.t = t;
        }
    }

    class AllTime {
        long sum;
        long cnt;

        public AllTime(int sum) {
            this.sum = (long) sum;
            this.cnt = 1;
        }

        public void addTime(int time) {
            this.sum += (long) time;
            this.cnt++;
        }

        public double getAvg() {
            return (double) sum / cnt;
        }
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */
