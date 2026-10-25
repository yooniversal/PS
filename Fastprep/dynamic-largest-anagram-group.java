public String[][] largestAnagramGroups(String[][] operations) {
    List<String[]> ret = new ArrayList<>();
    
    int maxGroupSize = 0;
    Map<String, TreeMap<String, Integer>> wordMap = new HashMap<>(); // word (sorted string), <origin word, count>
    Map<String, Integer> groupSizeMap = new HashMap<>(); // word (sorted string), group size
    Map<Integer, TreeSet<String>> groupMap = new HashMap<>(); // group size, word (sorted string)

    for (String[] op : operations) {
        if (op.length == 2) {
            String oper = op[0];
            String word = op[1];
            String key = getKey(word);

            if (oper.equals("add")) {
                int groupSize = groupSizeMap.getOrDefault(key, 0);

                // 기존 그룹에서 제거
                if (groupSize > 0) {
                    TreeSet<String> beforeTreeSet = groupMap.get(groupSize);
                    beforeTreeSet.remove(key);

                    if (beforeTreeSet.isEmpty()) {
                        groupMap.remove(groupSize);
                    }
                }

                maxGroupSize = Math.max(maxGroupSize, groupSize + 1);

                // 새로운 그룹에 추가
                TreeSet<String> nextTreeSet = groupMap.getOrDefault(groupSize + 1, new TreeSet<>());
                nextTreeSet.add(key);
                groupMap.put(groupSize + 1, nextTreeSet);

                groupSizeMap.put(key, groupSize + 1);

                // 원본 단어 추가
                TreeMap<String, Integer> wordCntMap = wordMap.getOrDefault(key, new TreeMap<>());
                int prevCnt = wordCntMap.getOrDefault(word, 0);
                wordCntMap.put(word, prevCnt + 1);
                wordMap.put(key, wordCntMap);
            } else if (oper.equals("remove")) {
                TreeMap<String, Integer> wordCntMap = wordMap.get(key);

                // 원본 단어가 존재하지 않으면 무시
                if (wordCntMap == null || !wordCntMap.containsKey(word)) {
                    continue;
                }

                int groupSize = groupSizeMap.get(key);

                // 기존 그룹에서 제거
                TreeSet<String> beforeTreeSet = groupMap.get(groupSize);
                beforeTreeSet.remove(key);

                if (beforeTreeSet.isEmpty()) {
                    groupMap.remove(groupSize);
                }

                // 원본 단어 제거
                int prevCnt = wordCntMap.get(word);

                if (prevCnt == 1) {
                    wordCntMap.remove(word);
                } else {
                    wordCntMap.put(word, prevCnt - 1);
                }

                // 새로운 그룹으로 이동
                if (groupSize == 1) {
                    groupSizeMap.remove(key);
                    wordMap.remove(key);
                } else {
                    groupSizeMap.put(key, groupSize - 1);

                    TreeSet<String> nextTreeSet = groupMap.getOrDefault(groupSize - 1, new TreeSet<>());
                    nextTreeSet.add(key);
                    groupMap.put(groupSize - 1, nextTreeSet);
                }

                // 최대 그룹 크기 갱신
                if (groupSize == maxGroupSize && !groupMap.containsKey(groupSize)) {
                    maxGroupSize = groupSize - 1;
                }
            }
        } else {
            // largestGroup
            boolean empty = maxGroupSize == 0 || groupMap.getOrDefault(maxGroupSize, new TreeSet<>()).isEmpty();
            if (empty) {
                ret.add(new String[]{});
                continue;
            }

            TreeSet<String> wordSet = groupMap.get(maxGroupSize);
            String key = wordSet.first();

            TreeMap<String, Integer> originWordMap = wordMap.get(key);
            List<String> tmp = new ArrayList<>();
            for (Map.Entry<String, Integer> entry : originWordMap.entrySet()) {
                String originWord = entry.getKey();
                int cnt = entry.getValue();

                for (int i=0; i<cnt; i++) {
                    tmp.add(originWord);                    
                }
            }

            String[] stringTmp = new String[tmp.size()];
            for (int i=0; i<tmp.size(); i++) stringTmp[i] = tmp.get(i);
            ret.add(stringTmp);            
        }
    }

    String[][] result = new String[ret.size()][];
    
    for (int i=0; i<ret.size(); i++) {
        result[i] = ret.get(i);
    }
    
    return result;
}

private String getKey(String origin) {
    char[] chars = origin.toCharArray();
    Arrays.sort(chars);
    return new String(chars);
}