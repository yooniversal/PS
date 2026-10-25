class MyCalendar {
    List<int[]> bookings = new ArrayList<>();

    public MyCalendar() {
    }

    public boolean book(int start, int end) {
        for (int[] booking : bookings) {
            int prevStart = booking[0];
            int prevEnd = booking[1];

            if (start < prevEnd && end > prevStart) {
                return false;
            }
        }

        bookings.add(new int[]{start, end});
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(startTime,endTime);
 */
