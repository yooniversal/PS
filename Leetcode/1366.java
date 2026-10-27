class Solution {
    public String rankTeams(String[] votes) {
        int[][] cnt = new int[26][26];

        // 팀별 순위 득표수 집계
        for (String vote : votes) {
            for (int i = 0; i < vote.length(); i++) {
                int team = vote.charAt(i) - 'A';
                cnt[team][i]++;
            }
        }

        // 팀 목록 초기화
        List<Character> teams = new ArrayList<>();
        for (char c : votes[0].toCharArray()) {
            teams.add(c);
        }

        // 정렬
        teams.sort((a, b) -> {
            // 득표수 비교
            for (int i = 0; i < 26; i++) {
                int diff = Integer.compare(cnt[b - 'A'][i], cnt[a - 'A'][i]);
                if (diff != 0) return diff;
            }

            // 알파벳순 비교
            return Character.compare(a, b);
        });

        StringBuilder sb = new StringBuilder();
        for (char team : teams) {
            sb.append(team);
        }

        return sb.toString();
    }
}
