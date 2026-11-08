class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        List<int[]> exceptAisleSeats = new ArrayList<>();
        for (int[] r : reservedSeats) {
            if (r[1] == 1 || r[1] == 10) continue;
            exceptAisleSeats.add(r);
        }
        exceptAisleSeats.sort((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });

        int ret = 0;

        int currentRow = 0;
        int startSeat = 0;
        int beforeRowCols = 0;
        for (int i=0; i<exceptAisleSeats.size(); i++) {
            int r = exceptAisleSeats.get(i)[0], c = exceptAisleSeats.get(i)[1];
            if (currentRow < r) {
                // 이전 행
                if (r - currentRow > 1) {
                    ret += (r - currentRow - 1) * 2;
                }
                if (beforeRowCols > 0 && startSeat < 6) {
                    ret++;
                }

                // 현재 행
                if (c >= 6) {
                    ret++;
                }

                currentRow = r;
                startSeat = c;

                beforeRowCols = 1;
            } else {
                int diff = c - startSeat - 1;
                if (diff >= 4) {
                    if (startSeat == 2 || startSeat == 3) {
                        if (c == 8 || c == 9) {
                            ret++;
                        }
                    } else if (startSeat >= 6) {
                        ret++;
                    }
                }
                
                startSeat = c;
                beforeRowCols++;
            }
        }

        // 마지막 남은 행들 (no seat)
        if (n - currentRow > 0) {
            ret += (n - currentRow) * 2;
        }

        // seat가 있던 마지막 행 계산
        if (startSeat < 6) {
            ret++;
        }

        return ret;
    }
}
