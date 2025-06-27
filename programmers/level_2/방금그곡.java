import java.util.*;

class Solution {
    public String solution(String m, String[] musicinfos) {
        String convertedMelody = convertWithoutSharpMelody(m);
        List<MusicInfo> matchedMusicInfos = new ArrayList<>();
        int seq = 0;
        for (String mi : musicinfos) {
            MusicInfo convertedMusicInfo = new MusicInfo(mi, seq++);
            if (!convertedMusicInfo.isMatch(convertedMelody)) continue;
            matchedMusicInfos.add(convertedMusicInfo);
        }
        
        if (matchedMusicInfos.isEmpty()) return "(None)";
        Collections.sort(matchedMusicInfos);
        
        return matchedMusicInfos.get(0).title;
    }
    
    public String convertWithoutSharpMelody(String melody) {
        StringBuilder sb = new StringBuilder();
        
        for (int i=0; i<melody.length(); ) {
            boolean hasSharp = i < melody.length()-1 && melody.charAt(i+1) == '#';
            if (hasSharp) {
                sb.append(convertSharpAlphabet(melody.charAt(i)));
                i += 2;
            } else {
                sb.append(melody.charAt(i));
                i++;
            }
        }
        
        return sb.toString();
    }
    
    public char convertSharpAlphabet(char c) {
        if (c == 'C') return 'P';
        if (c == 'D') return 'O';
        if (c == 'F') return 'I';
        if (c == 'G') return 'U';
        if (c == 'A') return 'Y';
        if (c == 'E') return 'T';
        if (c == 'B') return 'M';
        throw new RuntimeException("Invalid sharp alphabet:" + c);
    }
    
    class MusicInfo implements Comparable<MusicInfo> {
        int seq;
        int startTime;
        int endTime;
        String title;
        String melody;
        
        MusicInfo(String str, int seq) {
            String[] inputs = str.split(",");
            this.seq = seq;
            this.startTime = toMinutes(inputs[0]);
            this.endTime = toMinutes(inputs[1]);
            this.title = inputs[2];
            this.melody = getRepeatedMelody(
                getFullTime(),
                convertWithoutSharpMelody(inputs[3])
            );
        }
        
        public boolean isMatch(String melody) {
            System.out.println("this.melody:" + this.melody + " param:" + melody);
            return this.melody.contains(melody);
        }
        
        public int getFullTime() {
            return endTime - startTime;
        }
        
        @Override
        public int compareTo(MusicInfo next) {
            if (getFullTime() != next.getFullTime()) 
                return next.getFullTime() - getFullTime();
            return seq - next.seq;
        }
        
        @Override
        public String toString() {
            return "startTime:" + startTime + " endTime:" + endTime + " title" + title + " melody:" + melody;
        }
        
        private int toMinutes(String time) {
            int hour = Integer.parseInt(time.substring(0, 2));
            int minute = Integer.parseInt(time.substring(3, 5));
            return hour * 60 + minute;
        }
        
        private String getRepeatedMelody(int minutes, String melody) {
            if (melody.length() >= minutes) return melody.substring(0, minutes);
            
            StringBuilder sb = new StringBuilder();
            for (int i=0; i<minutes / melody.length(); i++) {
                sb.append(melody);
            }
            
            for (int i=0; i<minutes % melody.length(); i++) {
                sb.append(melody.charAt(i));
            }
            
            return sb.toString();
        }
    }
}