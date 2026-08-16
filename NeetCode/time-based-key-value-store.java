class TimeMap {

    Map<String, TreeMap<Integer, String>> map;

    public TimeMap() {
        map = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        TreeMap<Integer, String> valueMap = map.getOrDefault(key, new TreeMap<>());
        valueMap.put(timestamp, value);
        map.put(key, valueMap);
    }
    
    public String get(String key, int timestamp) {
        TreeMap<Integer, String> valueMap = map.getOrDefault(key, new TreeMap<>());
        Integer keyByTimestamp = valueMap.floorKey(timestamp);
        if (keyByTimestamp == null) return "";

        String value = valueMap.get(keyByTimestamp);
        return value == null ? "" : value;
    }
}
