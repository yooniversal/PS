class Solution {
    public int[][] reconstructQueue(int[][] people) {
        List<S> arr = new ArrayList<>();
        for (int[] p : people) {
            arr.add(new S(p[0], p[1]));
        }
        
        arr.sort((a, b) -> {
            if (a.k != b.k) return Integer.compare(a.k, b.k);
            return Integer.compare(a.h, b.h);
        });

        List<S> tmp = new ArrayList<>();
        for (S s : arr) {
            if (tmp.isEmpty()) {
                tmp.add(s);
                continue;
            }

            int target = 0;
            int cnt = 0;
            while (target < tmp.size()) {
                S current = tmp.get(target);
                if (current.h >= s.h) cnt++;
                if (s.k == cnt) {
                    target++;

                    if (target >= tmp.size()) break;

                    current = tmp.get(target);
                    while (target < tmp.size() && current.h < s.h) {
                        target++;
                        if (target < tmp.size()) current = tmp.get(target);
                    }
                    break;
                }
                
                target++;
            }

            if (target < 0 || target >= tmp.size()) {
                tmp.add(s);
            } else {
                tmp.add(target, s);
            }
        }

        int[][] ret = new int[tmp.size()][2];
        for (int i=0; i<tmp.size(); i++) {
            ret[i][0] = tmp.get(i).h;
            ret[i][1] = tmp.get(i).k;
        }

        return ret;
    }

    class S {
        int h, k;

        public S(int h, int k) {
            this.h = h;
            this.k = k;
        }
    }
}
